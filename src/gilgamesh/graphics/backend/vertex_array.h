#pragma once

#include "core/defines.h"
#include "graphics/backend/buffer.h"

#include <vector>

namespace gilg {

// Macros
///////////////////////////////////////////////////////
#define GILG_BUFFER_DATA(data) buffer_data{data, sizeof(data)}
///////////////////////////////////////////////////////

// Vertex Array type
///////////////////////////////////////////////////////
struct vertex_array
{
  u32 id;
  buffer_desc vbo, ebo;
  b8 is_binded;
};
///////////////////////////////////////////////////////

// Vertex Array functions
///////////////////////////////////////////////////////
vertex_array create_vertex_array();
void destroy_vertex_array(vertex_array& va);
void bind_vertex_array(vertex_array& va);
void unbind_vertex_array(vertex_array& va);
void vertex_array_push_buffer(vertex_array& va, const buffer_desc& desc);
void vertex_array_push_layout(const vertex_array& va, const std::vector<layout_data_type>& layout);
///////////////////////////////////////////////////////

}
