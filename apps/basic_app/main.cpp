#include <gilgamesh.h>

#include <cstdio>

struct game 
{
  int width, height;
  std::string title;

  glm::vec3 target;
  gilg::camera3d cam;
  gilg::color background_color;
  bool show_editor;
};

game init_game();
void update_game(game& game);
void render_game(game& game);
void render_game_gui(game& game, const gilg::render_data& data);
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
  game.background_color = gilg::color(0.1f, 0.1f, 0.1f, 1.0f);

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
  gilg::render_data ren_dat = {
    .cam = &game.cam, 
  };

  gilg::begin_renderer(ren_dat);
  gilg::clear_renderer(game.background_color);

  if(game.show_editor)
    render_game_gui(game, ren_dat);

  gilg::end_renderer();
}

void render_game_gui(game& game)
{
  gilg::editor_begin();
  gilg::enable_cursor();

  gilg::editor_end();
}

void shutdown_game(game& game)
{
  gilg::editor_shutdown();
  gilg::shutdown_engine();
}
