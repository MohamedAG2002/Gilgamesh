#pragma once

#include "core/defines.h"
#include "graphics/renderer.h"

#include <string>

namespace gilg {

// App functions
///////////////////////////////////////////////
GILG_API void create_app(const i32 window_width, const i32 window_height, const std::string& window_title);
GILG_API void destroy_app();
GILG_API void run_app();
///////////////////////////////////////////////

}

