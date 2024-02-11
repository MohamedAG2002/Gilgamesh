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
  bind_vertex_array(m->mesh_va);
  
  // Setup VBO
  buffer_desc vbo = {
    .type  = GILG_BUFF_TYPE_VERTEX, 
    // @TODO: This is bad. Pass in the data another way
    .data  = buffer_data{m->vertices.data(), sizeof(vertex) * m->vertices.size()}, 
    .usage = GILG_BUFF_USAGE_STATIC_DRAW, 
    .count = m->vertices.size()
  };
  vertex_array_push_buffer(m->mesh_va, vbo);

  // Setup EBO
  buffer_desc ebo = {
    .type  = GILG_BUFF_TYPE_INDEX, 
    .data  = buffer_data{m->indices.data(), sizeof(u32) * m->indices.size()}, 
    .usage = GILG_BUFF_USAGE_STATIC_DRAW, 
    .count = m->indices.size()
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

static void build_cube(mesh* m)
{
  // Back-face
  m->vertices.push_back({glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(0.0f, 0.0f)});  
  m->vertices.push_back({glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(1.0f, 0.0f)}); 
  m->vertices.push_back({glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(1.0f, 1.0f)}); 
  m->vertices.push_back({glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(0.0f, 1.0f)}); 

  // Front-face
  m->vertices.push_back({glm::vec3(-0.5f, -0.5f, 0.5f),  glm::vec3(0.0f, 0.0f, 1.0f),  glm::vec2(0.0f, 0.0f)});
  m->vertices.push_back({glm::vec3( 0.5f, -0.5f, 0.5f),  glm::vec3(0.0f, 0.0f, 1.0f),  glm::vec2(1.0f, 0.0f)});
  m->vertices.push_back({glm::vec3( 0.5f,  0.5f, 0.5f),  glm::vec3(0.0f, 0.0f, 1.0f),  glm::vec2(1.0f, 1.0f)});
  m->vertices.push_back({glm::vec3(-0.5f,  0.5f, 0.5f),  glm::vec3(0.0f, 0.0f, 1.0f),  glm::vec2(0.0f, 1.0f)});

  // Left-face
  m->vertices.push_back({glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 0.0f)});
  m->vertices.push_back({glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(1.0f, 1.0f)});
  m->vertices.push_back({glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 1.0f)});
  m->vertices.push_back({glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 0.0f)});

  // Right-face
  m->vertices.push_back({glm::vec3(0.5f,  0.5f,  0.5f),  glm::vec3(1.0f, 0.0f, 0.0f),  glm::vec2(1.0f, 0.0f)});
  m->vertices.push_back({glm::vec3(0.5f,  0.5f, -0.5f),  glm::vec3(1.0f, 0.0f, 0.0f),  glm::vec2(1.0f, 1.0f)});
  m->vertices.push_back({glm::vec3(0.5f, -0.5f, -0.5f),  glm::vec3(1.0f, 0.0f, 0.0f),  glm::vec2(0.0f, 1.0f)});
  m->vertices.push_back({glm::vec3(0.5f, -0.5f,  0.5f),  glm::vec3(1.0f, 0.0f, 0.0f),  glm::vec2(0.0f, 0.0f)});

  // Top-face
  m->vertices.push_back({glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(0.0f, 1.0f)});
  m->vertices.push_back({glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(1.0f, 1.0f)});
  m->vertices.push_back({glm::vec3( 0.5f, -0.5f,  0.5f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(1.0f, 0.0f)});
  m->vertices.push_back({glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec2(0.0f, 0.0f)});

  // Bottom-face
  m->vertices.push_back({glm::vec3(-0.5f, 0.5f, -0.5f),  glm::vec3(0.0f, 1.0f, 0.0f),  glm::vec2(0.0f, 1.0f)});
  m->vertices.push_back({glm::vec3( 0.5f, 0.5f, -0.5f),  glm::vec3(0.0f, 1.0f, 0.0f),  glm::vec2(1.0f, 1.0f)});
  m->vertices.push_back({glm::vec3( 0.5f, 0.5f,  0.5f),  glm::vec3(0.0f, 1.0f, 0.0f),  glm::vec2(1.0f, 0.0f)});
  m->vertices.push_back({glm::vec3(-0.5f, 0.5f,  0.5f),  glm::vec3(0.0f, 1.0f, 0.0f),  glm::vec2(0.0f, 0.0f)});

  m->indices = {
    // Back-face 
    0, 1, 2, 
    2, 3, 0, 

    // Front-face 
    4, 5, 6, 
    6, 7, 4, 

    // Left-face 
    10, 9, 8, 
    8, 11, 10, 
    
    // Right-face 
    14, 13, 12, 
    12, 15, 14,

    // Top-face 
    16, 17, 18, 
    18, 19, 16, 

    // Bottom-face 
    20, 21, 22, 
    22, 23, 20, 
  };
};

static void construct_mesh_by_type(mesh* m, const mesh_type type)
{
  switch(type)
  {
    case GILG_MESH_TYPE_CUBE: 
      build_cube(m);
      break;
    case GILG_MESH_TYPE_CYLINDER:
      break;
    case GILG_MESH_TYPE_CIRCLE:
      break;
    case GILG_MESH_TYPE_PLANE:
      break;
    case GILG_MESH_TYPE_PYRAMID:
      break;
    default:
      GILG_ASSERT_MSG(false, "Unknown mesh type");
      break;
  }
}
//////////////////////////////////////////////////////////////////////

// Mesh functions
//////////////////////////////////////////////////////////////////////
mesh* load_mesh(const std::vector<vertex>& vertices, const std::vector<u32>& indices)
{
  mesh* m = new mesh;
  m->vertices = vertices;
  m->indices  = indices;

  // Setup the VAO
  m->mesh_va = create_vertex_array();
  setup_mesh_buffer(m); 

  return m;
}

mesh* load_mesh(const mesh_type type)
{
  mesh* m = new mesh;
 
  // Setup the VAO
  m->mesh_va = create_vertex_array();
  construct_mesh_by_type(m, type);
  setup_mesh_buffer(m); 

  return m;
}

void unload_mesh(mesh* m)
{
  m->vertices.clear();
  m->indices.clear();

  destroy_vertex_array(m->mesh_va);
  free_memory(m, sizeof(mesh));
}

void render_mesh(const mesh* m)
{
  gcontext_draw_index(GILG_DRAW_TRIANGLES, m->mesh_va);
}

void render_mesh(const mesh* m, const texture2d* texture)
{
  // Render the texture
  render_texture2d(texture);

  // Rendering the indices 
  gcontext_draw_index(GILG_DRAW_TRIANGLES, m->mesh_va);
}
//////////////////////////////////////////////////////////////////////

}
