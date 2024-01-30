#pragma once

#include "gilgamesh/core/defines.h"

#include <glm/glm.hpp>

namespace gilg {

// Camera type enum
////////////////////////////////////////////////////////
enum camera_type 
{
  GILG_CAM_FREE = 0, 
  GILG_CAM_FPS  = 1
};
////////////////////////////////////////////////////////

// Camera 3D type
////////////////////////////////////////////////////////
struct camera3d 
{
  f32 zoom, yaw, pitch;

  glm::vec3 position;
  glm::vec3 up_axis, right_axis, up;
  glm::vec3 direction, front;

  glm::mat4 view_projection;

  camera_type type;
};
////////////////////////////////////////////////////////

// Camera 3D functions
////////////////////////////////////////////////////////
camera3d create_camera3d(const camera_type type, const glm::vec3& pos, glm::vec3* target, f32 zoom);
void update_camera3d(camera3d& cam);
void move_camera3d(camera3d& cam);
////////////////////////////////////////////////////////

}
