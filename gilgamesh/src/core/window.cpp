#include "window.h"
#include "defines.h"
#include "gilg_asserts.h"
#include "logger.h"

#include <GLFW/glfw3.h>
#include <glad/gl.h>
#include <glm/glm.hpp>

#include <string>

// Globals 
/////////////////////////////////
glm::vec2 last_mouse_pos;
/////////////////////////////////

namespace gilg {

// Window struct
/////////////////////////////////
struct window
{
  b8 is_fullscreen;

  i32 frame_count;
  f32 scroll_val, sensitivity;

  f64 last_frame, delta_time;
  f64 prev_time, curr_time, fps; 

  glm::vec2 size, mouse_pos;
  
  GLFWwindow* handle;

  std::string title;
}; 

static window window;
/////////////////////////////////

// Callbacks
////////////////////////////////////////////
void mouse_callback(GLFWwindow* win, f64 x_pos, f64 y_pos)
{
  glm::vec2 offset = glm::vec2(x_pos - window.mouse_pos.x, window.mouse_pos.y - y_pos);
  glm::vec2 last_mouse_pos = glm::vec2(x_pos, y_pos);

  // Adding the sensitivity 
  offset *= window.sensitivity;

  // Adding the offset to the current mouse position to get the current position
  window.mouse_pos += offset;
}

void scroll_callback(GLFWwindow* win, f64 x_off, f64 y_off)
{
  window.scroll_val = (f32)y_off;
}

void frame_buffer_resize_callback(GLFWwindow* win, i32 width, i32 height)
{
  window.size = glm::vec2(width, height);

  glViewport(0, 0, width, height);
}

void key_callback(GLFWwindow* win, i32 key, i32 scancode, i32 action, i32 mods)
{
  if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(win, true);
}

void error_callback(i32 err_code, const char* desc)
{
  GILG_LOG_FATAL("GLFW-ERROR %i: %s", err_code, desc);
}
////////////////////////////////////////////

// Window functions
////////////////////////////////////////////////////////
b8 create_window(i32 width, i32 height, const std::string& title)
{
  // GLFW init and window hints
  /////////////////////////////////////////////////////////////
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Setting the error callback to catch any errors prior
  glfwSetErrorCallback(error_callback);
  /////////////////////////////////////////////////////////////
  
  // Variables init
  /////////////////////////////////////////////////////////////
  window.mouse_pos = last_mouse_pos;
  window.scroll_val = 0.0f;
  window.sensitivity = 0.1f;
  window.is_fullscreen = false;
  window.size = glm::vec2(width, height);
  last_mouse_pos = glm::vec2(window.size.x / 2.0f, window.size.y / 2.0f);
  /////////////////////////////////////////////////////////////
  
  // Create window and check for errors
  ////////////////////////////////////////////////////////////////////
  window.handle = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
  if(window.handle == NULL)
    return false;

  glfwMakeContextCurrent(window.handle); 
  ////////////////////////////////////////////////////////////////////
  
  // Setting window callbacks
  ////////////////////////////////////////////////////////////////////
  glfwSetCursorPosCallback(window.handle, mouse_callback);
  glfwSetScrollCallback(window.handle, scroll_callback);
  glfwSetFramebufferSizeCallback(window.handle, frame_buffer_resize_callback);
  glfwSetKeyCallback(window.handle, key_callback);
  ////////////////////////////////////////////////////////////////////

  return true;
}

void destroy_window()
{
  glfwDestroyWindow(window.handle);
  glfwTerminate();
}

void update_window()
{ 
  // Calculate delta time
  //////////////////////////////////////////////////
  window.delta_time = glfwGetTime() - window.last_frame;
  window.last_frame = glfwGetTime();
  //////////////////////////////////////////////////
  
  // Calculate FPS
  //////////////////////////////////////////////////
  window.frame_count++;
  window.curr_time = glfwGetTime();

  if((window.curr_time - window.prev_time) >= 1.0f)
  {
    window.fps = window.frame_count;
    window.frame_count = 0;
    window.prev_time = window.curr_time;
  }
  //////////////////////////////////////////////////

  // Necessary steps to do every frame
  //////////////////////////////////////////////////
  glfwPollEvents();
  //////////////////////////////////////////////////
}

void enable_cursor()
{
  glfwSetInputMode(window.handle, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}

void disable_cursor()
{
  glfwSetInputMode(window.handle, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
}

b8 window_fullscreen()
{
  return window.is_fullscreen;
}

b8 window_closed()
{
  return glfwWindowShouldClose(window.handle);
}

const f32 scroll()
{
  return window.scroll_val;
}

const f32 sensitivity()
{
  return window.sensitivity;
}

const f32 aspect_ratio()
{
  return window.size.x / window.size.y;
}

const f64 delta_time()
{
  return window.delta_time;
}

const f64 fps()
{
  return window.fps;
}

const glm::vec2 window_size()
{
  return window.size;
}

const glm::vec2 mouse_pos()
{
  return window.mouse_pos;
}

GLFWwindow* window_handle()
{
  return window.handle;
}

const std::string& window_title()
{
  return window.title;
}

void set_fullscreen(const b8 fullscreen)
{
  window.is_fullscreen = fullscreen;

  window.handle = glfwCreateWindow(window.size.x, window.size.y, window.title.c_str(), glfwGetPrimaryMonitor(), NULL);
  GILG_ASSERT_MSG(window.handle != NULL, "Failed to make window fullscreen");

  i32 width, height;
  glfwGetFramebufferSize(window.handle, &width, &height);
  glViewport(0, 0, width, height);
}

void set_vsync(const b8 vsync)
{
  glfwSwapInterval(vsync);
}

void set_sensitivity(const f32 value)
{
  window.sensitivity = value;
}

void window_resize(const glm::vec2 size)
{
  window.size = size;

  glfwSetWindowSize(window.handle, size.x, size.y);
  glViewport(0, 0, size.x, size.y);
}

void set_window_pos(const glm::vec2 pos)
{
  glfwSetWindowPos(window.handle, pos.x, pos.y);
}

void set_mouse_pos(const glm::vec2 pos)
{
  window.mouse_pos = pos;

  glfwSetCursorPos(window.handle, pos.x, pos.y);
}

void set_window_title(const std::string& title)
{
  window.title = title;

  glfwSetWindowTitle(window.handle, title.c_str());
}
////////////////////////////////////////////////////////

}
