// -------------------------------------------------------------------------------- //
//	Copyright (C) 2008-2010 J.Rios
//	anonbeat@gmail.com
//
//    This Program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2, or (at your option)
//    any later version.
//
//    This Program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program; see the file LICENSE.  If not, write to
//    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
//    http://www.gnu.org/copyleft/gpl.html
//
// -------------------------------------------------------------------------------- //
#include "DbRadios.h"

#include "Config.h"

#include <wx/arrimpl.cpp>


WX_DEFINE_OBJARRAY(guRadioStations);

// -------------------------------------------------------------------------------- //
guDbRadios::guDbRadios( guDb * db )
{
    m_Db = db;

    guConfig * Config = ( guConfig * ) guConfig::Get();
    if( Config )
    {
        m_StationsOrder = Config->ReadNum( wxT( "StationsOrder" ), 0, wxT( "General" ) );
        m_StationsOrderDesc = Config->ReadBool( wxT( "StationsOrderDesc" ), false, wxT( "General" ) );
    }
    m_RadioSource = guRADIO_SOURCE_GENRE;

    m_RaTeFilters.Empty();
    m_RaGeFilters.Empty();
    m_RaLaFilters.Empty();

}

// -------------------------------------------------------------------------------- //
guDbRadios::~guDbRadios()
{
    guConfig * Config = ( guConfig * ) guConfig::Get();
    if( Config )
    {
        Config->WriteNum( wxT( "StationsOrder" ), m_StationsOrder, wxT( "General" ) );
        Config->WriteBool( wxT( "StationsOrderDesc" ), m_StationsOrderDesc, wxT( "General" ) );
    }
}

// -------------------------------------------------------------------------------- //
int guDbRadios::GetRadioFiltersCount( void ) const
{
    return m_RaTeFilters.Count() | m_RaGeFilters.Count() | m_RaLaFilters.Count();
}

// -------------------------------------------------------------------------------- //
wxString inline RadioTextFilterToSQL( const wxArrayString &TeFilters )
{
  long count;
  long index;
  wxString RetVal = wxEmptyString;
  if( ( count = TeFilters.Count() ) )
  {
    for( index = 0; index < count; index++ )
    {
        RetVal += wxT( "( radiogenre_name LIKE '%" ) + escape_query_str( TeFilters[ index ] ) + wxT( "%' OR " );
        RetVal += wxT( " radiostation_name LIKE '%" ) + escape_query_str( TeFilters[ index ] ) + wxT( "%' ) AND " );
    }
    RetVal = RetVal.RemoveLast( 4 );
  }
  return RetVal;
}

// -------------------------------------------------------------------------------- //
wxString guDbRadios::RadioFiltersSQL( void )
{
  wxString query;
  wxString RetVal = wxEmptyString;

  if( m_RaTeFilters.Count() )
  {
    RetVal += RadioTextFilterToSQL( m_RaTeFilters );
  }

  return RetVal;
}

// -------------------------------------------------------------------------------- //
void guDbRadios::GetRadioGenresList( const int source, const wxArrayInt &ids, guListItems * listitems, wxArrayInt * radioflags )
{
  wxString query;
  wxSQLite3ResultSet dbRes;

  if( ids.Count() )
  {
    query = wxT( "SELECT radiogenre_id, radiogenre_name, radiogenre_flags FROM radiogenres WHERE " );
    query += wxString::Format( wxT( "radiogenre_source = %i AND " ), source );
    query += ArrayToFilter( ids, wxT( "radiogenre_id" ) );
    query += wxT( " ORDER BY radiogenre_name COLLATE NOCASE;" );

    //guLogMessage( query );
    dbRes = m_Db->ExecuteQuery( query );

    while( dbRes.NextRow() )
    {
      listitems->Add( new guListItem( dbRes.GetInt( 0 ), dbRes.GetString( 1 ) ) );
      if( radioflags )
        radioflags->Add( dbRes.GetInt( 2 ) );
    }
    dbRes.Finalize();
  }
}

// -------------------------------------------------------------------------------- //
void guDbRadios::GetRadioGenres( const int source, guListItems * radiogenres, bool AllowFilter, wxArrayInt * radioflags )
{
  wxString query;
  wxSQLite3ResultSet dbRes;

  //if( !AllowFilter || !GetRadioFiltersCount() )
  if( !AllowFilter || ( !m_RaTeFilters.Count() && !m_RaLaFilters.Count() ) )
  {
    query = wxT( "SELECT radiogenre_id, radiogenre_name, radiogenre_flags FROM radiogenres " );
    query += wxString::Format( wxT( "WHERE radiogenre_source = %i " ), source );
    query += wxT( "ORDER BY radiogenre_name COLLATE NOCASE;" );
  }
  else
  {
    query = wxT( "SELECT DISTINCT radiogenre_id, radiogenre_name, radiogenre_flags FROM radiogenres, radiostations " );
    query += wxString::Format( wxT( "WHERE radiogenre_source = %i " ), source );
    query += wxT( "AND radiogenre_id = radiostation_genreid " );
    if( m_RaTeFilters.Count() )
    {
        query += wxT( " AND " );
        query += RadioFiltersSQL();
    }
    if( m_RaLaFilters.Count() )
    {
        query += wxT( " AND radiostation_id IN ( SELECT DISTINCT radiosetlabel_stationid FROM radiosetlabels WHERE " );
        query += ArrayToFilter( m_RaLaFilters, wxT( "radiosetlabel_labelid" ) );
        query += wxT( " )" );
    }
    query += wxT( " ORDER BY radiogenre_name COLLATE NOCASE;" );
  }

  //guLogMessage( query );
  dbRes = m_Db->ExecuteQuery( query );

  while( dbRes.NextRow() )
  {
    radiogenres->Add( new guListItem( dbRes.GetInt( 0 ), dbRes.GetString( 1 ) ) );
    if( radioflags )
        radioflags->Add( dbRes.GetInt( 2 ) );
  }
  dbRes.Finalize();
}

// -------------------------------------------------------------------------------- //
int guDbRadios::AddRadioGenre( const wxString &GenreName, const int source, const int flags )
{
    wxString query;

    query = wxT( "INSERT INTO radiogenres( radiogenre_id, radiogenre_name, radiogenre_source, radiogenre_flags ) " );
    query += wxString::Format( wxT( "VALUES( NULL, '%s', %i, %i );" ),
            escape_query_str( GenreName ).c_str(),
            source, flags );

    if( m_Db->ExecuteUpdate( query ) == 1 )
    {
      return m_Db->GetLastRowId();
    }
    return 0;
}

// -------------------------------------------------------------------------------- //
int guDbRadios::SetRadioGenre( const int genreid, const wxString &name, const int source, const int flags )
{
    wxString query;

    query = wxString::Format( wxT( "UPDATE radiogenres SET radiogenre_name = '%s', radiogenre_source = %i, "
                                   "radiogenre_flags = %i WHERE radiogenre_id = %u;" ),
                escape_query_str( name ).c_str(), source, flags, genreid );

    return m_Db->ExecuteUpdate( query );
}

// -------------------------------------------------------------------------------- //
int guDbRadios::DelRadioGenre( const int GenreId )
{
  wxString query;

  query = query.Format( wxT( "DELETE FROM radiogenres WHERE radiogenre_id = %u;" ), GenreId );
  if( m_Db->ExecuteUpdate( query ) )
  {
    query = query.Format( wxT( "DELETE FROM radiostations WHERE radiostation_genreid = %u;" ), GenreId );
    if( m_Db->ExecuteUpdate( query ) )
      return 1;
  }
  return 0;
}

// -------------------------------------------------------------------------------- //
void guDbRadios::SetRaTeFilters( const wxArrayString &NewTeFilters )
{
    m_RaTeFilters = NewTeFilters;
    m_RaLaFilters.Empty();
    m_RaGeFilters.Empty();
}

// -------------------------------------------------------------------------------- //
void guDbRadios::SetRadioLabelsFilters( const wxArrayInt &filters )
{
    if( filters.Index( 0 ) != wxNOT_FOUND )
    {
        m_RaLaFilters.Empty();
    }
    else
    {
        m_RaLaFilters = filters;
    }
    m_RaGeFilters.Empty();
}

// -------------------------------------------------------------------------------- //
void guDbRadios::SetRadioGenresFilters( const wxArrayInt &filters )
{
    if( filters.Index( 0 ) != wxNOT_FOUND )
    {
        m_RaGeFilters.Empty();
    }
    else
    {
        m_RaGeFilters = filters;
    }
    //m_RadioSource = false;
}

// -------------------------------------------------------------------------------- //
void guDbRadios::SetRadioSourceFilter( int source )
{
    m_RadioSource = source;
    m_RaGeFilters.Empty();
}

// -------------------------------------------------------------------------------- //
void guDbRadios::SetRadioGenres( const wxArrayString &Genres )
{
  wxString query;
  wxSQLite3ResultSet dbRes;
  int index;
  int count;
  wxString GenreName;

  query = wxT( "DELETE FROM radiogenres;" );
  m_Db->ExecuteUpdate( query );

  count = Genres.Count();
  for( index = 0; index < count; index++ )
  {
    GenreName = Genres[ index ];
    escape_query_str( &GenreName );
    query = wxString::Format( wxT( "INSERT INTO radiogenres( radiogenre_id, radiogenre_name ) "\
                                       "VALUES( NULL, '%s' );" ), GenreName.c_str() );
    m_Db->ExecuteUpdate( query );
  }
}

// -------------------------------------------------------------------------------- //
void guDbRadios::SetRadioStationsOrder( int order )
{
    if( m_StationsOrder != order )
    {
        m_StationsOrder = order;
        m_StationsOrderDesc = ( order != 0 );
    }
    else
        m_StationsOrderDesc = !m_StationsOrderDesc;
}

// -------------------------------------------------------------------------------- //
int guDbRadios::GetUserRadioStations( guRadioStations * stations )
{
  wxString query;
  wxSQLite3ResultSet dbRes;
  guRadioStation * Station;

  query = wxT( "SELECT DISTINCT radiostation_name, radiostation_link "
               "FROM radiostations WHERE radiostation_source = 1 " );

  dbRes = m_Db->ExecuteQuery( query );

  while( dbRes.NextRow() )
  {
    Station = new guRadioStation();
    Station->m_Name       = dbRes.GetString( 0 );
    Station->m_Link       = dbRes.GetString( 1 );
    stations->Add( Station );
  }
  dbRes.Finalize();
  return stations->Count();
}

// -------------------------------------------------------------------------------- //
int guDbRadios::GetRadioStations( guRadioStations * Stations )
{
  wxString query;
  wxString querydb;
  wxString subquery;
  wxSQLite3ResultSet dbRes;
  guRadioStation * Station;

  if( !GetRadioFiltersCount() )
  {
    query = wxT( "SELECT DISTINCT radiostation_name, radiostation_id, radiostation_scid, radiostation_source, radiostation_genreid, radiostation_link, radiostation_type, radiostation_br, radiostation_lc, radiostation_ct "\
                 "FROM radiostations WHERE " );
    query += wxString::Format( wxT( "radiostation_source = %u " ), m_RadioSource );
    query += wxT( "GROUP BY radiostation_name, radiostation_br " );
  }
  else
  {
    if( m_RadioSource == guRADIO_SOURCE_USER )
    {
        //SELECT * FROM radiostations, radiosetlabels WHERE radiosetlabel_stationid = radiostation_id AND radiosetlabel_labelid IN ( 1 )
        query = wxT( "SELECT DISTINCT radiostation_name, radiostation_id, radiostation_scid, radiostation_source, radiostation_genreid, radiostation_link, radiostation_type, radiostation_br, radiostation_lc, radiostation_ct " );
        querydb = wxT( "FROM radiostations " );

        //else
        wxString subquery = wxEmptyString;

        if( m_RaLaFilters.Count() )
        {
            querydb += wxT( ", radiosetlabels " );
            subquery += wxT( "WHERE radiostation_id = radiosetlabel_stationid AND radiostation_source = 1" );
            subquery += wxT( " AND " ) + ArrayToFilter( m_RaLaFilters, wxT( "radiosetlabel_labelid" ) );
        }
        else
        {
            subquery += wxT( "WHERE radiostation_source = 1 " );
        }

        if( m_RaTeFilters.Count() )
        {
            querydb += wxT( ", radiogenres " );
            subquery += wxT( "AND radiostation_genreid = radiogenre_id " );
            subquery += wxT( "AND " ) + RadioFiltersSQL();
        }

        subquery += wxT( "GROUP BY radiostation_name, radiostation_br " );
        query = query + querydb + subquery;
    }
    else
    {
        //SELECT * FROM radiostations, radiosetlabels WHERE radiosetlabel_stationid = radiostation_id AND radiosetlabel_labelid IN ( 1 )
        query = wxT( "SELECT DISTINCT radiostation_name, radiostation_id, radiostation_scid, radiostation_source, radiostation_genreid, radiostation_link, radiostation_type, radiostation_br, radiostation_lc, radiostation_ct "\
                     "FROM radiostations, radiogenres" );

        //else
        wxString subquery = wxEmptyString;
        if( m_RaLaFilters.Count() )
        {
            query += wxT( ", radiosetlabels WHERE radiostation_genreid = radiogenre_id AND radiostation_id = radiosetlabel_stationid AND " );
            subquery += ArrayToFilter( m_RaLaFilters, wxT( "radiosetlabel_labelid" ) );
        }
        else
        {
            query += wxT( " WHERE radiostation_genreid = radiogenre_id " );
        }

        subquery += wxString::Format( wxT( " AND radiostation_source = %i " ), m_RadioSource );

        if( m_RaGeFilters.Count() )
        {
            subquery += wxT( " AND " ) + ArrayToFilter( m_RaGeFilters, wxT( "radiostation_genreid" ) );
        }

        if( m_RaTeFilters.Count() )
        {
            subquery += wxT( " AND " ) + RadioFiltersSQL();
        }

        if( !subquery.IsEmpty() )
        {
            query = query + subquery;
        }

        query += wxT( "GROUP BY radiostation_name, radiostation_br " );
    }
  }

  query += wxT( " ORDER BY " );

  if( m_StationsOrder == guRADIOSTATIONS_ORDER_NAME )
    query += wxT( "radiostation_name COLLATE NOCASE" );
  else if( m_StationsOrder == guRADIOSTATIONS_ORDER_BITRATE )
    query += wxT( "radiostation_br" );
  else if( m_StationsOrder == guRADIOSTATIONS_ORDER_LISTENERS )
    query += wxT( "radiostation_lc" );
  else if( m_StationsOrder == guRADIOSTATIONS_ORDER_TYPE )
    query += wxT( "radiostation_type" );
  else //if( m_StationsOrder == guRADIOSTATIONS_COLUMN_NOWPLAYING )
    query += wxT( "radiostation_ct" );

  if( m_StationsOrderDesc )
    query += wxT( " DESC;" );

  //guLogMessage( wxT( "GetRadioStations\n%s" ), query.c_str() );
  dbRes = m_Db->ExecuteQuery( query );

  while( dbRes.NextRow() )
  {
    Station = new guRadioStation();
    Station->m_Name       = dbRes.GetString( 0 );
    Station->m_Id         = dbRes.GetInt( 1 );
    Station->m_SCId       = dbRes.GetInt( 2 );
    Station->m_Source     = dbRes.GetInt( 3 );
    Station->m_GenreId    = dbRes.GetInt( 4 );
    Station->m_Link       = dbRes.GetString( 5 );
    Station->m_Type       = dbRes.GetString( 6 );
    Station->m_BitRate    = dbRes.GetInt( 7 );
    Station->m_Listeners  = dbRes.GetInt( 8 );
    Station->m_NowPlaying = dbRes.GetString( 9 );

    Stations->Add( Station );
  }
  dbRes.Finalize();
  return Stations->Count();
}

//// -------------------------------------------------------------------------------- //
//void guDbRadios::GetRadioCounter( wxLongLong * count )
//{
//  wxString query;
//  wxSQLite3ResultSet dbRes;
//
//  if( !GetRadioFiltersCount() )
//  {
//    query = wxT( "SELECT COUNT() FROM radiostations WHERE " );
//    query += wxString::Format( wxT( "radiostation_source = %u " ), m_RadioSource );
//  }
//  else
//  {
//    //SELECT * FROM radiostations, radiosetlabels WHERE radiosetlabel_stationid = radiostation_id AND radiosetlabel_labelid IN ( 1 )
//    query = wxT( "SELECT COUNT() FROM radiostations, radiogenres" );
//
//    //else
//    wxString subquery = wxEmptyString;
//    if( m_RaLaFilters.Count() )
//    {
//        query += wxT( ", radiosetlabels WHERE radiostation_id = radiosetlabel_stationid AND " );
//        subquery += ArrayToFilter( m_RaLaFilters, wxT( "radiosetlabel_labelid" ) );
//    }
//    else
//    {
//        query += wxT( " WHERE " );
//    }
//
//    if( !subquery.IsEmpty() )
//        subquery += wxT( " AND " );
//    subquery += wxString::Format( wxT( " radiostation_source = %u " ), m_RadioSource );
//
//    if( m_RaGeFilters.Count() )
//    {
//        //if( !subquery.IsEmpty() )
//        //{
//        //    subquery += wxT( " AND " );
//        //}
//        subquery += wxT( " AND radiostation_genreid = radiogenre_id AND " );
//        subquery += ArrayToFilter( m_RaGeFilters, wxT( "radiostation_genreid" ) );
//    }
//
//    if( m_RaTeFilters.Count() )
//    {
//        //if( !subquery.IsEmpty() )
//        //{
//            subquery += wxT( " AND " );
//        //}
//        subquery += RadioFiltersSQL();
//    }
//
//    if( !subquery.IsEmpty() )
//    {
//        query = query + subquery;
//    }
//  }
//
//  //guLogMessage( wxT( "GetRadioStations\n%s" ), query.c_str() );
//  dbRes = m_Db->ExecuteQuery( query );
//
//  if( dbRes.NextRow() )
//  {
//      * count = dbRes.GetInt64( 0 );
//  }
//  dbRes.Finalize();
//}

// -------------------------------------------------------------------------------- //
int guDbRadios::DelRadioStations( int source, const wxArrayInt &radioids )
{
  wxString query;
  if( radioids.Count() )
  {
    query = wxString::Format( wxT( "DELETE FROM radiostations WHERE radiostation_source = %i AND " ), source );
    query += ArrayToFilter( radioids, wxT( "radiostation_genreid" ) );
    return m_Db->ExecuteUpdate( query );
  }
  return 0;
}

// -------------------------------------------------------------------------------- //
int guDbRadios::DelRadioStation( const int radioid )
{
  wxString query;
  query = wxString::Format( wxT( "DELETE FROM radiostations WHERE radiostation_id = %u" ), radioid );
  return m_Db->ExecuteUpdate( query );
}

// -------------------------------------------------------------------------------- //
void guDbRadios::SetRadioStation( const guRadioStation * radiostation )
{
  wxString query;

  if( radiostation->m_Id != wxNOT_FOUND )
  {
    query = wxString::Format( wxT( "UPDATE radiostations SET "
                                   "radiostation_scid = %u, radiostation_source = %u, radiostation_genreid = %u, "
                                   "radiostation_name = '%s', radiostation_link = '%s', radiostation_type = '%s', "
                                   "radiostation_br = %u, radiostation_lc = %u, radiostation_ct = '%s' WHERE radiostation_id = %u;" ),
                                   radiostation->m_SCId,
                                   radiostation->m_Source,
                                   radiostation->m_GenreId,
                                   escape_query_str( radiostation->m_Name ).c_str(),
                                   escape_query_str( radiostation->m_Link ).c_str(),
                                   escape_query_str( radiostation->m_Type ).c_str(),
                                   radiostation->m_BitRate,
                                   radiostation->m_Listeners,
                                   escape_query_str( radiostation->m_NowPlaying ).c_str(),
                                   radiostation->m_Id );
  }
  else
  {
    query = wxString::Format( wxT( "INSERT INTO radiostations( radiostation_id, radiostation_scid, radiostation_source, radiostation_genreid, "\
                                   "radiostation_name, radiostation_link, radiostation_type, radiostation_br, radiostation_lc, radiostation_ct ) "\
                                   "VALUES( NULL, %u, %u, %u, '%s', '%s', '%s', %u, %u, '%s' );" ),
                                   radiostation->m_SCId,
                                   radiostation->m_Source,
                                   radiostation->m_GenreId,
                                   escape_query_str( radiostation->m_Name ).c_str(),
                                   escape_query_str( radiostation->m_Link ).c_str(),
                                   escape_query_str( radiostation->m_Type ).c_str(),
                                   radiostation->m_BitRate,
                                   radiostation->m_Listeners,
                                   escape_query_str( radiostation->m_NowPlaying ).c_str() );
  }
  //guLogMessage( wxT( "SetRadioStation:\n%s" ), query.c_str() );
  m_Db->ExecuteUpdate( query );
}

// -------------------------------------------------------------------------------- //
void guDbRadios::SetRadioStations( const guRadioStations * RadioStations )
{
  int index;
  int count;

  if( ( count = RadioStations->Count() ) )
  {
      for( index = 0; index < count; index++ )
      {
          SetRadioStation( &RadioStations->Item( index ) );
      }
  }
}

// -------------------------------------------------------------------------------- //
bool guDbRadios::GetRadioStation( const int id, guRadioStation * radiostation )
{
  wxString query;
  wxSQLite3ResultSet dbRes;

  query = wxT( "SELECT radiostation_id, radiostation_scid, radiostation_source, radiostation_genreid, radiostation_name, radiostation_link, radiostation_type, radiostation_br, radiostation_lc "\
                 "FROM radiostations WHERE " );
  query += wxString::Format( wxT( "radiostation_id = %u LIMIT 1;" ), id );

  dbRes = m_Db->ExecuteQuery( query );
  if( dbRes.NextRow() )
  {
    radiostation->m_Id         = dbRes.GetInt( 0 );
    radiostation->m_SCId       = dbRes.GetInt( 1 );
    radiostation->m_Source     = dbRes.GetInt( 2 );
    radiostation->m_GenreId    = dbRes.GetInt( 3 );
    radiostation->m_Name       = dbRes.GetString( 4 );
    radiostation->m_Link       = dbRes.GetString( 5 );
    radiostation->m_Type       = dbRes.GetString( 6 );
    radiostation->m_BitRate    = dbRes.GetInt( 7 );
    radiostation->m_Listeners  = dbRes.GetInt( 8 );
    return true;
  }
  return false;
}

// -------------------------------------------------------------------------------- //
bool guDbRadios::RadioStationExists( const int shoutcastid )
{
  wxString query;
  wxSQLite3ResultSet dbRes;
  bool RetVal;

  query = wxString::Format( wxT( "SELECT radiostation_id WHERE radiostation_scid = %i LIMIT 1;" ), shoutcastid );

  dbRes = m_Db->ExecuteQuery( query );

  RetVal = dbRes.NextRow();

  dbRes.Finalize();
  return RetVal;
}

// -------------------------------------------------------------------------------- //
guArrayListItems guDbRadios::GetStationsLabels( const wxArrayInt &Stations )
{
  wxString query;
  wxSQLite3ResultSet dbRes;
  guArrayListItems RetVal;
  guArrayListItem * CurItem = NULL;
  int Id;
  int index;
  int count = Stations.Count();
  for( index = 0; index < count; index++ )
  {
      Id = Stations[ index ];
      RetVal.Add( new guArrayListItem( Id ) );
  }

  query = wxT( "SELECT radiosetlabel_stationid, radiosetlabel_labelid FROM radiosetlabels " ) \
          wxT( "WHERE radiosetlabel_stationid IN " ) + ArrayIntToStrList( Stations );
  query += wxT( " ORDER BY radiosetlabel_stationid, radiosetlabel_labelid;" );

  //guLogMessage( query );
  dbRes = m_Db->ExecuteQuery( query );

  index = 0;
  CurItem = &RetVal[ index ];
  while( dbRes.NextRow() )
  {
    Id = dbRes.GetInt( 0 );
    if( CurItem->GetId() != Id )
    {
        index = 0;
        while( CurItem->GetId() != Id )
        {
            CurItem = &RetVal[ index ];
            index++;
        }
    }
    CurItem->AddData( dbRes.GetInt( 1 ) );
  }
  dbRes.Finalize();
  return RetVal;
}

// -------------------------------------------------------------------------------- //
void guDbRadios::SetRadioStationsLabels( const wxArrayInt &Stations, const wxArrayInt &Labels )
{
  wxString query;
  int StaIndex;
  int StaCount;
  int LaIndex;
  int LaCount;

  query = wxT( "DELETE FROM radiosetlabels "
               "WHERE radiosetlabel_stationid IN " ) + ArrayIntToStrList( Stations );

  m_Db->ExecuteUpdate( query );

  StaCount = Stations.Count();
  LaCount = Labels.Count();
  for( StaIndex = 0; StaIndex < StaCount; StaIndex++ )
  {
    for( LaIndex = 0; LaIndex < LaCount; LaIndex++ )
    {
      query = wxString::Format( wxT( "INSERT INTO radiosetlabels( radiosetlabel_labelid, radiosetlabel_stationid ) "\
                                   "VALUES( %u, %u );" ), Labels[ LaIndex ], Stations[ StaIndex ] );
      m_Db->ExecuteUpdate( query );
    }
  }
}

// -------------------------------------------------------------------------------- //
int guDbRadios::GetRadioLabelsSongs( const wxArrayInt &Labels, guTrackArray * Songs )
{
  wxString subquery;
  wxString query;
  wxSQLite3ResultSet dbRes;
//  guTrack * Song;

  if( Labels.Count() )
  {
    subquery = ArrayIntToStrList( Labels );


    dbRes.Finalize();
  }
  return Songs->Count();
}

// -------------------------------------------------------------------------------- //
void guDbRadios::GetRadioLabels( guListItems * Labels, const bool FullList )
{
  wxString query;
  wxSQLite3ResultSet dbRes;

  query = wxT( "SELECT radiolabel_id, radiolabel_name FROM radiolabels ORDER BY " );
  query += FullList ? wxT( "radiolabel_id;" ) : wxT( "radiolabel_name COLLATE NOCASE;" );

  //guLogMessage( query );
  dbRes = m_Db->ExecuteQuery( query );

  while( dbRes.NextRow() )
  {
    Labels->Add( new guListItem( dbRes.GetInt( 0 ), dbRes.GetString( 1 ) ) );
  }
  dbRes.Finalize();
//  return RetVal;
}

// -------------------------------------------------------------------------------- //
int guDbRadios::AddRadioLabel( wxString LabelName )
{
    wxString query;
    escape_query_str( &LabelName );

    query = wxT( "INSERT INTO radiolabels( radiolabel_id, radiolabel_name ) VALUES( NULL, '" ) +
            LabelName + wxT( "');" );

    if( m_Db->ExecuteUpdate( query ) == 1 )
    {
      return m_Db->GetLastRowId();
    }
    return 0;
}

// -------------------------------------------------------------------------------- //
int guDbRadios::SetRadioLabelName( const int LabelId, wxString LabelName )
{
    wxString query;
    escape_query_str( &LabelName );

    query = query.Format( wxT( "UPDATE radiolabels SET radiolabel_name = '%s' WHERE radiolabel_id = %u;" ), LabelName.c_str(), LabelId );

    if( m_Db->ExecuteUpdate( query ) == 1 )
    {
      return m_Db->GetLastRowId();
    }
    return 0;
}

// -------------------------------------------------------------------------------- //
int guDbRadios::DelRadioLabel( const int labelid )
{
  wxString query;

  query = query.Format( wxT( "DELETE FROM radiolabels WHERE radiolabel_id = %u;" ), labelid );
  if( m_Db->ExecuteUpdate( query ) )
  {
    query = query.Format( wxT( "DELETE FROM radiosetlabels WHERE radiosetlabel_labelid = %u;" ), labelid );
    if( m_Db->ExecuteUpdate( query ) )
    {
      return 1;
    }
  }
  return 0;
}

// -------------------------------------------------------------------------------- //