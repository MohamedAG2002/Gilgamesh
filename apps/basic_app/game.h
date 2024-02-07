#pragma once

#include "gilgamesh/gilgamesh.h"

struct game 
{
  glm::vec3 target;
  gilg::camera3d cam;
  gilg::render_data render_data;
  bool show_editor;

  gilg::transform cube_pos;

  glm::vec2 quad_pos, quad_size;
  gilg::color quad_color;
  gilg::texture2d* texture, *grass_texture;
};

void init_game();
void update_game();
void render_game();
void render_game_gui();
void shutdown_game();
