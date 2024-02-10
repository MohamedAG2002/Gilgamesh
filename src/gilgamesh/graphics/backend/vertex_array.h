#pragma once

#include "gilgamesh/core/defines.h"
#include "gilgamesh/graphics/backend/buffer.h"

#include <vector>

namespace gilg {

// Macros
///////////////////////////////////////////////////////

// Takes the given data and the size of it to be used later
#define GILG_BUFFER_DATA(data) buffer_data{data, sizeof(data)}

// Allocates the of size of T N times in the GPU. The data will be empty. 
// This should only be used when GILG_BUFF_USAGE_DYNAMIC or GILG_BUFF_USAGE_STREAM
// are used. 
#define GILG_BUFFER_ALLOC(t, n) buffer_data{nullptr, sizeof(t) * n}
///////////////////////////////////////////////////////

// Vertex Array type
///////////////////////////////////////////////////////
struct vertex_array
{
  u32 id;
  buffer_desc vertex_buffer, index_buffer, inst_buffer;
};
///////////////////////////////////////////////////////

// Vertex Array functions
///////////////////////////////////////////////////////
vertex_array create_vertex_array();
void destroy_vertex_array(vertex_array& va);
void bind_vertex_array(const vertex_array& va);
void unbind_vertex_array(const vertex_array& va);
void vertex_array_push_buffer(vertex_array& va, buffer_desc& desc);
void vertex_array_push_layout(const vertex_array& va, const std::vector<layout_data_type>& layout, bool is_inst);
void vertex_array_update_buffer(const vertex_array& va, const u32 buff_type, usizei offset, const usizei size, const void* data);
///////////////////////////////////////////////////////

}
