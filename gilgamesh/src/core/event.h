#pragma once

#include "core/defines.h"

#include <glm/glm.hpp>

namespace gilg {

// Event types
//////////////////////////////////////////////
enum event_type 
{
  GILG_EVENT_APP_QUIT = 0,
  
  GILG_EVENT_KEY_PRESSED  = 1,
  GILG_EVENT_KEY_RELEASED = 2,

  GILG_EVENT_MOUSE_BUTTON_PRESSED  = 3,
  GILG_EVENT_MOUSE_BUTTON_RELEASED = 4,
  GILG_EVENT_MOUSE_MOVED           = 5,
  GILG_EVENT_MOUSE_SCROLL_WHEEL    = 6, 

  GILG_EVENT_WINDOW_CLOSED  = 7,
  GILG_EVENT_WINDOW_RESIZED = 8,
  GILG_EVENT_WINDOW_MOVED   = 9
};
//////////////////////////////////////////////

// Event Description
//////////////////////////////////////////////
struct event_desc 
{
  u16 key_pressed, key_released;
  u16 mouse_button_pressed, mouse_button_released;

  f32 scroll_value;

  glm::vec2 mouse_pos;
  glm::vec2 window_size;
};
//////////////////////////////////////////////

// The event function pointer
//////////////////////////////////////////////
typedef bool (*event_func)(event_type, event_desc);
//////////////////////////////////////////////

// Event functions
//////////////////////////////////////////////
bool init_events();
void shutdown_events();
void listen_to_event(event_type type, event_func func);
bool dispatch_event(event_type type, event_desc desc);
////////////////////////////////////////////// 

}
