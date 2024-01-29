#include <gilgamesh.h>

#include <cstdio>

struct game 
{
  int width, height;
  std::string title;

  glm::vec3 target;
  gilg::camera3d cam;
  gilg::render_data render_data;
  bool show_editor;
};

game init_game();
void update_game(game& game);
void render_game(game& game);
void render_game_gui(game& game);
void shutdown_game(game& game);

int main()
{
  game some_game = init_game();

  while(!gilg::window_closed())
  {
    update_game(some_game);
    render_game(some_game);
  }

  shutdown_game(some_game);
}

game init_game()
{
  game game;
  game.width = 800;
  game.height = 600;
  game.title = "Gilgamesh Engine";

  // Engine init
  if(!gilg::init_engine(game.width, game.height, game.title))
    printf("ERROR: failed to create engine\n");
 
  // Editor init 
  if(!gilg::editor_init())
    printf("ERROR: failed to create the editor\n");

  game.target = glm::vec3(0.0f, 0.0f, -3.0f);
  game.cam = gilg::create_camera3d(gilg::GILG_CAM_FREE, glm::vec3(-10.0f, 0.0f, -4.0f), &game.target, 45.0f); 
 
  game.render_data.cam = &game.cam;
  game.render_data.clear_color = gilg::color(0.1f, 0.1f, 0.1f, 1.0f);

  return game;
}

void update_game(game& game)
{
  gilg::update_engine();

  if(!game.show_editor)
    gilg::update_camera3d(game.cam);
  gilg::move_camera3d(game.cam);

  if(gilg::is_key_pressed(gilg::GILG_KEY_F5))
    game.show_editor = !game.show_editor;
}

void render_game(game& game)
{
  gilg::begin_renderer(game.render_data);
  gilg::clear_renderer(game.render_data.clear_color);

  if(game.show_editor)
  {
    render_game_gui(game);
    gilg::enable_cursor();
  }
  else 
    gilg::disable_cursor();

  gilg::end_renderer();
}

void render_game_gui(game& game)
{
  gilg::editor_begin();

  gilg::editor_info_window(game.render_data);
  gilg::editor_camera_panel(game.cam); 

  gilg::editor_end();
}

void shutdown_game(game& game)
{
  gilg::editor_shutdown();
  gilg::shutdown_engine();
}
