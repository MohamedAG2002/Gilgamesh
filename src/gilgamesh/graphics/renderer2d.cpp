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
#include <array>

namespace gilg {

// Renderer2D type 
/////////////////////////////////////////////////
struct renderer2d 
{
  std::vector<vertex2d> vertices; 
  std::array<texture2d*, MAX_TEXTURES> textures;
  glm::vec4 quad_vertices[4];

  vertex_array vao;
  shader* batch_shader;

  usizei texture_index = 1;
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
    .count = 0
  };
  vertex_array_push_buffer(ren.vao, ebo_desc);
  /////////////////////////////////////////////////
 
  // Setup layout 
  /////////////////////////////////////////////////
  std::vector<layout_data_type> layout = {
    GILG_FLOAT3, // Position 
    GILG_FLOAT4, // Color
    GILG_FLOAT2, // Texture coords
    GILG_FLOAT1, // Texture index
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

  // Texutre init 
  u32 pixels = 0xffffffff;
  resource_add_texture("white_texture", 1, 1, GILG_RGBA, &pixels);
  ren.textures[0] = resource_get_texture("white_texture");

  // Setting up the texture uniforms in the shader
  bind_shader(ren.batch_shader);
  std::vector<i32> tex_slots(32);
  for(int i = 0; i < 32; i++)
    tex_slots[i] = i;
  set_shader_int_arr(ren.batch_shader, "u_textures", tex_slots);

  // Setting up the quad buffer vertices to be used against matrices 
  ren.quad_vertices[0] = glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f);
  ren.quad_vertices[1] = glm::vec4( 0.5f, -0.5f, 0.0f, 1.0f);
  ren.quad_vertices[2] = glm::vec4( 0.5f,  0.5f, 0.0f, 1.0f);
  ren.quad_vertices[3] = glm::vec4(-0.5f,  0.5f, 0.0f, 1.0f);

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
  ren.vertices.clear();
  
  ren.texture_index = 1;
  ren.vao.index_buffer.count = 0;
}

void flush_renderer2d()
{
  // Render all of the unique textures
  for(i32 i = 0; i < ren.texture_index; i++)
    render_texture2d(ren.textures[i]);

  // Initiate draw call!
  gcontext_draw_index(GILG_DRAW_TRIANGLES, ren.vao);
}

void end_renderer2d()
{
  vertex_array_update_buffer(ren.vao, GILG_BUFF_TYPE_VERTEX, 0, sizeof(vertex2d) * ren.vertices.size(), ren.vertices.data());
  
  flush_renderer2d();
}

void render_quad(const glm::vec2& pos, const glm::vec2& size, const color& color)
{
  // Restart the renderer once the max quads is reached 
  if(ren.vao.index_buffer.count >= MAX_INDICES)
  {
    end_renderer2d();
    begin_renderer2d();
  }

  glm::mat4 model(1.0f);
  model = glm::translate(model, glm::vec3(pos.x, pos.y, 0.0f));
  model = glm::scale(model, glm::vec3(size.x, size.y, 0.0f));

  // Top-left 
  vertex2d v1; 
  v1.position       = model * ren.quad_vertices[0]; 
  v1.color          = color;
  v1.texture_coords = glm::vec2(0.0f, 1.0f); 
  v1.texture_index  = 0.0f;
  ren.vertices.push_back(v1);
 
  // Top-right
  vertex2d v2; 
  v2.position       = model * ren.quad_vertices[1]; 
  v2.color          = color;
  v2.texture_coords = glm::vec2(1.0f, 1.0f); 
  v2.texture_index  = 0.0f;
  ren.vertices.push_back(v2);
 
  // Bottom-right
  vertex2d v3; 
  v3.position       = model * ren.quad_vertices[2]; 
  v3.color          = color;
  v3.texture_coords = glm::vec2(1.0f, 0.0f); 
  v3.texture_index  = 0.0f;
  ren.vertices.push_back(v3);
 
  // Bottom-left
  vertex2d v4; 
  v4.position       = model * ren.quad_vertices[3]; 
  v4.color          = color;
  v4.texture_coords = glm::vec2(0.0f, 0.0f); 
  v4.texture_index  = 0.0f;
  ren.vertices.push_back(v4);
  
  ren.vao.index_buffer.count += 6;
}

void render_quad(const glm::vec2& pos, const glm::vec2& size, texture2d* texture, const color tint)
{ 
  // Restart the renderer once the max quads or the max textures (which should not happen) is reached 
  if(ren.vao.index_buffer.count >= MAX_INDICES || ren.texture_index > MAX_TEXTURES)
  {
    end_renderer2d();
    begin_renderer2d();
  }
  
  glm::mat4 model(1.0f);
  model = glm::translate(model, glm::vec3(pos.x, pos.y, 0.0f));
  model = glm::scale(model, glm::vec3(size.x, size.y, 0.0f));

  // Top-left 
  vertex2d v1; 
  v1.position       = model * ren.quad_vertices[0]; 
  v1.color          = tint;
  v1.texture_coords = glm::vec2(0.0f, 1.0f); 
  v1.texture_index  = texture->slot;
  ren.vertices.push_back(v1);
 
  // Top-right
  vertex2d v2; 
  v2.position       = model * ren.quad_vertices[1]; 
  v2.color          = tint;
  v2.texture_coords = glm::vec2(1.0f, 1.0f); 
  v2.texture_index  = texture->slot;
  ren.vertices.push_back(v2);
 
  // Bottom-right
  vertex2d v3; 
  v3.position       = model * ren.quad_vertices[2]; 
  v3.color          = tint;
  v3.texture_coords = glm::vec2(1.0f, 0.0f); 
  v3.texture_index  = texture->slot;
  ren.vertices.push_back(v3);
 
  // Bottom-left
  vertex2d v4; 
  v4.position       = model * ren.quad_vertices[3]; 
  v4.color          = tint;
  v4.texture_coords = glm::vec2(0.0f, 0.0f); 
  v4.texture_index  = texture->slot;
  ren.vertices.push_back(v4);
  
  ren.vao.index_buffer.count += 6;

  // Check to find if the texture already exists in the array
  b8 found = false;
  for(i32 i = 1; i < ren.texture_index; i++)
    found = texture->id == ren.textures[i]->id;

  // Only add unique textures into the array
  if(found)
    return; 

  // If the texture is unique, add it to the array and 
  // increament the amount of textures to render next flush
  ren.textures[ren.texture_index] = texture;
  ren.texture_index++;
}
/////////////////////////////////////////////////

}
