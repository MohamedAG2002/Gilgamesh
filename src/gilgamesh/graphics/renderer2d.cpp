#include "renderer2d.h"
#include "gilgamesh/core/defines.h"
#include "gilgamesh/core/logger.h"
#include "gilgamesh/graphics/color.h"
#include "gilgamesh/graphics/backend/graphics_context.h"
#include "gilgamesh/graphics/backend/vertex_array.h"
#include "gilgamesh/graphics/backend/buffer.h"
#include "gilgamesh/math/vertex.h"
#include "gilgamesh/resources/texture2d.h"
#include "gilgamesh/resources/shader.h"
#include "gilgamesh/resources/resource_manager.h"

#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>

#include <vector>

namespace gilg {

// Renderer2D type 
/////////////////////////////////////////////////
struct renderer2d 
{
  std::vector<vertex2d> vertices; 

  vertex_array vao;
  shader batch_shader;

  u32 inst_count;
};

static renderer2d ren;
/////////////////////////////////////////////////

// Private functions
/////////////////////////////////////////////////
static void setup_buffers()
{
  // Setup vao 
  /////////////////////////////////////////////////
  bind_vertex_array(ren.vao);
  
  // Setup vbo 
  /////////////////////////////////////////////////
  buffer_desc vbo_desc = {
    .type  = GILG_BUFF_TYPE_VERTEX, 
    .data  = GILG_BUFFER_ALLOC(vertex2d, MAX_VERTICES), 
    .usage = GILG_BUFF_USAGE_DYNAMIC_DRAW, 
    .count = MAX_VERTICES
  };
  vertex_array_push_buffer(ren.vao, vbo_desc);
  /////////////////////////////////////////////////

  // Setup ebo
  /////////////////////////////////////////////////
  u32 indices[MAX_INDICES]; 
  u32 offset = 0;         
  for(int i = 0; i < MAX_INDICES; i += 6)
  {
    indices[i + 0] = 0 + offset;
    indices[i + 1] = 1 + offset;
    indices[i + 2] = 2 + offset;

    indices[i + 3] = 2 + offset;
    indices[i + 4] = 3 + offset;
    indices[i + 5] = 0 + offset;
  
    offset += 4;
  }

  buffer_desc ebo_desc = {
    .type  = GILG_BUFF_TYPE_INDEX, 
    .data  = GILG_BUFFER_DATA(indices), 
    .usage = GILG_BUFF_USAGE_STATIC_DRAW, 
    .count = 6
  };
  vertex_array_push_buffer(ren.vao, ebo_desc);
  /////////////////////////////////////////////////
 
  // Setup layout 
  /////////////////////////////////////////////////
  std::vector<layout_data_type> layout = {
    GILG_FLOAT3, 
    GILG_FLOAT4, 
    GILG_FLOAT2,
  };
  vertex_array_push_layout(ren.vao, layout, false);
  /////////////////////////////////////////////////
 
  unbind_vertex_array(ren.vao);
  /////////////////////////////////////////////////
}
/////////////////////////////////////////////////

// Renderer2D functions 
/////////////////////////////////////////////////
b8 create_renderer2d()
{
  // Vao init
  ren.vao = create_vertex_array();
  setup_buffers();

  // Shaders init
  resource_add_shader("batch", "assets/shaders/batch.vert.glsl", "assets/shaders/batch.frag.glsl");
  ren.batch_shader = resource_get_shader("batch");

  GILG_LOG_INFO("Renderer2D was successfully created");
  return true;
}

void destroy_renderer2d()
{
  ren.vertices.clear();
  destroy_vertex_array(ren.vao);

  GILG_LOG_INFO("Renderer2D was successfully shutdown");
}

void begin_renderer2d()
{
  bind_shader(ren.batch_shader);
}

void end_renderer2d()
{
  vertex_array_update_buffer(ren.vao, GILG_BUFF_TYPE_VERTEX, 0, sizeof(vertex2d) * ren.vertices.size(), ren.vertices.data());
  gcontext_draw_index(GILG_DRAW_TRIANGLES, ren.vao);
  
  ren.vertices.clear();
  ren.vao.index_buffer.count = 0;
}

void render_quad(const glm::vec2& pos, const glm::vec2& size, const color& color)
{
  // Top-left 
  vertex2d v1; 
  v1.position       = glm::vec3(pos.x, pos.y, 0.0f); 
  v1.color          = color;
  v1.texture_coords = glm::vec2(0.0f, 1.0f); 
  ren.vertices.push_back(v1);
 
  // Top-right
  vertex2d v2; 
  v2.position       = glm::vec3(pos.x + size.x, pos.y, 0.0f); 
  v2.color          = color;
  v2.texture_coords = glm::vec2(1.0f, 1.0f); 
  ren.vertices.push_back(v2);
 
  // Bottom-right
  vertex2d v3; 
  v3.position       = glm::vec3(pos.x + size.x, pos.y + size.y, 0.0f); 
  v3.color          = color;
  v3.texture_coords = glm::vec2(1.0f, 0.0f); 
  ren.vertices.push_back(v3);
 
  // Bottom-left
  vertex2d v4; 
  v4.position       = glm::vec3(pos.x, pos.y + size.y, 0.0f); 
  v4.color          = color;
  v4.texture_coords = glm::vec2(0.0f, 0.0f); 
  ren.vertices.push_back(v4);

  ren.vao.index_buffer.count += 6;
}

void render_quad(const glm::vec2& pos, const glm::vec2& size, const texture2d&texture)
{ 
}
/////////////////////////////////////////////////

}
