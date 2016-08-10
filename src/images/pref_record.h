// -------------------------------------------------------------------------------- //
//    Copyright (C) 2008-2016 J.Rios anonbeat@gmail.com
//
//    This Program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 3, or (at your option)
//    any later version.
//
//    This Program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program; see the file LICENSE.  If not, write to
//    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
//    Boston, MA 02110-1301 USA.
//
//    http://www.gnu.org/copyleft/gpl.html
//
// -------------------------------------------------------------------------------- //
const unsigned char guImage_pref_record[] = {
0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d, 
0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 
0x08, 0x06, 0x00, 0x00, 0x00, 0x73, 0x7a, 0x7a, 0xf4, 0x00, 0x00, 0x00, 
0x04, 0x73, 0x42, 0x49, 0x54, 0x08, 0x08, 0x08, 0x08, 0x7c, 0x08, 0x64, 
0x88, 0x00, 0x00, 0x00, 0x09, 0x70, 0x48, 0x59, 0x73, 0x00, 0x00, 0x08, 
0xdc, 0x00, 0x00, 0x08, 0xdc, 0x01, 0x9f, 0xe8, 0x5f, 0x3c, 0x00, 0x00, 
0x00, 0x19, 0x74, 0x45, 0x58, 0x74, 0x53, 0x6f, 0x66, 0x74, 0x77, 0x61, 
0x72, 0x65, 0x00, 0x77, 0x77, 0x77, 0x2e, 0x69, 0x6e, 0x6b, 0x73, 0x63, 
0x61, 0x70, 0x65, 0x2e, 0x6f, 0x72, 0x67, 0x9b, 0xee, 0x3c, 0x1a, 0x00, 
0x00, 0x05, 0xfd, 0x49, 0x44, 0x41, 0x54, 0x58, 0x85, 0xcd, 0x97, 0x6b, 
0x4c, 0x93, 0x67, 0x14, 0xc7, 0x7f, 0x7d, 0x6b, 0x69, 0x2d, 0x83, 0x29, 
0x08, 0xd2, 0x8a, 0x41, 0x14, 0xed, 0x10, 0x9c, 0x17, 0xb0, 0x0c, 0x63, 
0xc0, 0x61, 0x64, 0x64, 0xe9, 0xac, 0x9b, 0xb8, 0x18, 0xfc, 0x40, 0x8c, 
0x5f, 0x86, 0x31, 0x46, 0x4d, 0x8c, 0x51, 0x08, 0xde, 0x50, 0x23, 0x1a, 
0x17, 0xe3, 0x07, 0x48, 0x34, 0xf1, 0x92, 0x18, 0x74, 0x6a, 0x1c, 0xc4, 
0xa1, 0xc2, 0x1c, 0xa3, 0x8e, 0x29, 0x65, 0x22, 0xce, 0x0b, 0x3a, 0x10, 
0xbc, 0x60, 0xb9, 0x78, 0x2d, 0xda, 0x16, 0x0a, 0xf2, 0xee, 0x43, 0x5b, 
0x06, 0xf6, 0x62, 0x33, 0xb3, 0x64, 0x27, 0x79, 0x93, 0xf7, 0x72, 0x9e, 
0xf3, 0xff, 0xbf, 0xe7, 0x39, 0xcf, 0xf3, 0xfc, 0x8f, 0x44, 0x14, 0x45, 
0xfc, 0x34, 0x39, 0x90, 0x06, 0xe8, 0x81, 0x58, 0x40, 0xe5, 0xbc, 0x00, 
0xda, 0x9d, 0x57, 0x23, 0x50, 0x0a, 0xfc, 0x02, 0xf4, 0xfa, 0x15, 0x55, 
0x14, 0xc5, 0xf7, 0x5d, 0x2a, 0x51, 0x14, 0x8b, 0x44, 0x51, 0xec, 0x16, 
0xfd, 0xb7, 0x6e, 0xe7, 0x18, 0xd5, 0xfb, 0xe2, 0x4b, 0x7c, 0x64, 0x40, 
0x01, 0xe4, 0x01, 0x6b, 0x01, 0x25, 0x40, 0x77, 0x4b, 0x0b, 0xad, 0xa5, 
0xa5, 0xb4, 0x1b, 0x0c, 0x58, 0x4c, 0x26, 0xac, 0x26, 0x13, 0x00, 0x4a, 
0xb5, 0x9a, 0x40, 0xb5, 0x1a, 0x55, 0x4a, 0x0a, 0xd1, 0x7a, 0x3d, 0xc1, 
0x13, 0x27, 0xba, 0x62, 0x58, 0x81, 0xef, 0x81, 0x02, 0xa0, 0xc7, 0x13, 
0x88, 0x37, 0x02, 0x11, 0xc0, 0x8f, 0x40, 0x12, 0x40, 0x5b, 0x65, 0x25, 
0xb5, 0x79, 0x79, 0x74, 0x19, 0x8d, 0x7e, 0x65, 0x35, 0x5c, 0xab, 0x25, 
0xa9, 0xa0, 0x80, 0xc8, 0x05, 0x0b, 0x5c, 0xaf, 0x6a, 0x81, 0x45, 0x40, 
0x87, 0x3f, 0x04, 0xa6, 0x01, 0xe5, 0x40, 0xa4, 0xc5, 0x64, 0xa2, 0x6a, 
0xf9, 0x72, 0x1e, 0x57, 0x54, 0xf8, 0x05, 0xfc, 0xae, 0x8d, 0x4f, 0x4f, 
0xe7, 0xf3, 0xc3, 0x87, 0x09, 0x54, 0xab, 0x01, 0xda, 0x80, 0x2f, 0x81, 
0x9b, 0xbe, 0x08, 0x44, 0x00, 0x75, 0x40, 0x64, 0x97, 0xd1, 0xc8, 0x85, 
0xaf, 0xbf, 0xc6, 0xe2, 0x4c, 0xf3, 0xbf, 0xb5, 0x40, 0xb5, 0x9a, 0x8c, 
0xb3, 0x67, 0x09, 0xd7, 0x6a, 0x5d, 0x24, 0x66, 0x33, 0x24, 0x13, 0x43, 
0x09, 0x28, 0x80, 0x5f, 0x81, 0xa4, 0x2e, 0xa3, 0x91, 0x1f, 0x53, 0x53, 
0x79, 0xdb, 0xe3, 0x71, 0xda, 0xdc, 0x2c, 0x24, 0x2e, 0x8e, 0xc4, 0xfc, 
0x7c, 0xc6, 0xcc, 0x9a, 0x45, 0xbf, 0xcd, 0xc6, 0xfd, 0x53, 0xa7, 0xb8, 
0xbe, 0x7b, 0x37, 0x03, 0x76, 0x3b, 0x00, 0x52, 0x85, 0x82, 0x45, 0xd5, 
0xd5, 0x2e, 0x12, 0xb5, 0xc0, 0x3c, 0x9c, 0x35, 0x31, 0x94, 0x40, 0x01, 
0x90, 0x6b, 0x31, 0x99, 0x38, 0x33, 0x7b, 0xb6, 0xdf, 0x7f, 0x3e, 0x66, 
0xc6, 0x0c, 0x16, 0x19, 0x0c, 0xc8, 0x82, 0x82, 0x86, 0xbd, 0x6f, 0xbb, 
0x74, 0x89, 0x9f, 0x32, 0x32, 0x18, 0xe8, 0xef, 0x1f, 0xcc, 0xc4, 0xe2, 
0xba, 0x3a, 0xd7, 0x74, 0xec, 0xc0, 0x51, 0xe0, 0x08, 0x4e, 0x7f, 0x15, 
0x8e, 0x6a, 0xa7, 0x6a, 0xf9, 0x72, 0x9f, 0xe0, 0x81, 0xe3, 0xc6, 0x0d, 
0xde, 0x0b, 0x32, 0x19, 0x0b, 0x4e, 0x9e, 0x74, 0x03, 0x07, 0x88, 0x9c, 
0x3f, 0x9f, 0x98, 0xa5, 0x4b, 0x07, 0x9f, 0x5d, 0xf5, 0xe4, 0xb4, 0xb5, 
0x4e, 0xcc, 0x41, 0x02, 0xf9, 0x80, 0xb2, 0xad, 0xb2, 0xd2, 0x67, 0xc1, 
0x4d, 0x5a, 0xb2, 0x84, 0x65, 0xcd, 0xcd, 0x7c, 0xe2, 0x0c, 0x14, 0xa5, 
0xd3, 0x31, 0x6a, 0xca, 0x14, 0xaf, 0xfe, 0x51, 0x3a, 0xdd, 0xb0, 0xe7, 
0xc7, 0x15, 0x15, 0xb4, 0x55, 0x56, 0x82, 0x63, 0x59, 0xe7, 0xbb, 0x08, 
0xc8, 0x81, 0x65, 0x00, 0xb5, 0x79, 0x79, 0x5e, 0x83, 0x49, 0xe5, 0x72, 
0x3e, 0xdb, 0xbd, 0x1b, 0xa9, 0x42, 0xc1, 0xcb, 0xbb, 0x77, 0x01, 0x68, 
0x3d, 0x7b, 0x96, 0x72, 0x9d, 0x0e, 0x73, 0x73, 0xb3, 0xc7, 0x31, 0x01, 
0x1e, 0x32, 0x33, 0x04, 0x63, 0x19, 0x20, 0x17, 0x70, 0x6c, 0xaf, 0x41, 
0xdd, 0x2d, 0x2d, 0x3e, 0xd7, 0xf9, 0xa7, 0x6b, 0xd6, 0x10, 0x1c, 0x1d, 
0x4d, 0x53, 0x49, 0x09, 0x9d, 0x57, 0xae, 0x90, 0x90, 0x9b, 0x8b, 0x26, 
0x3b, 0x9b, 0x87, 0xe5, 0xe5, 0x9c, 0x88, 0x8b, 0xa3, 0x76, 0xd3, 0x26, 
0xfa, 0x2c, 0x96, 0x61, 0x63, 0x9e, 0x54, 0x55, 0xb9, 0xc5, 0xe9, 0x32, 
0x1a, 0xe9, 0x6e, 0x69, 0x01, 0x08, 0x02, 0xd2, 0x04, 0x1c, 0x7b, 0x3b, 
0xad, 0xa5, 0xa5, 0x5e, 0xc1, 0x47, 0x86, 0x87, 0x33, 0x6b, 0xd3, 0x26, 
0xfa, 0x6d, 0x36, 0xae, 0x6e, 0xd8, 0xc0, 0xc7, 0x31, 0x31, 0x24, 0xe6, 
0xe7, 0x93, 0x76, 0xe4, 0x08, 0xdf, 0xd4, 0xd4, 0x10, 0x1a, 0x1f, 0x4f, 
0xfd, 0xae, 0x5d, 0x94, 0x68, 0x34, 0x34, 0x95, 0x94, 0x00, 0x60, 0x37, 
0x9b, 0xb9, 0x77, 0xec, 0x98, 0xc7, 0x78, 0x43, 0xb0, 0xf4, 0x02, 0x8e, 
0x83, 0x85, 0x76, 0x83, 0xc1, 0x2b, 0x01, 0xed, 0xb6, 0x6d, 0x04, 0x04, 
0x07, 0xd3, 0xb0, 0x67, 0x0f, 0x6f, 0x1e, 0x3f, 0x26, 0xb9, 0xb0, 0x10, 
0x21, 0x20, 0x00, 0x80, 0xb1, 0xc9, 0xc9, 0x2c, 0xae, 0xab, 0x23, 0xa5, 
0xa8, 0x88, 0x7e, 0x9b, 0x8d, 0x9f, 0xb3, 0xb2, 0x28, 0x4d, 0x4d, 0xc5, 
0x90, 0x93, 0x83, 0xad, 0xab, 0xcb, 0x63, 0xbc, 0x21, 0x58, 0xb1, 0x12, 
0x51, 0x14, 0xff, 0x02, 0x26, 0x9f, 0x49, 0x4a, 0xf2, 0x38, 0x05, 0x21, 
0xf1, 0xf1, 0x7c, 0xdb, 0xd0, 0x80, 0xb5, 0xa3, 0x83, 0x12, 0x8d, 0x86, 
0xb0, 0x84, 0x04, 0xf4, 0xd5, 0xd5, 0x1e, 0x03, 0xf7, 0x3c, 0x7f, 0x4e, 
0x6d, 0x6e, 0x2e, 0x8d, 0x07, 0x0f, 0x22, 0x0e, 0x0c, 0x78, 0xfd, 0xa1, 
0x70, 0xad, 0x96, 0xc5, 0xb5, 0xb5, 0x00, 0x4d, 0x02, 0xce, 0xe5, 0x60, 
0xf5, 0xb2, 0xf4, 0xa6, 0xad, 0x5a, 0x85, 0x44, 0x2a, 0x75, 0xcc, 0xb1, 
0xd5, 0xca, 0x9c, 0x7d, 0xfb, 0xbc, 0x06, 0x56, 0x84, 0x86, 0x92, 0x5a, 
0x5c, 0xcc, 0xf8, 0xf4, 0x74, 0x84, 0x11, 0x23, 0x48, 0xda, 0xb9, 0x93, 
0x91, 0x61, 0x61, 0x6e, 0x7e, 0x43, 0xb0, 0x54, 0xae, 0x65, 0x88, 0x44, 
0x2a, 0x75, 0x73, 0x14, 0x64, 0x32, 0x26, 0x66, 0x66, 0x62, 0x37, 0x9b, 
0x69, 0x3a, 0x71, 0x82, 0xc9, 0x4b, 0x97, 0x12, 0x96, 0x90, 0xe0, 0x95, 
0x00, 0x80, 0xc9, 0x60, 0xe0, 0xd1, 0x85, 0x0b, 0xc4, 0xe5, 0xe4, 0x30, 
0x6b, 0xe3, 0x46, 0x92, 0xf7, 0xec, 0xf1, 0xe9, 0x2f, 0xe0, 0x10, 0x12, 
0x04, 0x4d, 0x98, 0xe0, 0xf6, 0x31, 0x2c, 0x31, 0x11, 0x45, 0x68, 0x28, 
0x0f, 0xcf, 0x9d, 0x63, 0xc0, 0x6e, 0x47, 0x93, 0x9d, 0xed, 0x33, 0x18, 
0xa2, 0xc8, 0xef, 0x6b, 0xd7, 0x22, 0x1f, 0x3d, 0x9a, 0xd9, 0x5b, 0xb6, 
0xf0, 0xb6, 0xb7, 0x97, 0x3f, 0xb6, 0x6e, 0x75, 0x73, 0x53, 0x3a, 0x76, 
0x43, 0x80, 0x76, 0x9f, 0x04, 0xa4, 0xce, 0x42, 0x73, 0xed, 0x8c, 0xa3, 
0x63, 0x63, 0x7d, 0xe2, 0xdf, 0x3d, 0x7a, 0x94, 0xa7, 0xf5, 0xf5, 0x24, 
0x6e, 0xde, 0x8c, 0x3c, 0x24, 0x84, 0x3f, 0xf7, 0xef, 0xa7, 0xbb, 0xb5, 
0xd5, 0xcd, 0x2f, 0xf0, 0x1d, 0x02, 0x8d, 0x00, 0xa3, 0x34, 0x1a, 0xaf, 
0x81, 0xe5, 0x21, 0x21, 0x00, 0x58, 0x3b, 0x3b, 0xbd, 0xfa, 0xf4, 0x59, 
0x2c, 0x18, 0x73, 0x73, 0x19, 0xa5, 0xd1, 0x10, 0xbf, 0x72, 0x25, 0xb6, 
0xae, 0x2e, 0xea, 0x77, 0xec, 0xf0, 0xe8, 0xab, 0x4a, 0x49, 0x71, 0xdd, 
0x36, 0x0a, 0x38, 0x34, 0x1c, 0x93, 0xb3, 0xb2, 0x90, 0x08, 0xc2, 0x30, 
0xc7, 0xe7, 0x37, 0x6f, 0x32, 0x60, 0xb7, 0xa3, 0x9a, 0x3b, 0x17, 0x89, 
0x20, 0x70, 0xbb, 0xb8, 0xd8, 0x2b, 0x81, 0x6b, 0xdb, 0xb7, 0x63, 0x31, 
0x99, 0x98, 0xb3, 0x77, 0x2f, 0x82, 0x4c, 0x86, 0x31, 0x3f, 0x1f, 0x7b, 
0x77, 0xb7, 0x47, 0xdf, 0x68, 0xbd, 0xde, 0x75, 0x5b, 0x2a, 0xe0, 0x10, 
0x90, 0xaf, 0x83, 0xa2, 0xa2, 0x18, 0x9f, 0x9e, 0x3e, 0xcc, 0xb1, 0xf7, 
0xc5, 0x0b, 0x1e, 0x9e, 0x3f, 0xcf, 0x28, 0x8d, 0x86, 0x89, 0x99, 0x99, 
0xdc, 0x3b, 0x72, 0x84, 0xdb, 0x45, 0x45, 0x6e, 0x01, 0x9b, 0x8e, 0x1f, 
0xe7, 0x7a, 0x61, 0x21, 0xd1, 0x7a, 0x3d, 0x51, 0x3a, 0x1d, 0x2f, 0x6e, 
0xdd, 0xa2, 0xf1, 0xd0, 0x21, 0x8f, 0xe0, 0xe1, 0x5a, 0xad, 0x4b, 0xb2, 
0xbd, 0x06, 0x7e, 0x71, 0x1d, 0xc7, 0x45, 0xc0, 0x77, 0x0f, 0xca, 0xca, 
0x38, 0xff, 0x0f, 0x3b, 0x00, 0xd4, 0xf3, 0xe6, 0xb1, 0xf0, 0xd2, 0x25, 
0x7a, 0x9e, 0x3d, 0xe3, 0xdc, 0x17, 0x5f, 0xf0, 0xac, 0xa1, 0x81, 0x88, 
0x39, 0x73, 0x98, 0xb0, 0x70, 0x21, 0x03, 0x7d, 0x7d, 0xb4, 0x55, 0x56, 
0x62, 0x32, 0x18, 0x18, 0x33, 0x73, 0x26, 0x8b, 0x0c, 0x06, 0xa4, 0x0a, 
0x05, 0x65, 0x69, 0x69, 0xb4, 0x5f, 0xbe, 0xec, 0x91, 0xc0, 0x57, 0x15, 
0x15, 0x2e, 0xa9, 0x56, 0x0c, 0xe4, 0xb8, 0x08, 0xa8, 0x80, 0x66, 0x40, 
0x79, 0x31, 0x33, 0x93, 0x96, 0x33, 0x67, 0x86, 0x0d, 0x9a, 0xb1, 0x7e, 
0x3d, 0xc9, 0x85, 0x85, 0xd8, 0xcd, 0x66, 0x6a, 0xd6, 0xad, 0xa3, 0xe5, 
0xf4, 0xe9, 0xc1, 0xf4, 0x8e, 0x50, 0x2a, 0x99, 0xb6, 0x6a, 0x15, 0x33, 
0x37, 0x6c, 0x40, 0x1e, 0x12, 0xc2, 0x6f, 0xab, 0x57, 0x73, 0xf3, 0xc0, 
0x01, 0x8f, 0xe0, 0xe3, 0xd3, 0xd3, 0xd1, 0x5d, 0xbc, 0x08, 0x0e, 0xb1, 
0x1a, 0x03, 0xb4, 0xbb, 0x09, 0x92, 0xde, 0x57, 0xaf, 0xf8, 0x61, 0xfa, 
0x74, 0xde, 0x3c, 0x7a, 0x34, 0x38, 0x50, 0x22, 0x08, 0x64, 0x9b, 0x4c, 
0x8c, 0x1c, 0x3b, 0x16, 0x80, 0xb7, 0x3d, 0x3d, 0x3c, 0xbb, 0x71, 0x83, 
0x80, 0xe0, 0x60, 0x3e, 0x8a, 0x8c, 0x44, 0x16, 0x14, 0xc4, 0xdb, 0x9e, 
0x1e, 0xae, 0x15, 0x14, 0x70, 0xcd, 0x4b, 0xe1, 0x79, 0x13, 0x24, 0x1e, 
0x25, 0x59, 0xe7, 0xd5, 0xab, 0x9c, 0xcb, 0xc8, 0xc0, 0x6e, 0x36, 0x03, 
0x10, 0xbb, 0x62, 0x05, 0xf3, 0x9c, 0x73, 0xfa, 0xb2, 0xb1, 0x11, 0x69, 
0x40, 0xc0, 0xa0, 0xf4, 0x36, 0xdf, 0xbf, 0x4f, 0x47, 0x4d, 0x0d, 0x75, 
0x5b, 0xb6, 0xf0, 0xfa, 0xc1, 0x03, 0x8f, 0xe0, 0xfe, 0x4a, 0x32, 0x18, 
0x22, 0x4a, 0x5f, 0xde, 0xb9, 0x43, 0xb9, 0x4e, 0x87, 0xed, 0xe9, 0x53, 
0xb2, 0x9a, 0x9a, 0x50, 0x46, 0x44, 0xd0, 0xf7, 0xe6, 0x0d, 0xc7, 0x63, 
0x62, 0xb0, 0x75, 0x76, 0x22, 0x0b, 0x0c, 0x04, 0x70, 0x3b, 0x82, 0x3d, 
0xfd, 0xb9, 0x2f, 0x51, 0x3a, 0xe2, 0x1d, 0xff, 0x0e, 0x1c, 0xd2, 0xb9, 
0x7c, 0xf4, 0xd4, 0xa9, 0x91, 0x8b, 0x8d, 0x46, 0x9e, 0x54, 0x55, 0xa1, 
0x8c, 0x88, 0x00, 0xa0, 0x7e, 0xd7, 0x2e, 0x6c, 0xce, 0xbd, 0xe0, 0x7d, 
0xc0, 0xe0, 0x55, 0x96, 0x0f, 0xeb, 0x0d, 0xfc, 0x6a, 0x4c, 0xc0, 0xb1, 
0x1b, 0x1e, 0x9f, 0x34, 0xc9, 0x2f, 0xa5, 0xfc, 0xa1, 0x8d, 0x89, 0xcb, 
0xdc, 0x5a, 0xb3, 0x57, 0xf7, 0xee, 0xf1, 0xa0, 0xac, 0x0c, 0x53, 0x75, 
0x35, 0xd6, 0xf6, 0x76, 0xac, 0x9d, 0x9d, 0x48, 0x24, 0x92, 0x0f, 0x6a, 
0xcd, 0xfe, 0xd7, 0xcd, 0xe9, 0xbb, 0xf6, 0x9f, 0xb4, 0xe7, 0x7f, 0x03, 
0x7a, 0x85, 0x4c, 0xfb, 0x9f, 0x7e, 0xe5, 0x30, 0x00, 0x00, 0x00, 0x00, 
0x49, 0x45, 0x4e, 0x44, 0xae, 0x42, 0x60, 0x82, 
};
