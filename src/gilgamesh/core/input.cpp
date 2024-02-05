#include "input.h"
#include "gilgamesh/core/defines.h"
#include "gilgamesh/core/event.h"
#include "gilgamesh/core/logger.h"
#include "gilgamesh/core/memory_alloc.h"

namespace gilg {

// Input states
////////////////////////////////////////////////
struct key_state
{
  b8 previous_state[GILG_MAX_KEYS];
  b8 current_state[GILG_MAX_KEYS];
};

struct mouse_state
{
  b8 previous_state[GILG_MAX_BUTTONS];
  b8 current_state[GILG_MAX_BUTTONS];
};


static mouse_state s_mouse;
static key_state s_key;
////////////////////////////////////////////////

// Callbacks
////////////////////////////////////////////////
bool key_input_callback(event_type type, event_desc desc)
{
  if(type == GILG_EVENT_KEY_PRESSED)
  {
    s_key.current_state[desc.key_pressed] = true;
    return true;
  }
  else if(type == GILG_EVENT_KEY_RELEASED)
  {
    s_key.current_state[desc.key_released] = false;
    return true;
  }

  return false;
}

bool mouse_input_callback(event_type type, event_desc desc)
{
  if(type == GILG_EVENT_MOUSE_BUTTON_PRESSED)
  {
    s_mouse.current_state[desc.mouse_button_pressed] = true;
    return true;
  }
  else if(type == GILG_EVENT_MOUSE_BUTTON_RELEASED)
  {
    s_mouse.current_state[desc.mouse_button_released] = false;
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

void update_input()
{
  // Updating the keyboard state 
  copy_memory(s_key.current_state, s_key.previous_state, sizeof(s_key.current_state));

  // Updating the mouse state 
  copy_memory(s_mouse.current_state, s_mouse.previous_state, sizeof(s_mouse.current_state));
}
////////////////////////////////////////////////

// Keyboard input
////////////////////////////////////////////////
b8 is_key_down(key_code code)
{
  return s_key.current_state[code];
}

b8 is_key_up(key_code code)
{
  return !s_key.current_state[code];
}

b8 is_key_pressed(key_code code)
{
  return !s_key.previous_state[code] && s_key.current_state[code];
}

b8 is_key_released(key_code code)
{
  return s_key.previous_state[code] && !s_key.current_state[code];
}
////////////////////////////////////////////////

// Mouse input
////////////////////////////////////////////////
b8 is_mouse_down(mouse_button_code code)
{
  return s_mouse.current_state[code];
}

b8 is_mouse_up(mouse_button_code code)
{
  return !s_mouse.current_state[code];
}

b8 is_mouse_pressed(mouse_button_code code)
{
  return !s_mouse.previous_state[code] && s_mouse.current_state[code];
}

b8 is_mouse_released(mouse_button_code code)
{
  return s_mouse.previous_state[code] && !s_mouse.current_state[code];
}
////////////////////////////////////////////////

}
