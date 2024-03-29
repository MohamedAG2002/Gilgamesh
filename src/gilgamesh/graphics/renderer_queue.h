#pragma once

#include "gilgamesh/graphics/backend/vertex_array.h"
#include "gilgamesh/resources/shader.h"
#include "gilgamesh/math/transform.h"

namespace gilg {

// Renderer Queue functions
//////////////////////////////////////////////////
void renderer_queue_sumbit(const shader* shader, vertex_array& va, const transform& transform);
void renderer_queue_sumbit_inst(const shader* shader, vertex_array& va, const usizei inst_count);
void renderer_queue_flush();
//////////////////////////////////////////////////

}
