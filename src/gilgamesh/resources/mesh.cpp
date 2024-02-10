#include "gilgamesh/resources/mesh.h"
#include "gilgamesh/core/gilg_asserts.h"
#include "gilgamesh/core/logger.h"
#include "gilgamesh/core/memory_alloc.h"
#include "gilgamesh/resources/texture2d.h"
#include "gilgamesh/graphics/backend/graphics_context.h"
#include "gilgamesh/graphics/backend/vertex_array.h"
#include "gilgamesh/graphics/backend/buffer.h"

#include <vector>

namespace gilg {

// Private functions
//////////////////////////////////////////////////////////////////////
static void setup_mesh_buffer(mesh* m)
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

  bind_vertex_array(m->mesh_va);
  
  // Setup VBO
  buffer_desc vbo = {
    .type  = GILG_BUFF_TYPE_VERTEX, 
    .data  = GILG_BUFFER_DATA(vertices), 
    .usage = GILG_BUFF_USAGE_STATIC_DRAW, 
    .count = m->desc.vertices_count
  };
  vertex_array_push_buffer(m->mesh_va, vbo);

  // Setup EBO
  buffer_desc ebo = {
    .type  = GILG_BUFF_TYPE_INDEX, 
    .data  = GILG_BUFFER_DATA(&m->desc.indices), 
    .usage = GILG_BUFF_USAGE_STATIC_DRAW, 
    .count = m->desc.indices_count
  };
  vertex_array_push_buffer(m->mesh_va, ebo);
  
  // Setup the layout
  std::vector<layout_data_type> layout = {
    GILG_FLOAT3, // Position 
    GILG_FLOAT3, // Normal
    GILG_FLOAT2, // Texture coords
  };
  vertex_array_push_layout(m->mesh_va, layout, false);

  unbind_vertex_array(m->mesh_va);
}
//////////////////////////////////////////////////////////////////////

// Mesh functions
//////////////////////////////////////////////////////////////////////
mesh* load_mesh(const mesh_desc& desc)
{
  mesh* m = (mesh*)alloc_memory(sizeof(mesh));
  m->desc = desc;
 
  // Setup the VAO
  m->mesh_va = create_vertex_array();
  setup_mesh_buffer(m); 

  return m;
}

void unload_mesh(mesh* m)
{
  destroy_vertex_array(m->mesh_va);
  free_memory(m, sizeof(mesh));
}

void render_mesh(const mesh* m)
{
  // Render the textures 
  //for(int i = 0; i < m->desc.textures_count; i++)
    //render_texture2d(m->desc.textures[i]);

  // Rendering the indices 
  gcontext_draw_vertex(GILG_DRAW_TRIANGLES, m->mesh_va);
}
//////////////////////////////////////////////////////////////////////

}
