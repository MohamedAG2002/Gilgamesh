#pragma once

#include "gilgamesh/core/defines.h"

#include <string>

namespace gilg {

// Engine functions
//////////////////////////////////////////
b8 init_engine(const i32 width, const i32 height, const std::string& title);
void shutdown_engine();
void update_engine();
//////////////////////////////////////////

}
