#include "renderer.h"
#include "graphics/color.h"
#include "graphics/renderer_queue.h"
#include "graphics/camera3d.h"

#include "graphics/backend/graphics_context.h"
#include "graphics/backend/vertex_array.h"

#include "resources/resource_manager.h"

#include "core/logger.h"
#include "core/defines.h"

#include "math/vertex.h"

#include <glm/ext/matrix_transform.hpp>

#include <string>
#include <unordered_map>
#include <vector>

namespace gilg {

// Private functions
///////////////////////////////////////////////////////
void setup_buffers(renderer& ren)
{
  /*
  vertex vertices[] = {
    // Position                    Texture coords
    glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec2(0, 1), // Top-left
    glm::vec3( 0.5f, -0.5f, 0.0f), glm::vec2(1, 1), // Top-right
    glm::vec3( 0.5f,  0.5f, 0.0f), glm::vec2(1, 0), // Bottom-right
    glm::vec3(-0.5f,  0.5f, 0.0f), glm::vec2(0, 0), // Bottom-left
  };
  */

  vertex vertices[] = {
    glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 0.0f),  
    glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec2(1.0f, 0.0f), 
    glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec2(1.0f, 1.0f), 
    glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec2(1.0f, 1.0f), 
    glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec2(0.0f, 1.0f), 
    glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 0.0f), 
   
    // Back-face
    glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(0.0f, 0.0f),
    glm::vec3( 0.5f, -0.5f, 0.5f), glm::vec2(1.0f, 0.0f),
    glm::vec3( 0.5f,  0.5f, 0.5f), glm::vec2(1.0f, 1.0f),
    glm::vec3( 0.5f,  0.5f, 0.5f), glm::vec2(1.0f, 1.0f),
    glm::vec3(-0.5f,  0.5f, 0.5f), glm::vec2(0.0f, 1.0f),
    glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(0.0f, 0.0f),
   
    // Left-face
    glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec2(1.0f, 0.0f),
    glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec2(1.0f, 1.0f),
    glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 1.0f),
    glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 1.0f),
    glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec2(0.0f, 0.0f),
    glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec2(1.0f, 0.0f),
   
    // Right-face
    glm::vec3(0.5f,  0.5f,  0.5f), glm::vec2(1.0f, 0.0f),
    glm::vec3(0.5f,  0.5f, -0.5f), glm::vec2(1.0f, 1.0f),
    glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 1.0f),
    glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 1.0f),
    glm::vec3(0.5f, -0.5f,  0.5f), glm::vec2(0.0f, 0.0f),
    glm::vec3(0.5f,  0.5f,  0.5f), glm::vec2(1.0f, 0.0f),
   
    // Bottom-face
    glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec2(0.0f, 1.0f),
    glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec2(1.0f, 1.0f),
    glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec2(1.0f, 0.0f),
    glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec2(1.0f, 0.0f),
    glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec2(0.0f, 0.0f),
    glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec2(0.0f, 1.0f),
   
    // Top-face
    glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec2(0.0f, 1.0f),
    glm::vec3( 0.5f, 0.5f, -0.5f), glm::vec2(1.0f, 1.0f),
    glm::vec3( 0.5f, 0.5f,  0.5f), glm::vec2(1.0f, 0.0f),
    glm::vec3( 0.5f, 0.5f,  0.5f), glm::vec2(1.0f, 0.0f),
    glm::vec3(-0.5f, 0.5f,  0.5f), glm::vec2(0.0f, 0.0f),
    glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec2(0.0f, 1.0f),
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
    .usage = GILG_BUFF_USAGE_STATIC_DRAW, 
    .count = 36
  };
  vertex_array_push_buffer(ren.quad_va, vbo_desc);

  // Pushing ebo buffer
  buffer_desc ebo_desc = {
    .type  = GILG_BUFF_TYPE_INDEX,
    .data  = GILG_BUFFER_DATA(indices),
    .usage = GILG_BUFF_USAGE_STATIC_DRAW, 
    .count = 6
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
  if(!create_gcontext()) 
    GILG_LOG_ERROR("Failed to create graphics context");

  ren.quad_va = create_vertex_array();
  setup_buffers(ren);

  ren.shaders["basic"] = resource_add_shader("assets/shaders/basic.vert.glsl", "assets/shaders/basic.frag.glsl");
  ren.shaders["texture"] = resource_add_shader("assets/shaders/texture.vert.glsl", "assets/shaders/texture.frag.glsl");
  ren.shaders["camera"] = resource_add_shader("assets/shaders/camera.vert.glsl", "assets/shaders/camera.frag.glsl");
  ren.current_shader = ren.shaders["camera"];

  ren.textures["container"] = resource_add_texture("assets/textures/container.jpg");

  ren.curr_shdr = resource_get_shader(ren.current_shader);
  ren.curr_tex = resource_get_texture(ren.textures["container"]);

  GILG_LOG_INFO("Renderer was successfully created");
  return ren;
}

void destroy_renderer(renderer& renderer)
{
  destroy_vertex_array(renderer.quad_va);
  destroy_gcontext();

  GILG_LOG_INFO("Renderer was successfully destroyed");
}

void pre_renderer(renderer& renderer, const camera3d& cam)
{
  bind_shader(renderer.curr_shdr);
 
  set_shader_mat4(renderer.curr_shdr, "u_projection", cam.projection); 
  set_shader_mat4(renderer.curr_shdr, "u_view", cam.view); 

  glm::mat4 model(1.0f);
  model = glm::translate(model, glm::vec3(0.0f, 0.0f, -3.0f));
  set_shader_mat4(renderer.curr_shdr, "u_model", model); 
}

void begin_renderer(renderer& renderer, const color& color)
{
  gcontext_clear(color);
  gcontext_draw_vertex(GILG_DRAW_TRIANGLES, renderer.quad_va);

  //renderer_queue_sumbit(renderer.quad_va);
}

void end_renderer(renderer& renderer)
{
  //renderer_queue_flush();

  gcontext_swap();
}
///////////////////////////////////////////////////////

}
