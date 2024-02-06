#pragma once

#include "gilgamesh/core/defines.h"

#include <stb_image/stb_image.h>

#include <string>

namespace gilg {

// Texture format enum
//////////////////////////////////////////////////////////////
enum texture_format 
{
  GILG_RED  = 0x1903,
  GILG_RG   = 0x8227,
  GILG_RGB  = 0x1907,
  GILG_RGBA = 0x1908, 
};
//////////////////////////////////////////////////////////////

// Texture2D type
//////////////////////////////////////////////////////////////
struct texture2d 
{
  u32 id;
  i32 width, height;
  i32 depth, slot;
  texture_format format;
};
//////////////////////////////////////////////////////////////

// Texture2D functions
//////////////////////////////////////////////////////////////
texture2d* load_texture2d(const std::string& path);
texture2d* load_texture2d(u32 width, u32 height, texture_format format, void* pixels);
void unload_texture2d(texture2d* texture);
void render_texture2d(const texture2d* texture);
//////////////////////////////////////////////////////////////

}
