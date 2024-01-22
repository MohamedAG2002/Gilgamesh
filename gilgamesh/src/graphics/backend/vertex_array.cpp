#include "graphics/backend/vertex_array.h"
#include "graphics/backend/buffer.h"
#include "core/defines.h"

#include <glad/gl.h>

namespace gilg {

// Vertex Array functions
///////////////////////////////////////////////////////
vertex_array create_vertex_array()
{
  vertex_array va;
  va.id = 0;

  glGenVertexArrays(1, &va.id);
  glGenBuffers(1, &va.vbo.id);
  glGenBuffers(1, &va.ebo.id);

  return va;
}

void destroy_vertex_array(vertex_array& va)
{
  glDeleteVertexArrays(1, &va.id);
  glDeleteBuffers(1, &va.vbo.id);
  glDeleteBuffers(1, &va.ebo.id);
}

void bind_vertex_array(vertex_array& va)
{
  glBindVertexArray(va.id);
  glBindBuffer(GL_ARRAY_BUFFER, va.vbo.id);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, va.ebo.id);

  va.is_binded = true;
}

void unbind_vertex_array(vertex_array& va)
{
  glBindVertexArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  
  va.is_binded = false;
}

void vertex_array_push_buffer(const vertex_array& va, const buffer_desc& desc)
{
  glBufferData((u32)desc.type, desc.data.size, desc.data.data, desc.usage);
}

void vertex_array_push_layout(const vertex_array& va, u32 index, u32 comps, layout_data_type data_type, bool normalized, usizei stride, usizei offset)
{
  glEnableVertexAttribArray(index);
  glVertexAttribPointer(index, comps, data_type, normalized, stride, (const void*)offset);
}
///////////////////////////////////////////////////////

}
