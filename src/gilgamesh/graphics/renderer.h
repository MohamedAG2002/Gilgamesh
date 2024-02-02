#pragma once

#include "gilgamesh/resources/shader.h"
#include "gilgamesh/graphics/camera3d.h"
#include "gilgamesh/graphics/color.h"
#include "gilgamesh/math/transform.h"
#include "gilgamesh/graphics/color.h"

namespace gilg {

// Render Data struct
///////////////////////////////////////////////////////
struct render_data 
{
  camera3d* cam;
  shader* current_shader;
  color clear_color;
};
///////////////////////////////////////////////////////

// Renderer functions
///////////////////////////////////////////////////////
b8 create_renderer();
void destroy_renderer();

void clear_renderer(const color& color);
void begin_renderer(const render_data& data);
void end_renderer();

void render_cube(const transform& transform, const color& color);
///////////////////////////////////////////////////////

}
