#include "camera3d.h"
#include "core/window.h"
#include "core/input.h"

#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>

namespace gilg {

// Globals
////////////////////////////////////////////////////////
const f32 CAM_MAX_DEG = 89.0f;
const f32 CAM_MAX_ZOOM = 180.0f;
const f32 CAM_SPEED = 10.0f;
////////////////////////////////////////////////////////

// Private functions
////////////////////////////////////////////////////////
void move_free_cam(camera3d& cam, f32 speed)
{ 
  // Move right
  if(is_key_down(GILG_KEY_D))
    cam.position += glm::normalize(glm::cross(cam.front, cam.up)) * speed;
  // Move left
  else if(is_key_down(GILG_KEY_A))
    cam.position -= glm::normalize(glm::cross(cam.front, cam.up)) * speed;
 
  // Move forwards/up
  if(is_key_down(GILG_KEY_W))
    cam.position += cam.front * speed;
  // Move backwards/down
  else if(is_key_down(GILG_KEY_S))
    cam.position -= cam.front * speed;
}

void move_fps_cam(camera3d& cam, f32 speed)
{
  move_free_cam(cam, speed);

  cam.position.y = 0.0f;
}
////////////////////////////////////////////////////////

// Camera 2D functions
////////////////////////////////////////////////////////
camera3d create_camera3d(const camera_type type, const glm::vec3& pos, glm::vec3* target, f32 zoom)
{
  camera3d cam;
  glm::vec3 look_dir = glm::normalize(pos - *target);

  cam.zoom = zoom;
  cam.yaw = -90.0f;
  cam.pitch = 0.0f;

  cam.position = pos;
  
  cam.up_axis = glm::vec3(0.0f, 1.0f, 0.0f);
  cam.right_axis = glm::normalize(glm::cross(cam.up_axis, look_dir));
  cam.up = glm::normalize(glm::cross(look_dir, cam.right_axis));

  cam.direction.x = glm::cos(glm::radians(cam.yaw)) * glm::cos(glm::radians(cam.pitch));
  cam.direction.y = glm::sin(glm::radians(cam.pitch));
  cam.direction.z = glm::sin(glm::radians(cam.yaw)) * glm::cos(glm::radians(cam.pitch));
  cam.front = glm::normalize(cam.direction);

  cam.projection = glm::mat4(1.0f);
  cam.view = glm::mat4(1.0f);
  
  cam.type = type;

  return cam;
}

void update_camera3d(camera3d& cam)
{
  // Getting values from the window
  f32 aspect_ratio = get_aspect_ratio();
  glm::vec2 mouse_pos = get_mouse_pos();

  // Updating the projection and view matrices
  cam.view = glm::lookAt(cam.position, cam.position + cam.front, cam.up);  
  cam.projection = glm::perspective(glm::radians(cam.zoom), aspect_ratio, 0.1f, 100.0f);
  
  // Updating the yaw and pitch values
  cam.yaw = mouse_pos.x;
  cam.pitch = mouse_pos.y;
  
  // Clamping the pitch and zoom values to not get crazy values
  cam.pitch = glm::clamp(cam.pitch, -CAM_MAX_DEG, CAM_MAX_DEG);
  cam.zoom = glm::clamp(cam.zoom, 1.0f, CAM_MAX_ZOOM);

  // Updating the front of the camera based on the yaw and pitch values
  cam.direction.x = cos(glm::radians(cam.yaw)) * cos(glm::radians(cam.pitch));
  cam.direction.y = sin(glm::radians(cam.pitch));
  cam.direction.z = sin(glm::radians(cam.yaw)) * cos(glm::radians(cam.pitch));
  cam.front = glm::normalize(cam.direction);

  printf("Camera Position = {.x = %f, .y = %f, .z = %f}\n", cam.position.x, cam.position.y, cam.position.z);
}

void move_camera3d(camera3d& cam)
{
  f32 delta_speed = CAM_SPEED * get_delta_time();

  switch(cam.type)
  {
    case GILG_CAM_FREE:
      move_free_cam(cam, delta_speed);
      break;
    case GILG_CAM_FPS:
      move_fps_cam(cam, delta_speed);
      break;
  }
}
////////////////////////////////////////////////////////

}
