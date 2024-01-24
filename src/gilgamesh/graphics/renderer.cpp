#include "graphics/renderer.h"
#include "graphics/color.h"
#include "graphics/backend/graphics_context.h"
#include "graphics/backend/vertex_array.h"
#include "resources/shader.h"
#include "resources/texture2d.h"
#include "core/logger.h"
#include "core/defines.h"
#include "math/vertex.h"

#include <string>
#include <unordered_map>
#include <vector>

namespace gilg {

// Private functions
///////////////////////////////////////////////////////
void setup_buffers(renderer& ren)
{
  vertex vertices[] = {
    // Position                    Texture coords
    glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec2(0, 1), // Top-left
    glm::vec3( 0.5f, -0.5f, 0.0f), glm::vec2(1, 1), // Top-right
    glm::vec3( 0.5f,  0.5f, 0.0f), glm::vec2(1, 0), // Bottom-right
    glm::vec3(-0.5f,  0.5f, 0.0f), glm::vec2(0, 0), // Bottom-left
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
  std::vector<layout_data_type> layout = {
    GILG_FLOAT3, 
    GILG_FLOAT2,
  };
  vertex_array_push_layout(ren.quad_va, layout);

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

  ren.shaders["basic"] = load_shader("assets/shaders/basic.vert.glsl", "assets/shaders/basic.frag.glsl");
  ren.shaders["texture"] = load_shader("assets/shaders/texture.vert.glsl", "assets/shaders/texture.frag.glsl");
  ren.current_shader = ren.shaders["texture"];

  ren.texture = load_texture2d("assets/textures/container.jpg");

  GILG_LOG_INFO("Renderer was successfully created");
  return ren;
}

void destroy_renderer(renderer& renderer)
{
  unload_texture2d(renderer.texture);

  for(auto& [key, value] : renderer.shaders)
    unload_shader(value);

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
  bind_shader(renderer.current_shader);
  render_texture2d(renderer.texture, 0);

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
