#include "game.h"

#include "gilgamesh/gilgamesh.h"

// Globals
///////////////////////
game game;
///////////////////////

// Game functions
///////////////////////
void init_game()
{
  // Editor init 
  if(!gilg::editor_init())
    printf("ERROR: failed to create the editor\n");

  game.target = glm::vec3(0.0f, 0.0f, -3.0f);
  game.cam = gilg::create_camera3d(gilg::GILG_CAM_FREE, glm::vec3(-10.0f, 0.0f, 10.0f), &game.target, 45.0f); 
 
  game.render_data.cam = &game.cam;
  game.render_data.clear_color = gilg::color(0.1f, 0.1f, 0.1f, 1.0f);
}

void update_game()
{
  if(!game.show_editor)
    gilg::update_camera3d(game.cam);
  gilg::move_camera3d(game.cam);

  if(gilg::is_key_pressed(gilg::GILG_KEY_F5))
    game.show_editor = !game.show_editor;
}

void render_game()
{
  gilg::begin_renderer(game.render_data);
  gilg::clear_renderer(game.render_data.clear_color);

  if(game.show_editor)
  {
    render_game_gui();
    gilg::enable_cursor();
  }
  else 
    gilg::disable_cursor();

  gilg::end_renderer();
}

void render_game_gui()
{
  gilg::editor_begin();

  gilg::editor_info_window(game.render_data);
  gilg::editor_camera_panel(game.cam); 

  gilg::editor_end();
}

void shutdown_game()
{

}
///////////////////////
