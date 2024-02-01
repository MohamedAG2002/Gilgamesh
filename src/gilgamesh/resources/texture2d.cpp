#include "texture2d.h"
#include "gilgamesh/core/defines.h"
#include "gilgamesh/core/logger.h"

#include <glad/gl.h>
#include <stb_image/stb_image.h>

#include <string>

namespace gilg {

// Texture2D functions
//////////////////////////////////////////////////////////////
texture2d load_texture2d(const std::string& path)
{
  texture2d tex;
  tex.id = 0;
  tex.depth = 0;

  // Generate and bind the texture 
  glGenTextures(1, &tex.id);
  glBindTexture(GL_TEXTURE_2D, tex.id);

  i32 num_channels = 0;
  
  stbi_set_flip_vertically_on_load(true);
  u8* data = stbi_load(path.c_str(), &tex.width, &tex.height, &num_channels, 0);
  if(data)
  {
    if(num_channels == 1)
      tex.format = GILG_RED;
    else if(num_channels == 2)
      tex.format = GILG_RG;
    else if(num_channels == 3)
      tex.format = GILG_RGB;
    else if(num_channels == 4)
      tex.format = GILG_RGBA;

    // Loading the texture and generating the mipmap
    glTexImage2D(GL_TEXTURE_2D, tex.depth, GL_RGBA, tex.width, tex.height, 0, tex.format, GL_UNSIGNED_BYTE, data); 
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

void unload_texture2d(texture2d& texture)
{
  glDeleteTextures(1, &texture.id);
}

void render_texture2d(const texture2d& texture, i32 num)
{
  glActiveTexture(GL_TEXTURE0 + num);
  glBindTexture(GL_TEXTURE_2D, texture.id);
}
//////////////////////////////////////////////////////////////

}
