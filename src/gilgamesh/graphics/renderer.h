#pragma once

#include "graphics/backend/graphics_context.h"
#include "graphics/backend/vertex_array.h"
#include "graphics/color.h"

#include <string>
#include <unordered_map>

namespace gilg {

// Renderer type
///////////////////////////////////////////////////////
struct renderer 
{
  graphics_context context;
  vertex_array quad_va;
  std::unordered_map<std::string, u64> shaders, textures;
  u64 current_shader;
};
///////////////////////////////////////////////////////

// Renderer functions
///////////////////////////////////////////////////////
renderer create_renderer();
void destroy_renderer(renderer& renderer);

void clear_renderer(renderer& renderer, const color& color);
void begin_renderer(renderer& renderer);
void end_renderer(renderer& renderer);
///////////////////////////////////////////////////////

}
