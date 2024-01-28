#include "renderer_queue.h"
#include "graphics/backend/vertex_array.h"
#include "graphics/backend/graphics_context.h"
#include "resources/shader.h"
#include "math/transform.h"

#include <vector>

namespace gilg {

// Renderer Queue type
//////////////////////////////////////////////////
struct renderer_queue 
{
  std::vector<vertex_array> queue;
};

static renderer_queue ren_que;
//////////////////////////////////////////////////

// Renderer Queue functions
//////////////////////////////////////////////////
void renderer_queue_sumbit(shader& shader, vertex_array& va, const transform& transform)
{
  bind_shader(shader);
  set_shader_mat4(shader, "u_model", transform.model);

  gcontext_draw_vertex(GILG_DRAW_TRIANGLES, va); 
}

void renderer_queue_flush()
{
  for(auto& va : ren_que.queue)
    gcontext_draw_vertex(GILG_DRAW_TRIANGLES, va);
}
//////////////////////////////////////////////////

}
