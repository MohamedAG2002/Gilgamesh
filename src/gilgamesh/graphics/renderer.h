#pragma once

#include "graphics/backend/graphics_context.h"
#include "graphics/backend/vertex_array.h"
#include "graphics/color.h"
#include "graphics/shader.h"
#include "graphics/texture2d.h"

#include <string>
#include <unordered_map>

namespace gilg {

// Renderer type
///////////////////////////////////////////////////////
struct renderer 
{
  graphics_context context;
  vertex_array quad_va;
  std::unordered_map<std::string, shader> shaders;
  shader current_shader;
  texture2d texture;
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
