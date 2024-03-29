#pragma once

#include "gilgamesh/core/defines.h"
#include "gilgamesh/graphics/color.h"
#include "gilgamesh/resources/texture2d.h"

#include <glm/glm.hpp>

namespace gilg {

// Render stats struct
/////////////////////////////////////////////////
struct render_stats 
{
  usizei total_quads = 0;
  usizei draw_calls  = 0;
};
/////////////////////////////////////////////////

// Consts 
/////////////////////////////////////////////////
const usizei MAX_QUADS    = 10000;
const usizei MAX_VERTICES = MAX_QUADS * 4;
const usizei MAX_INDICES  = MAX_QUADS * 6;
const usizei MAX_TEXTURES = 32; // @TODO: Probably should query the driver for the max textures instead of assuming
/////////////////////////////////////////////////

// Renderer2D functions 
/////////////////////////////////////////////////
b8 create_renderer2d();
void destroy_renderer2d();
void begin_renderer2d();
void flush_renderer2d();
void end_renderer2d();

void render_quad(const glm::vec2& pos, const glm::vec2& size, const color& color);
void render_quad(const glm::vec2& pos, const glm::vec2& size, texture2d* texture, const color tint = color(1.0f));

// @TODO: Future API 
// void render_circle(pos, radius, color);
// void render_polygon(pos, radius, sides/poly_count, color);

const render_stats& get_renderer2d_stats();
void reset_renderer2d_stats();
/////////////////////////////////////////////////

}
