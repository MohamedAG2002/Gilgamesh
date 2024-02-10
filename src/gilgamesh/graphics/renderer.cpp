#include "renderer.h"
#include "gilgamesh/graphics/renderer2d.h"
#include "gilgamesh/graphics/color.h"
#include "gilgamesh/graphics/renderer_queue.h"
#include "gilgamesh/graphics/camera3d.h"
#include "gilgamesh/graphics/shader_lib.h"

#include "gilgamesh/graphics/backend/graphics_context.h"
#include "gilgamesh/graphics/backend/vertex_array.h"
#include "gilgamesh/graphics/backend/uniform_buffer.h"

#include "gilgamesh/resources/resource_manager.h"
#include "gilgamesh/resources/mesh.h"

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
  mesh* cube_mesh;

  std::vector<glm::mat4> transforms;
  usizei inst_count;
};

static renderer renderer;
///////////////////////////////////////////////////////

// Private functions
///////////////////////////////////////////////////////
static void setup_buffers()
{
  vertex vertices[] = {
    glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(0.0f, 0.0f),  
    glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(1.0f, 0.0f), 
    glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(1.0f, 1.0f), 
    glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(1.0f, 1.0f), 
    glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(0.0f, 1.0f), 
    glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(0.0f, 0.0f), 
    glm::vec3(-0.5f, -0.5f, 0.5f),  glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f),
    glm::vec3( 0.5f, -0.5f, 0.5f),  glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1.0f, 0.0f),
    glm::vec3( 0.5f,  0.5f, 0.5f),  glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1.0f, 1.0f),
    glm::vec3( 0.5f,  0.5f, 0.5f),  glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1.0f, 1.0f),
    glm::vec3(-0.5f,  0.5f, 0.5f),  glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 1.0f),
    glm::vec3(-0.5f, -0.5f, 0.5f),  glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0.0f, 0.0f),
    glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 0.0f),
    glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 1.0f),
    glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 1.0f),
    glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 1.0f),
    glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f),
    glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 0.0f),
    glm::vec3(0.5f,  0.5f,  0.5f),  glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 0.0f),
    glm::vec3(0.5f,  0.5f, -0.5f),  glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 1.0f),
    glm::vec3(0.5f, -0.5f, -0.5f),  glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 1.0f),
    glm::vec3(0.5f, -0.5f, -0.5f),  glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 1.0f),
    glm::vec3(0.5f, -0.5f,  0.5f),  glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f),
    glm::vec3(0.5f,  0.5f,  0.5f),  glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 0.0f),
    glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(0.0f, 1.0f),
    glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(1.0f, 1.0f),
    glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(1.0f, 0.0f),
    glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(1.0f, 0.0f),
    glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(0.0f, 0.0f),
    glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(0.0f, 1.0f),
    glm::vec3(-0.5f, 0.5f, -0.5f),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 1.0f),
    glm::vec3( 0.5f, 0.5f, -0.5f),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(1.0f, 1.0f),
    glm::vec3( 0.5f, 0.5f,  0.5f),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(1.0f, 0.0f),
    glm::vec3( 0.5f, 0.5f,  0.5f),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(1.0f, 0.0f),
    glm::vec3(-0.5f, 0.5f,  0.5f),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 0.0f),
    glm::vec3(-0.5f, 0.5f, -0.5f),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 1.0f),
  };

  bind_vertex_array(renderer.quad_va);
  
  buffer_desc vbo = {
    .type = GILG_BUFF_TYPE_VERTEX, 
    .data = GILG_BUFFER_DATA(vertices), 
    .usage = GILG_BUFF_USAGE_STATIC_DRAW,
    .count = 36,
  };
  vertex_array_push_buffer(renderer.quad_va, vbo);

  std::vector<layout_data_type> layout = {
    GILG_FLOAT3, 
    GILG_FLOAT3, 
    GILG_FLOAT2,
  };
  vertex_array_push_layout(renderer.quad_va, layout, false);
  
  buffer_desc inst_vbo = {
    .type = GILG_BUFF_TYPE_INSTANCE, 
    .data = GILG_BUFFER_ALLOC(glm::mat4, 100), 
    .usage = GILG_BUFF_USAGE_DYNAMIC_DRAW,
    .count = 0,
  };
  vertex_array_push_buffer(renderer.quad_va, inst_vbo);
  
  std::vector<layout_data_type> inst_layout = {
    GILG_FLOAT4, 
    GILG_FLOAT4, 
    GILG_FLOAT4,
    GILG_FLOAT4,
  };
  vertex_array_push_layout(renderer.quad_va, inst_layout, true);

  unbind_vertex_array(renderer.quad_va);

  mesh_desc cube_desc = {
    .vertices = vertices, 
    .vertices_count = 36,
    .indices = nullptr,
    .indices_count = 0,
    .textures = nullptr, 
    .textures_count = 0
  };
  resource_add_mesh("cube_mesh", cube_desc);
  renderer.cube_mesh = resource_get_mesh("cube_mesh");
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

  if(!shader_lib_init("assets/shaders/"))
  {
    GILG_LOG_FATAL("Failed to initialize shader library");
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
  shader_lib_add("basic", "basic.glsl");
  shader_lib_add("basic3d", "basic3d.glsl");
  shader_lib_add("texture", "texture.glsl");
  shader_lib_add("camera", "camera.glsl");
  shader_lib_add("test", "test.glsl");
  shader_lib_add("inst", "inst.glsl");
  renderer.current_shader = shader_lib_get("basic3d");

  GILG_LOG_INFO("Renderer was successfully created");
  return true;
}

void destroy_renderer()
{
  renderer.transforms.clear();

  destroy_uniform_buffer(renderer.ubo);
  destroy_vertex_array(renderer.quad_va);
  destroy_renderer2d();
  shader_lib_shutdown();
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
                               GILG_BUFF_TYPE_INSTANCE, 
                               i * sizeof(glm::mat4), sizeof(glm::mat4), 
                               glm::value_ptr(renderer.transforms[i]));
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
  bind_shader(renderer.current_shader);
  set_shader_mat4(renderer.current_shader, "u_model", transform.model);
  set_shader_vec4(renderer.current_shader, "u_color", color);
  render_mesh(renderer.cube_mesh);
  
  //renderer.transforms.push_back(transform.model);
  //renderer.inst_count++;
}
///////////////////////////////////////////////////////

}
