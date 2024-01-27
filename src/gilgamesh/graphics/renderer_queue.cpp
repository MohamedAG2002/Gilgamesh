#include "renderer_queue.h"
#include "graphics/backend/vertex_array.h"
#include "graphics/backend/graphics_context.h"

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
void renderer_queue_sumbit(vertex_array& va)
{
  //ren_que.queue.push_back(va); 

  gcontext_draw_vertex(GILG_DRAW_TRIANGLES, va); 
}

void renderer_queue_flush()
{
  for(auto& va : ren_que.queue)
    gcontext_draw_vertex(GILG_DRAW_TRIANGLES, va);
}
//////////////////////////////////////////////////

}
