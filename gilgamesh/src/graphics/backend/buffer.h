#pragma once

#include "core/defines.h"

namespace gilg {

// Buffer type enum
///////////////////////////////////////////////////////
enum buffer_type 
{
  GILG_BUFF_TYPE_VERTEX = 0x8892,
  GILG_BUFF_TYPE_INDEX  = 0x8893,
};
///////////////////////////////////////////////////////

// Buffer mode enum
///////////////////////////////////////////////////////
enum buffer_usage
{
  // Dynamic
  GILG_BUFF_USAGE_DYNAMIC_COPY = 0x88EA, 
  GILG_BUFF_USAGE_DYNAMIC_DRAW = 0x88E8,
  GILG_BUFF_USAGE_DYNAMIC_READ = 0x88E9,

  // Static 
  GILG_BUFF_USAGE_STATIC_COPY = 0x88E6,
  GILG_BUFF_USAGE_STATIC_DRAW = 0x88E4,
  GILG_BUFF_USAGE_STATIC_READ = 0x88E5,

  // Stream
  GILG_BUFF_USAGE_STREAM_COPY = 0x88E2, 
  GIGL_BUFF_USAGE_STREAM_DRAW = 0x88E0, 
  GIGL_BUFF_USAGE_STREAM_READ = 0x88E1, 
};
///////////////////////////////////////////////////////

// Layout Data Type enum
///////////////////////////////////////////////////////
enum layout_data_type 
{
  GILG_LAYOUT_DAT_TYPE_BYTE  = 0x1400,
  GILG_LAYOUT_DAT_TYPE_UBYTE = 0x1401,
  
  GILG_LAYOUT_DAT_TYPE_SHORT   = 0x1402,
  GILG_LAYOUT_DAT_TYPE_USHORT  = 0x1403,
  
  GILG_LAYOUT_DAT_TYPE_INT  = 0x1404,
  GILG_LAYOUT_DAT_TYPE_UINT = 0x1405,

  GILG_LAYOUT_DAT_TYPE_FLOAT      = 0x1406,
  GILG_LAYOUT_DAT_TYPE_HALF_FLOAT = 0x1408,
};
///////////////////////////////////////////////////////

// Buffer Data type
///////////////////////////////////////////////////////
struct buffer_data
{
  void* data;
  usizei size;
};
///////////////////////////////////////////////////////

// Buffer Desc type
///////////////////////////////////////////////////////
struct buffer_desc 
{
  // DO NOT MESS WITH THIS ID VARIABLE!!!!!!
  u32 id;
  
  buffer_type type;
  buffer_data data;
  buffer_usage usage;
};
///////////////////////////////////////////////////////

}
