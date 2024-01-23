#include "graphics/renderer.h"
#include "graphics/color.h"
#include "graphics/backend/graphics_context.h"
#include "graphics/backend/vertex_array.h"
#include "graphics/shader.h"
#include "core/logger.h"
#include "core/defines.h"

namespace gilg {

// Private functions
///////////////////////////////////////////////////////
void setup_buffers(renderer& ren)
{
  float vertices[] = {
    -0.5f, -0.5f, 0.0f, // Top-left
     0.5f, -0.5f, 0.0f, // Top-right
     0.5f,  0.5f, 0.0f, // Bottom-right
    -0.5f,  0.5f, 0.0f  // Bottom-left
  };

  u32 indices[] = {
    0, 1, 2, 
    2, 3, 0
  };

  bind_vertex_array(ren.quad_va);

  // Pushing vbo buffer
  buffer_desc vbo_desc = {
    .type  = GILG_BUFF_TYPE_VERTEX,
    .data  = GILG_BUFFER_DATA(vertices),
    .usage = GILG_BUFF_USAGE_STATIC_DRAW
  };
  vertex_array_push_buffer(ren.quad_va, vbo_desc);

  // Pushing ebo buffer
  buffer_desc ebo_desc = {
    .type  = GILG_BUFF_TYPE_INDEX,
    .data  = GILG_BUFFER_DATA(indices),
    .usage = GILG_BUFF_USAGE_STATIC_DRAW
  };
  vertex_array_push_buffer(ren.quad_va, ebo_desc);

  // Pushing layout 
  // Position 
  vertex_array_push_layout(ren.quad_va, 0, 3, GILG_LAYOUT_DAT_TYPE_FLOAT, false, sizeof(float) * 3, 0);

  unbind_vertex_array(ren.quad_va);
}
///////////////////////////////////////////////////////

// Renderer functions
///////////////////////////////////////////////////////
renderer create_renderer()
{
  renderer ren;
  ren.context = create_gcontext();
  ren.quad_va = create_vertex_array();
  setup_buffers(ren);

  ren.basic_shader = load_shader("assets/shaders/basic.vert.glsl", "assets/shaders/basic.frag.glsl");

  GILG_LOG_INFO("Renderer was successfully created");
  return ren;
}

void destroy_renderer(renderer& renderer)
{
  destroy_vertex_array(renderer.quad_va);
  destroy_gcontext(renderer.context);

  GILG_LOG_INFO("Renderer was successfully destroyed");
}

void clear_renderer(renderer& renderer, const color& color)
{
  gcontext_clear(renderer.context, color);
}

void begin_renderer(renderer& renderer)
{
  bind_shader(renderer.basic_shader);

  bind_vertex_array(renderer.quad_va);
  gcontext_draw_index(renderer.context, GILG_DRAW_TRIANGLES, 6);
  unbind_vertex_array(renderer.quad_va);
}

void end_renderer(renderer& renderer)
{
  gcontext_swap(renderer.context);
}
///////////////////////////////////////////////////////

}
