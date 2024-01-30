#include "renderer.h"
#include "gilgamesh/graphics/color.h"
#include "gilgamesh/graphics/renderer_queue.h"
#include "gilgamesh/graphics/camera3d.h"

#include "gilgamesh/graphics/backend/graphics_context.h"
#include "gilgamesh/graphics/backend/vertex_array.h"

#include "gilgamesh/resources/resource_manager.h"

#include "gilgamesh/core/logger.h"
#include "gilgamesh/core/defines.h"

#include "gilgamesh/math/vertex.h"
#include "gilgamesh/math/transform.h"

#include <glm/ext/matrix_transform.hpp>

#include <string>
#include <unordered_map>
#include <vector>

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

  std::vector<transform> models;
};

static renderer renderer;
///////////////////////////////////////////////////////


// Private functions
///////////////////////////////////////////////////////
void setup_buffers()
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

  bind_vertex_array(renderer.quad_va);

  // Pushing vbo buffer
  buffer_desc vbo_desc = {
    .type  = GILG_BUFF_TYPE_VERTEX,
    .data  = GILG_BUFFER_DATA(vertices),
    .usage = GILG_BUFF_USAGE_STATIC_DRAW, 
    .count = 36
  };
  vertex_array_push_buffer(renderer.quad_va, vbo_desc);

  // Pushing ebo buffer
  buffer_desc ebo_desc = {
    .type  = GILG_BUFF_TYPE_INDEX,
    .data  = GILG_BUFFER_DATA(indices),
    .usage = GILG_BUFF_USAGE_STATIC_DRAW, 
    .count = 6
  };
  vertex_array_push_buffer(renderer.quad_va, ebo_desc);

  // Pushing layout 
  std::vector<layout_data_type> layout = {
    GILG_FLOAT3, 
    GILG_FLOAT2,
  };
  vertex_array_push_layout(renderer.quad_va, layout);

  unbind_vertex_array(renderer.quad_va);
}
///////////////////////////////////////////////////////

// Renderer functions
///////////////////////////////////////////////////////
b8 create_renderer()
{
  if(!create_gcontext()) 
  {
    GILG_LOG_ERROR("Failed to create graphics context");
    return false;
  }

  renderer.quad_va = create_vertex_array();
  setup_buffers();

  renderer.shaders["basic"] = resource_add_shader("assets/shaders/basic.vert.glsl", "assets/shaders/basic.frag.glsl");
  renderer.shaders["texture"] = resource_add_shader("assets/shaders/texture.vert.glsl", "assets/shaders/texture.frag.glsl");
  renderer.shaders["camera"] = resource_add_shader("assets/shaders/camera.vert.glsl", "assets/shaders/camera.frag.glsl");
  renderer.current_shader = renderer.shaders["camera"];

  renderer.textures["container"] = resource_add_texture("assets/textures/container.jpg");

  renderer.curr_shdr = resource_get_shader(renderer.current_shader);
  renderer.curr_tex = resource_get_texture(renderer.textures["container"]);

  renderer.models.push_back(create_transform(glm::vec3(10.0f, 0.0f, 10.0f)));
  renderer.models.push_back(create_transform(glm::vec3(20.0f, 0.0f, 15.0f)));
  renderer.models.push_back(create_transform(glm::vec3(30.0f, 0.0f, 30.0f)));
  renderer.models.push_back(create_transform(glm::vec3(35.0f, 0.0f, 20.0f)));
  renderer.models.push_back(create_transform(glm::vec3(40.0f, 0.0f, 50.0f)));

  GILG_LOG_INFO("Renderer was successfully created");
  return true;
}

void destroy_renderer()
{
  destroy_vertex_array(renderer.quad_va);
  destroy_gcontext();

  GILG_LOG_INFO("Renderer was successfully destroyed");
}

void clear_renderer(const color& color)
{
  gcontext_clear(color);
}

void begin_renderer(const render_data& data)
{
  bind_shader(renderer.curr_shdr);
 
  set_shader_mat4(renderer.curr_shdr, "u_projection", data.cam->projection); 
  set_shader_mat4(renderer.curr_shdr, "u_view", data.cam->view); 
}

void end_renderer()
{
  for(auto& transform : renderer.models)
  {
    renderer_queue_sumbit(renderer.curr_shdr, renderer.quad_va, transform);
    //renderer_queue_flush();
  }

  gcontext_swap();
}
///////////////////////////////////////////////////////

}
