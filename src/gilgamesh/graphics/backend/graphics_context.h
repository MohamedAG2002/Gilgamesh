#pragma once

#include "core/defines.h"
#include "graphics/color.h"
#include "graphics/backend/vertex_array.h"

namespace gilg {

// Draw modes
////////////////////////////////////////////////////////////
enum draw_mode 
{
  // Lines
  GILG_DRAW_LINES                = 0x0001,
  GILG_DRAW_LINES_ADJACENCY      = 0x000A,
  GILG_DRAW_LINE_LOOP            = 0x0002,
  GILG_DRAW_LINE_STRIP           = 0x0003,
  GILG_DRAW_LINE_STRIP_ADJACENCY = 0x000B,

  // Triangles
  GILG_DRAW_TRIANGLES                = 0x0004,
  GILG_DRAW_TRIANGLES_ADJACENCY      = 0x000C,
  GILG_DRAW_TRIANGLE_FAN             = 0x0006,
  GILG_DRAW_TRIANGLE_STRIP           = 0x0005,
  GILG_DRAW_TRIANGLE_STRIP_ADJACENCY = 0x000D
};
////////////////////////////////////////////////////////////

// Graphics context functions
////////////////////////////////////////////////////////////
b8 create_gcontext();
void destroy_gcontext();
void gcontext_clear(const color& color);
void gcontext_swap();
void gcontext_draw_vertex(const draw_mode mode, vertex_array& va);
void gcontext_draw_index(const draw_mode mode, vertex_array& va);
////////////////////////////////////////////////////////////

}
