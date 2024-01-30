#pragma once

#include "gilgamesh/core/defines.h"

#include <glm/glm.hpp>

namespace gilg {

// Transform type
//////////////////////////////////////////////////
struct transform 
{
  glm::vec3 position;
  glm::vec3 rotation;
  glm::vec3 scale;

  glm::mat4 model;
};
//////////////////////////////////////////////////

// Transform functions
//////////////////////////////////////////////////
transform create_transform(const glm::vec3& pos, const glm::vec3& rot = glm::vec3(1.0f), const glm::vec3& scale = glm::vec3(1.0f));
void translate_transform(transform& transform, const glm::vec3& offset);
void rotate_transform(transform& transform, const f32 rotation_in_deg, const glm::vec3& rotation_axis);
void scale_transform(transform& transform, const glm::vec3& scale_factor);
//////////////////////////////////////////////////

}
