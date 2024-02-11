#include "game.h"

#include "gilgamesh/gilgamesh.h"

// Globals
///////////////////////
game game;
static glm::vec3 pos;
const float CUBE_SPEED = 20.0f;
///////////////////////

// Game functions
///////////////////////
void init_game()
{
  gilg::set_vsync(false);

  game.target = glm::vec3(0.0f, 0.0f, -3.0f);
  game.cam = gilg::create_camera3d(gilg::GILG_CAM_FREE, glm::vec3(-10.0f, 0.0f, 10.0f), &game.target, 45.0f); 
 
  game.render_data.cam = &game.cam;
  game.render_data.clear_color = gilg::color(0.1f, 0.1f, 0.1f, 1.0f);

  game.cube_pos = gilg::create_transform(glm::vec3(-3.0f, 0.0f, .0f));
  game.quad_pos = glm::vec2(-0.5f, 0.5f);
  game.quad_size = glm::vec2(1.0f, 1.0f);
  game.quad_color = gilg::GILG_COLOR_WHITE;
  
  gilg::resource_add_texture("container", "assets/textures/container.jpg");
  game.texture = gilg::resource_get_texture("container");

  gilg::resource_add_texture("grass", "assets/textures/grass.png");
  game.grass_texture = gilg::resource_get_texture("grass");
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

  for(int y = 0; y < 10; y++)
  {
    for(int x = 0; x < 10; x++)
    {
      gilg::transform model = gilg::create_transform(glm::vec3(y * 2.0f, 0.0f, x * 2.0f));
      gilg::render_cube(model, game.texture);
    }
  }

  render_game_gui();
  gilg::end_renderer();

  // Just for diagnostics
  gilg::reset_renderer2d_stats();
}

void render_game_gui()
{
  if(!game.show_editor)
  {
    gilg::disable_cursor();
    return;
  }

  gilg::enable_cursor();
  gilg::editor_begin();

  gilg::editor_debug_info();
  gilg::editor_renderer_info(game.render_data);
  gilg::editor_camera_panel(game.cam); 
  gilg::editor_entities_panel(game.quad_pos, game.quad_size, game.quad_color);

  gilg::editor_end();
}

void shutdown_game()
{
}
///////////////////////
