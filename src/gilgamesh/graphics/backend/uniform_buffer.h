#pragma once

#include "gilgamesh/core/defines.h"
#include "gilgamesh/graphics/backend/buffer.h"

#include <glm/glm.hpp>

namespace gilg {

// Uniform Buffer struct
/////////////////////////////////////////////////////
struct uniform_buffer
{
  buffer_desc buffer;
};
/////////////////////////////////////////////////////

// Uniform Buffer functions
/////////////////////////////////////////////////////
uniform_buffer create_uniform_buffer(u32 bind_point);
void destroy_uniform_buffer(uniform_buffer& ub);
void bind_uniform_buffer(uniform_buffer& ub);
void unbind_uniform_buffer(uniform_buffer& ub);
void update_uniform_buffer(uniform_buffer& ub, usizei offset, void* data);
void uniform_buffer_upload_mat4(uniform_buffer& ub, const glm::mat4& value);
/////////////////////////////////////////////////////

}
