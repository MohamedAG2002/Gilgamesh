#pragma once

#include "gilgamesh/core/defines.h"

namespace gilg {

// Key types
////////////////////////////////////////////////
enum key_code 
{
  GILG_KEY_UNKNOWN       = -1, 

  GILG_KEY_SPACE         = 32,
  GILG_KEY_APOSTROPHE    = 39, 
  GILG_KEY_COMMA         = 44, 
  GILG_KEY_MINUS         = 45, 
  GILG_KEY_PERIOD        = 46, 
  GILG_KEY_SLASH         = 47, 
  GILG_KEY_0             = 48,
  GILG_KEY_1             = 49,
  GILG_KEY_2             = 50,
  GILG_KEY_3             = 51,
  GILG_KEY_4             = 52,
  GILG_KEY_5             = 53,
  GILG_KEY_6             = 54,
  GILG_KEY_7             = 55,
  GILG_KEY_8             = 56,
  GILG_KEY_9             = 57,
  GILG_KEY_SEMICOLON     = 59,
  GILG_KEY_EQUAL         = 61,
  GILG_KEY_A             = 65,
  GILG_KEY_B             = 66,
  GILG_KEY_C             = 67,
  GILG_KEY_D             = 68,
  GILG_KEY_E             = 69,
  GILG_KEY_F             = 70,
  GILG_KEY_G             = 71,
  GILG_KEY_H             = 72,
  GILG_KEY_I             = 73,
  GILG_KEY_J             = 74,
  GILG_KEY_K             = 75,
  GILG_KEY_L             = 76,
  GILG_KEY_M             = 77,
  GILG_KEY_N             = 78,
  GILG_KEY_O             = 79,
  GILG_KEY_P             = 80,
  GILG_KEY_Q             = 81,
  GILG_KEY_R             = 82,
  GILG_KEY_S             = 83,
  GILG_KEY_T             = 84,
  GILG_KEY_U             = 85,
  GILG_KEY_V             = 86,
  GILG_KEY_W             = 87,
  GILG_KEY_X             = 88,
  GILG_KEY_Y             = 89,
  GILG_KEY_Z             = 90,
  GILG_KEY_LEFT_BRACKET  = 91, 
  GILG_KEY_BACKSLASH     = 92, 
  GILG_KEY_RIGHT_BRACKET = 93, 
  GILG_KEY_GRAVE_ACCENT  = 96, 
  GILG_KEY_WORLD_1       = 161,
  GILG_KEY_WORLD_2       = 162,

  GILG_KEY_ESCAPE        = 256, 
  GILG_KEY_ENTER         = 257, 
  GILG_KEY_TAB           = 258, 
  GILG_KEY_BACKSPACE     = 259, 
  GILG_KEY_INSERT        = 260, 
  GILG_KEY_DELETE        = 261, 
  GILG_KEY_RIGHT         = 262, 
  GILG_KEY_LEFT          = 263, 
  GILG_KEY_DOWN          = 264, 
  GILG_KEY_UP            = 265, 
  GILG_KEY_PAGE_UP       = 266, 
  GILG_KEY_PAGE_DOWN     = 267, 
  GILG_KEY_HOME          = 268, 
  GILG_KEY_END           = 269, 
  GILG_KEY_CAPS_LOCK     = 280, 
  GILG_KEY_SCROLL_LOCK   = 281, 
  GILG_KEY_NUM_LOCK      = 282, 
  GILG_KEY_PRINT_SCREEN  = 283, 
  GILG_KEY_PAUSE         = 284, 
  GILG_KEY_F1            = 290, 
  GILG_KEY_F2            = 291, 
  GILG_KEY_F3            = 292, 
  GILG_KEY_F4            = 293, 
  GILG_KEY_F5            = 294, 
  GILG_KEY_F6            = 295, 
  GILG_KEY_F7            = 296, 
  GILG_KEY_F8            = 297, 
  GILG_KEY_F9            = 298, 
  GILG_KEY_F10           = 299, 
  GILG_KEY_F11           = 300, 
  GILG_KEY_F12           = 301, 
  GILG_KEY_F13           = 302, 
  GILG_KEY_F14           = 303, 
  GILG_KEY_F15           = 304, 
  GILG_KEY_F16           = 305, 
  GILG_KEY_F17           = 306, 
  GILG_KEY_F18           = 307, 
  GILG_KEY_F19           = 308, 
  GILG_KEY_F20           = 309, 
  GILG_KEY_F21           = 310, 
  GILG_KEY_F22           = 311, 
  GILG_KEY_F23           = 312, 
  GILG_KEY_F24           = 313, 
  GILG_KEY_F25           = 314, 
  GILG_KEY_KP_0          = 320, 
  GILG_KEY_KP_1          = 321, 
  GILG_KEY_KP_2          = 322, 
  GILG_KEY_KP_3          = 323, 
  GILG_KEY_KP_4          = 324, 
  GILG_KEY_KP_5          = 325, 
  GILG_KEY_KP_6          = 326, 
  GILG_KEY_KP_7          = 327, 
  GILG_KEY_KP_8          = 328, 
  GILG_KEY_KP_9          = 329, 
  GILG_KEY_KP_DECIMAL    = 330, 
  GILG_KEY_KP_DIVIDE     = 331, 
  GILG_KEY_KP_MULTIPLY   = 332, 
  GILG_KEY_KP_SUBTRACT   = 333, 
  GILG_KEY_KP_ADD        = 334, 
  GILG_KEY_KP_ENTER      = 335, 
  GILG_KEY_KP_EQUAL      = 336, 
  GILG_KEY_LEFT_SHIFT    = 340, 
  GILG_KEY_LEFT_CONTROL  = 341, 
  GILG_KEY_LEFT_ALT      = 342, 
  GILG_KEY_LEFT_SUPER    = 343, 
  GILG_KEY_RIGHT_SHIFT   = 344, 
  GILG_KEY_RIGHT_CONTROL = 345, 
  GILG_KEY_RIGHT_ALT     = 346, 
  GILG_KEY_RIGHT_SUPER   = 347, 
  GILG_KEY_MENU          = 348, 

  GILG_MAX_KEYS          = 349
};
////////////////////////////////////////////////

// Mouse button types
////////////////////////////////////////////////
enum mouse_button_code 
{
  GILG_MOUSE_BUTTON_1      = 0, 
  GILG_MOUSE_BUTTON_2      = 1, 
  GILG_MOUSE_BUTTON_3      = 2, 
  GILG_MOUSE_BUTTON_4      = 3, 
  GILG_MOUSE_BUTTON_5      = 4, 
  GILG_MOUSE_BUTTON_6      = 5, 
  GILG_MOUSE_BUTTON_7      = 6, 
  GILG_MOUSE_BUTTON_8      = 7, 
  GILG_MOUSE_BUTTON_LAST   = GILG_MOUSE_BUTTON_8,
  GILG_MOUSE_BUTTON_LEFT   = GILG_MOUSE_BUTTON_1,
  GILG_MOUSE_BUTTON_RIGHT  = GILG_MOUSE_BUTTON_2,
  GILG_MOUSE_BUTTON_MIDDLE = GILG_MOUSE_BUTTON_3,

  GILG_MAX_BUTTONS         = 8
};
////////////////////////////////////////////////

// Input functions
////////////////////////////////////////////////
b8 init_input();
void shutdown_input();
void update_input();
////////////////////////////////////////////////

// Keyboard input
////////////////////////////////////////////////
GILG_API b8 is_key_down(key_code code);
GILG_API b8 is_key_up(key_code code);
GILG_API b8 is_key_pressed(key_code code);
GILG_API b8 is_key_released(key_code code);
////////////////////////////////////////////////

// Mouse input
////////////////////////////////////////////////
GILG_API b8 is_mouse_down(mouse_button_code code);
GILG_API b8 is_mouse_up(mouse_button_code code);
GILG_API b8 is_mouse_pressed(mouse_button_code code);
GILG_API b8 is_mouse_released(mouse_button_code code);
////////////////////////////////////////////////

}
