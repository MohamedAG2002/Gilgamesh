#pragma once

#include "graphics/backend/vertex_array.h"
#include "graphics/color.h"

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
};
///////////////////////////////////////////////////////

// Renderer functions
///////////////////////////////////////////////////////
renderer create_renderer();
void destroy_renderer(renderer& renderer);

void pre_renderer(renderer& renderer);
void begin_renderer(renderer& renderer, const color& color);
void end_renderer(renderer& renderer);
///////////////////////////////////////////////////////

}
