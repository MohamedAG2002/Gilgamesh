#pragma once

#include "core/defines.h"
#include "graphics/backend/buffer.h"

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
void vertex_array_push_buffer(const vertex_array& va, const buffer_desc& desc);
void vertex_array_push_layout(const vertex_array& va, u32 index, u32 comps, layout_data_type data_type, bool normalized, usizei stride, usizei offset);
///////////////////////////////////////////////////////

}
