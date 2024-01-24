#include "core/input.h"
#include "core/defines.h"
#include "core/event.h"
#include "core/logger.h"
#include "core/window.h"

namespace gilg {

// Input states
////////////////////////////////////////////////
struct input_state
{
  b8 keyboard_state[GILG_MAX_KEYS];
  b8 mouse_state[GILG_MAX_BUTTONS];
};

static input_state input_state;
////////////////////////////////////////////////

// Callbacks
////////////////////////////////////////////////
bool key_input_callback(event_type type, event_desc desc)
{
  if(type == GILG_EVENT_KEY_PRESSED)
  {
    input_state.keyboard_state[desc.key_pressed] = true;
    return true;
  }
  else if(type == GILG_EVENT_KEY_RELEASED)
  {
    input_state.keyboard_state[desc.key_released] = false;
    return true;
  }

  return false;
}

bool mouse_input_callback(event_type type, event_desc desc)
{
  if(type == GILG_EVENT_MOUSE_BUTTON_PRESSED)
  {
    input_state.mouse_state[desc.mouse_button_pressed] = true;
    return true;
  }
  else if(type == GILG_EVENT_MOUSE_BUTTON_RELEASED)
  {
    input_state.mouse_state[desc.mouse_button_released] = false;
    return true;
  }

  return false;
}
////////////////////////////////////////////////

// Input functions
////////////////////////////////////////////////
b8 init_input()
{
  // Listening to input events
  listen_to_event(GILG_EVENT_KEY_PRESSED, key_input_callback);
  listen_to_event(GILG_EVENT_KEY_RELEASED, key_input_callback);
  listen_to_event(GILG_EVENT_MOUSE_BUTTON_PRESSED, mouse_input_callback);
  listen_to_event(GILG_EVENT_MOUSE_BUTTON_RELEASED, mouse_input_callback);

  GILG_LOG_INFO("Input system successfully initialized");
  
  return true;
}

void shutdown_input()
{
  GILG_LOG_INFO("Input system successfully shutdown");
}
////////////////////////////////////////////////

// Keyboard input
////////////////////////////////////////////////
b8 is_key_down(key_code code)
{
  return glfwGetKey(window_handle(), code) == GLFW_PRESS;
}

b8 is_key_up(key_code code)
{
  return glfwGetKey(window_handle(), code) == GLFW_RELEASE;
}

b8 is_key_pressed(key_code code)
{
  return input_state.keyboard_state[code];
}

b8 is_key_released(key_code code)
{
  return !input_state.keyboard_state[code];
}
////////////////////////////////////////////////

// Mouse input
////////////////////////////////////////////////
b8 is_mouse_down(mouse_button_code code)
{
  return glfwGetMouseButton(window_handle(), code) == GLFW_PRESS;
}

b8 is_mouse_up(mouse_button_code code)
{
  return glfwGetMouseButton(window_handle(), code) == GLFW_RELEASE;
}

b8 is_mouse_pressed(mouse_button_code code)
{
  return input_state.mouse_state[code];
}

b8 is_mouse_released(mouse_button_code code)
{
  return !input_state.mouse_state[code];
}
////////////////////////////////////////////////

}
