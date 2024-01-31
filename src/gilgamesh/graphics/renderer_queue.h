#pragma once

#include "gilgamesh/graphics/backend/vertex_array.h"
#include "gilgamesh/resources/shader.h"
#include "gilgamesh/math/transform.h"

namespace gilg {

// Renderer Queue functions
//////////////////////////////////////////////////
void renderer_queue_sumbit(shader& shader, vertex_array& va, const transform& transform);
void renderer_queue_sumbit_inst(shader& shader, vertex_array& va, usizei inst_count);
void renderer_queue_flush();
//////////////////////////////////////////////////

}
