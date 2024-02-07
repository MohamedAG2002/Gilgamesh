#include "renderer.h"
#include "gilgamesh/graphics/renderer2d.h"
#include "gilgamesh/graphics/color.h"
#include "gilgamesh/graphics/renderer_queue.h"
#include "gilgamesh/graphics/camera3d.h"

#include "gilgamesh/graphics/backend/graphics_context.h"
#include "gilgamesh/graphics/backend/vertex_array.h"
#include "gilgamesh/graphics/backend/uniform_buffer.h"

#include "gilgamesh/resources/resource_manager.h"

#include "gilgamesh/core/logger.h"
#include "gilgamesh/core/defines.h"

#include "gilgamesh/math/vertex.h"
#include "gilgamesh/math/transform.h"

#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/gl.h>

#include <string>
#include <vector>

namespace gilg {

// Renderer type
///////////////////////////////////////////////////////
struct renderer 
{
  vertex_array quad_va;
  uniform_buffer ubo;
  shader* current_shader;

  std::vector<transform> transforms;
  usizei inst_count;
};

static renderer renderer;
///////////////////////////////////////////////////////


// Private functions
///////////////////////////////////////////////////////
static void setup_buffers()
{
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

  bind_vertex_array(renderer.quad_va);

  // Pushing vbo buffer
  buffer_desc vbo_desc = {
    .type  = GILG_BUFF_TYPE_VERTEX,
    .data  = GILG_BUFFER_DATA(vertices),
    .usage = GILG_BUFF_USAGE_STATIC_DRAW, 
    .count = 36
  };
  vertex_array_push_buffer(renderer.quad_va, vbo_desc);
  
  // Pushing layouts
  std::vector<layout_data_type> layout = {
    GILG_FLOAT3, 
    GILG_FLOAT2,
  };
  vertex_array_push_layout(renderer.quad_va, layout, false);

  // Pushing instance buffer
  buffer_desc inst_desc = {
    .type  = GILG_BUFF_TYPE_INSTANCE,
    .data  = GILG_BUFFER_ALLOC(glm::mat4, 1024),
    .usage = GILG_BUFF_USAGE_DYNAMIC_DRAW, 
    .count = 1024
  };
  vertex_array_push_buffer(renderer.quad_va, inst_desc);

  std::vector<layout_data_type> inst_layout = {
    GILG_FLOAT4, // Matrix 1st colomn
    GILG_FLOAT4, // Matrix 2nd colomn
    GILG_FLOAT4, // Matrix 3rd colomn
    GILG_FLOAT4, // Matrix 4th colomn
  };
  vertex_array_push_layout(renderer.quad_va, inst_layout, true);

  unbind_vertex_array(renderer.quad_va);
}
///////////////////////////////////////////////////////

// Renderer functions
///////////////////////////////////////////////////////
b8 create_renderer()
{
  if(!create_gcontext()) 
  {
    GILG_LOG_FATAL("Failed to create graphics context");
    return false;
  }

  if(!create_renderer2d())
  {
    GILG_LOG_FATAL("Failed to create renderer2d");
    return false;
  }

  renderer.quad_va = create_vertex_array();
  setup_buffers();
  renderer.ubo = create_uniform_buffer(0);

  // Shaders init 
  resource_add_shader("basic", "assets/shaders/basic.vert.glsl", "assets/shaders/basic.frag.glsl");
  resource_add_shader("texture", "assets/shaders/texture.vert.glsl", "assets/shaders/texture.frag.glsl");
  resource_add_shader("camera", "assets/shaders/camera.vert.glsl", "assets/shaders/camera.frag.glsl");
  resource_add_shader("test", "assets/shaders/test.vert.glsl", "assets/shaders/test.frag.glsl");
  resource_add_shader("inst", "assets/shaders/inst.vert.glsl", "assets/shaders/inst.frag.glsl");
  renderer.current_shader = resource_get_shader("inst");

  GILG_LOG_INFO("Renderer was successfully created");
  return true;
}

void destroy_renderer()
{
  renderer.transforms.clear();

  destroy_uniform_buffer(renderer.ubo);
  destroy_vertex_array(renderer.quad_va);
  destroy_renderer2d();
  destroy_gcontext();

  GILG_LOG_INFO("Renderer was successfully destroyed");
}

void clear_renderer(const color& color)
{
  gcontext_clear(color);
}

void begin_renderer(const render_data& data)
{
  uniform_buffer_upload_mat4(renderer.ubo, data.cam->view_projection);
}

void end_renderer()
{
  /*
  // Setting up the transform 
  for(int i = 0; i < renderer.transforms.size(); i++)
  {
    vertex_array_update_buffer(renderer.quad_va, 
                               GILG_BUFF_TYPE_VERTEX, 
                               i * sizeof(glm::mat4), sizeof(glm::mat4), 
                               glm::value_ptr(renderer.transforms[i].model));
  }
 
  // The actual render call
  renderer_queue_sumbit_inst(renderer.current_shader, renderer.quad_va, renderer.inst_count);

  // Bringing everything back to normal 
  renderer.inst_count = 0;
  renderer.transforms.clear();
  */

  gcontext_swap();
}

void render_cube(const transform& transform, const color& color)
{
  renderer.transforms.push_back(transform);
  renderer.inst_count++;
}
///////////////////////////////////////////////////////

}
