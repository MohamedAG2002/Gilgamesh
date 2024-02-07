#include "texture2d.h"
#include "gilgamesh/core/defines.h"
#include "gilgamesh/core/logger.h"
#include "gilgamesh/core/memory_alloc.h"

#include <glad/gl.h>
#include <stb_image/stb_image.h>

#include <string>

namespace gilg {

// Globals
//////////////////////////////////////////////////////////////
static i32 total_slot = -1;
//////////////////////////////////////////////////////////////

// Texture2D functions
//////////////////////////////////////////////////////////////
texture2d* load_texture2d(const std::string& path)
{
  texture2d* tex = (texture2d*)alloc_memory(sizeof(texture2d));
  tex->id    = 0;
  tex->depth = 0;
  tex->slot  = ++total_slot;

  // Generate and bind the texture 
  glGenTextures(1, &tex->id);
  glBindTexture(GL_TEXTURE_2D, tex->id);

  i32 num_channels = 0;
  
  stbi_set_flip_vertically_on_load(true);
  u8* data = stbi_load(path.c_str(), &tex->width, &tex->height, &num_channels, 0);
  if(data)
  {
    if(num_channels == 1)
      tex->format = GILG_RED;
    else if(num_channels == 2)
      tex->format = GILG_RG;
    else if(num_channels == 3)
      tex->format = GILG_RGB;
    else if(num_channels == 4)
      tex->format = GILG_RGBA;

    // Loading the texture and generating the mipmap
    glTexImage2D(GL_TEXTURE_2D, tex->depth, GL_RGBA, tex->width, tex->height, 0, tex->format, GL_UNSIGNED_BYTE, data); 
    glGenerateMipmap(GL_TEXTURE_2D); 
  }
  else 
    GILG_LOG_ERROR("Failed to load texture at \'%s\'", path.c_str());

  // Setting some parametars of the texture
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  // Free the loaded data since it was already sent to the GPU 
  stbi_image_free(data);

  return tex;
}

texture2d* load_texture2d(i32 width, i32 height, texture_format format, void* pixels)
{
  texture2d* tex = (texture2d*)alloc_memory(sizeof(texture2d));
  tex->id     = 0;
  tex->width  = width;
  tex->height = height;
  tex->depth  = 0;
  tex->slot   = ++total_slot;
  tex->format = format;

  // Generate and bind the texture 
  glGenTextures(1, &tex->id);
  glBindTexture(GL_TEXTURE_2D, tex->id);
  
  if(pixels)
  {
    // Loading the texture and generating the mipmap
    glTexImage2D(GL_TEXTURE_2D, tex->depth, GL_RGBA, tex->width, tex->height, 0, tex->format, GL_UNSIGNED_BYTE, pixels); 
    glGenerateMipmap(GL_TEXTURE_2D); 
  }
  else 
    GILG_LOG_ERROR("Texture pixels given is not valid");
  
  // Setting some parametars of the texture
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
 
  return tex;
}

void unload_texture2d(texture2d* texture)
{
  glDeleteTextures(1, &texture->id);
  free_memory(texture, sizeof(texture2d));
}

void render_texture2d(const texture2d* texture)
{
  glActiveTexture(GL_TEXTURE0 + texture->slot);
  glBindTexture(GL_TEXTURE_2D, texture->id);
}
//////////////////////////////////////////////////////////////

}
