#pragma once

#include "graphics/camera3d.h"
#include "graphics/color.h"

namespace gilg {

// Renderer functions
///////////////////////////////////////////////////////
b8 create_renderer();
void destroy_renderer();

void clear_renderer(const color& color);
void begin_renderer(const camera3d& cam);
void end_renderer();
///////////////////////////////////////////////////////

}
