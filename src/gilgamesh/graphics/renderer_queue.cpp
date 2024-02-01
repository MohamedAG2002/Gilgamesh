#include "renderer_queue.h"
#include "gilgamesh/graphics/backend/vertex_array.h"
#include "gilgamesh/graphics/backend/graphics_context.h"
#include "gilgamesh/resources/shader.h"
#include "gilgamesh/math/transform.h"

namespace gilg {

// Renderer Queue functions
//////////////////////////////////////////////////
void renderer_queue_sumbit(shader& shader, vertex_array& va, const transform& transform)
{
  bind_shader(shader);
  set_shader_mat4(shader, "u_model", transform.model); 

  gcontext_draw_vertex(GILG_DRAW_TRIANGLES, va); 
}

void renderer_queue_sumbit_inst(shader& shader, vertex_array& va, usizei inst_count)
{
  bind_shader(shader);
  gcontext_draw_vertex_inst(GILG_DRAW_TRIANGLES, va, inst_count);
}

void renderer_queue_flush()
{
  // Does nothing for now...
}
//////////////////////////////////////////////////

}
