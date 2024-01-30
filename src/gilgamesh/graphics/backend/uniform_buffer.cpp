#include "uniform_buffer.h"
#include "gilgamesh/core/defines.h"
#include "gilgamesh/graphics/backend/buffer.h"

#include <glad/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace gilg {

// Uniform Buffer functions
/////////////////////////////////////////////////////
uniform_buffer create_uniform_buffer(u32 bind_point)
{
  uniform_buffer ub; 
  ub.buffer.id = 0; 
  ub.buffer.type = GILG_BUFF_TYPE_UNIFORM;
  
  glGenBuffers(1, &ub.buffer.id);
  
  glBindBuffer(ub.buffer.type, ub.buffer.id);
  glBufferData(ub.buffer.type, sizeof(float) * 1024, nullptr, GL_DYNAMIC_DRAW);
  glBindBuffer(ub.buffer.type, 0);
  
  glBindBufferBase(ub.buffer.type, bind_point, ub.buffer.id);

  return ub;
}

void destroy_uniform_buffer(uniform_buffer& ub)
{
  glDeleteBuffers(1, &ub.buffer.id);
}

void bind_uniform_buffer(uniform_buffer& ub)
{
  glBindBuffer(ub.buffer.type, ub.buffer.id);
}

void unbind_uniform_buffer(uniform_buffer& ub)
{
  glBindBuffer(ub.buffer.type, 0);
}

void uniform_buffer_upload_mat4(uniform_buffer& ub, const glm::mat4& value)
{
  glBufferSubData(ub.buffer.type, 0, sizeof(glm::mat4), glm::value_ptr(value));
}
/////////////////////////////////////////////////////

}
