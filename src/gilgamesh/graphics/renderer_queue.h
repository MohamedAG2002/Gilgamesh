#pragma once

#include "graphics/backend/vertex_array.h"
#include "resources/shader.h"
#include "math/transform.h"

namespace gilg {

// Renderer Queue functions
//////////////////////////////////////////////////
void renderer_queue_sumbit(shader& shader, vertex_array& va, const transform& transform);
void renderer_queue_flush();
//////////////////////////////////////////////////

}
