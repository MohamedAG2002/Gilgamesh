#pragma once

#include "graphics/camera3d.h"
#include "graphics/color.h"
#include "graphics/backend/vertex_array.h"

#include "resources/shader.h"
#include "resources/texture2d.h"

#include <string>
#include <unordered_map>

namespace gilg {

// Renderer type
///////////////////////////////////////////////////////
struct renderer 
{
  vertex_array quad_va;
  std::unordered_map<std::string, u64> shaders, textures;
  u64 current_shader;
 
  shader curr_shdr;
  texture2d curr_tex;
};
///////////////////////////////////////////////////////

// Renderer functions
///////////////////////////////////////////////////////
renderer create_renderer();
void destroy_renderer(renderer& renderer);

void pre_renderer(renderer& renderer, const camera3d& cam);
void begin_renderer(renderer& renderer, const color& color);
void end_renderer(renderer& renderer);
///////////////////////////////////////////////////////

}
