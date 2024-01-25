#pragma once

#include "graphics/backend/vertex_array.h"

namespace gilg {

// Renderer Queue functions
//////////////////////////////////////////////////
void renderer_queue_sumbit(vertex_array& va);
void renderer_queue_flush();
//////////////////////////////////////////////////

}
