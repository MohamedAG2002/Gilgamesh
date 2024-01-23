#include "graphics/backend/vertex_array.h"
#include "graphics/backend/buffer.h"
#include "core/defines.h"

#include <glad/gl.h>

#include <vector>

namespace gilg {

// Private functions
///////////////////////////////////////////////////////
u32 calculate_stride(const std::vector<layout_data_type>& layout)
{
  u32 stride = 0;

  for(int i = 0; i < layout.size(); i++)
    stride += layout[i];

  return stride;
}
///////////////////////////////////////////////////////

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

void vertex_array_push_layout(const vertex_array& va, const std::vector<layout_data_type>& layout)
{
  u32 stride = calculate_stride(layout); 

  for(int i = 0; i < layout.size(); i++)
  {
    buffer_element element;

    switch(layout[i])
    {
      case GILG_FLOAT1:
        element.size = 1;
        element.type = GL_FLOAT; 
        element.normalized = false;
        break;
      case GILG_FLOAT2:
        element.size = 2;
        element.type = GL_FLOAT; 
        element.normalized = false;
        break;
      case GILG_FLOAT3:
        element.size = 3;
        element.type = GL_FLOAT; 
        element.normalized = false;
        break;
      case GILG_FLOAT4:
        element.size = 4;
        element.type = GL_FLOAT; 
        element.normalized = false;
        break;
    }

    usizei offset = 0;
    if(i > 0)
      offset = layout[i - 1];  

    glEnableVertexAttribArray(i);
    glVertexAttribPointer(i, element.size, element.type, element.normalized, stride, (const void*)offset);
  }
}
///////////////////////////////////////////////////////

}
