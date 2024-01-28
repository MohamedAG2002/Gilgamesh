#pragma once

#include "resources/shader.h"
#include "graphics/camera3d.h"
#include "graphics/color.h"

namespace gilg {

// Render Data struct
///////////////////////////////////////////////////////
struct render_data 
{
  camera3d* cam;
  shader* current_shader;
};
///////////////////////////////////////////////////////

// Renderer functions
///////////////////////////////////////////////////////
b8 create_renderer();
void destroy_renderer();

void clear_renderer(const color& color);
void begin_renderer(const render_data& data);
void end_renderer();
///////////////////////////////////////////////////////

}
