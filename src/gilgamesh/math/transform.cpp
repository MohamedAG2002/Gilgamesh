#include "transform.h"
#include "core/defines.h"

#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>

namespace gilg {

// Private functions
//////////////////////////////////////////////////
void update_transform(transform& transform)
{
  glm::mat4 iden_mat(1.0f);

  transform.model = glm::translate(transform.model, transform.position) *
                    glm::rotate(transform.model, 45.0f, transform.rotation) * 
                    glm::scale(transform.model, transform.scale);
}
//////////////////////////////////////////////////

// Transform functions
//////////////////////////////////////////////////
transform create_transform(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& scale)
{
  transform trans = {
    .position = pos,
    .rotation = rot, 
    .scale    = scale,
    .model    = glm::mat4(1.0f)
  };

  trans.model = glm::translate(trans.model, trans.position);
  trans.model = glm::rotate(trans.model, 0.0f, trans.rotation);
  trans.model = glm::scale(trans.model, trans.scale);

  return trans;
}

void translate_transform(transform& transform, const glm::vec3& offset)
{
  transform.position += offset;
  update_transform(transform);
}

void rotate_transform(transform& transform, const f32 rotation_in_deg, const glm::vec3& rotation_axis)
{
  transform.rotation = rotation_axis;
  update_transform(transform);
}

void scale_transform(transform& transform, const glm::vec3& scale_factor)
{
  transform.scale = scale_factor;
  update_transform(transform);
}
//////////////////////////////////////////////////

}
