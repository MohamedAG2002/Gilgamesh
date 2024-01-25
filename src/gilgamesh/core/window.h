#pragma once

#include "defines.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <string>

namespace gilg {

// Window functions
////////////////////////////////////////////////////////
b8 create_window(i32 width, i32 height, const std::string& title);
void destroy_window();
void update_window();

GILG_API void enable_cursor();
GILG_API void disable_cursor();

GILG_API b8 window_fullscreen();
GILG_API b8 window_closed();
GILG_API const f32 get_scroll();
GILG_API const f32 get_sensitivity();
GILG_API const f32 get_aspect_ratio();
GILG_API const f64 get_delta_time(); 
GILG_API const f64 get_fps();
GILG_API const glm::vec2 get_window_size();
GILG_API const glm::vec2 get_mouse_pos();
GILG_API GLFWwindow* window_handle();
GILG_API const std::string& window_title();

GILG_API void set_fullscreen(const b8 fullscreen);
GILG_API void set_vsync(const b8 vsync);
GILG_API void set_sensitivity(const f32 value);
GILG_API void window_resize(const glm::vec2 size);
GILG_API void close_window();
GILG_API void set_window_exit_key(const i32 key_code);
GILG_API void set_window_pos(const glm::vec2 pos);
GILG_API void set_mouse_pos(const glm::vec2 pos);
GILG_API void set_window_title(const std::string& title);
////////////////////////////////////////////////////////

}
