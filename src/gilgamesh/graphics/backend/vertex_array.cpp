#include "vertex_array.h"
#include "gilgamesh/graphics/backend/buffer.h"
#include "gilgamesh/core/defines.h"
#include "gilgamesh/core/logger.h"

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

buffer_element get_buffer_element_by_type(layout_data_type type)
{
  buffer_element element; 

  switch(type)
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
    default:
      GILG_LOG_ERROR("Failed to deduce layout type");
      break;
  }

  return element;
}
///////////////////////////////////////////////////////

// Vertex Array functions
///////////////////////////////////////////////////////
vertex_array create_vertex_array()
{
  vertex_array va;
  va.id = 0;

  glGenVertexArrays(1, &va.id);

  return va;
}

void destroy_vertex_array(vertex_array& va)
{
  glDeleteVertexArrays(1, &va.id);
 
  // Delete all the buffers
  glDeleteBuffers(1, &va.vertex_buffer.id);
  glDeleteBuffers(1, &va.index_buffer.id);
  glDeleteBuffers(1, &va.inst_buffer.id);
}

void bind_vertex_array(vertex_array& va)
{
  glBindVertexArray(va.id);

  va.is_binded = true;
}

void unbind_vertex_array(vertex_array& va)
{
  glBindVertexArray(0);
  
  va.is_binded = false;
}

void vertex_array_push_buffer(vertex_array& va, buffer_desc& desc)
{                                                
  // Making sure to bind the correct buffer      
  switch(desc.type) 
  {
    case GILG_BUFF_TYPE_VERTEX:
      va.vertex_buffer = desc;
      glGenBuffers(1, &va.vertex_buffer.id);
      glBindBuffer(GL_ARRAY_BUFFER, va.vertex_buffer.id);
    break; 

    case GILG_BUFF_TYPE_INDEX:
      va.index_buffer = desc;
      glGenBuffers(1, &va.index_buffer.id);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, va.index_buffer.id);
    break;

    case GILG_BUFF_TYPE_INSTANCE:
      desc.type = GILG_BUFF_TYPE_VERTEX; // @TODO: This is not good fix it 
      va.inst_buffer = desc;
      glGenBuffers(1, &va.inst_buffer.id);
      glBindBuffer(GL_ARRAY_BUFFER, va.inst_buffer.id);
    break;

    case GILG_BUFF_TYPE_UNIFORM:
      printf("WHAT?!!!\n");
    break;
  }

  // Setting the data of the binded buffer
  glBufferData((u32)desc.type, desc.data.size, desc.data.data, desc.usage);
}

void vertex_array_push_layout(const vertex_array& va, const std::vector<layout_data_type>& layout, bool is_inst)
{
  u32 index_mul = 0; 
  usizei offset = 0;
  u32 stride = calculate_stride(layout); 
  
  if(is_inst)
    index_mul = 2;

  glBindVertexArray(va.id); 

  for(int i = 0; i < layout.size(); i++)
  {
    buffer_element element = get_buffer_element_by_type(layout[i]);
    u32 index = i + index_mul;

    if(i > 0)
      offset += layout[i - 1];  

    glEnableVertexAttribArray(index);
    glVertexAttribPointer(index, element.size, element.type, element.normalized, stride, (void*)offset);
  
    if(is_inst)
      glVertexAttribDivisor(index, 1);
  }
}

void vertex_array_update_buffer(const vertex_array& va, const u32 buff_type, usizei offset, const usizei size, const void* data)
{
  glBindVertexArray(va.id);
  glBindBuffer(va.inst_buffer.type, va.inst_buffer.id);
  glBufferSubData(va.inst_buffer.type, offset, size, data);
}
///////////////////////////////////////////////////////

}
