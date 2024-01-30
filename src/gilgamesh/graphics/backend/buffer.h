#pragma once

#include "gilgamesh/core/defines.h"

namespace gilg {

// Buffer type enum
///////////////////////////////////////////////////////
enum buffer_type 
{
  GILG_BUFF_TYPE_VERTEX  = 0x8892,
  GILG_BUFF_TYPE_INDEX   = 0x8893,
  GILG_BUFF_TYPE_UNIFORM = 0x8A11,
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

// Buffer Element enum
///////////////////////////////////////////////////////
struct buffer_element 
{
  i32 size;
  u32 type;
  b8 normalized;
};
///////////////////////////////////////////////////////

// Layout Data Type enum
///////////////////////////////////////////////////////
enum layout_data_type 
{
  GILG_FLOAT1 = sizeof(float),
  GILG_FLOAT2 = sizeof(float) * 2, 
  GILG_FLOAT3 = sizeof(float) * 3,
  GILG_FLOAT4 = sizeof(float) * 4,
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

  // The number of indices if the buffer type is INDEX; the numebr of vertices
  // if the buffer type is VERTEX
  usizei count;
};
///////////////////////////////////////////////////////

}
