#pragma once

#include "gilgamesh/core/defines.h"
#include "gilgamesh/resources/texture2d.h"
#include "gilgamesh/math/vertex.h"
#include "gilgamesh/graphics/backend/vertex_array.h"

#include <vector>

namespace gilg {

// Mesh type enum
//////////////////////////////////////////////////////////////////////
enum mesh_type 
{
  GILG_MESH_TYPE_CUBE     = 0, 
  GILG_MESH_TYPE_CYLINDER = 1,
  GILG_MESH_TYPE_CIRCLE   = 2,
  GILG_MESH_TYPE_PLANE    = 3,
  GILG_MESH_TYPE_PYRAMID  = 4,
};
//////////////////////////////////////////////////////////////////////

// Mesh Desc struct
//////////////////////////////////////////////////////////////////////
struct mesh_desc 
{
  std::vector<vertex> vertices;
  std::vector<u32>    indices;
  texture2d*          texture; 
};
//////////////////////////////////////////////////////////////////////

// Mesh struct
//////////////////////////////////////////////////////////////////////
struct mesh 
{
  std::vector<vertex> vertices; 
  std::vector<u32>    indices;
  texture2d*          texture;
  vertex_array        mesh_va;
};
//////////////////////////////////////////////////////////////////////

// Mesh functions
//////////////////////////////////////////////////////////////////////
mesh* load_mesh(const mesh_desc& desc);
mesh* load_mesh(const mesh_type type);
void unload_mesh(mesh* m);
void render_mesh(const mesh* m);
//////////////////////////////////////////////////////////////////////

}
