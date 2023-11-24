#include "Gilgamesh/Core/Application.hpp"
#include "Gilgamesh/Core/Window.hpp"
#include "Gilgamesh/Graphics/Renderer2D.hpp"
#include "Gilgamesh/Graphics/Color.hpp"
#include "Gilgamesh/GilgPCH.hpp"
#include "Gilgamesh/Managers/SceneManager.hpp"
#include "Gilgamesh/Scene/Scene2D.hpp"

namespace gilg { // beginning of gilg

Application::Application(U32 width, U32 height, const std::string&& title)
{
  isRunning = true;
  lastFrame = 0.0f;
  deltaTime = 0.0f;

  window = CreateWindow(width, height, title);
  
}

void ProcessAppEvents(Application& app)
{
  ProcessWindowEvents();
}

void UpdateApp(Application& app)
{
  UpdateScenes(app.scnMgr, app.deltaTime);
}

void RenderApp(Application& app)
{
  Render2DClear(app.renderer, Color::Black);
  Render2DBegin(app.renderer);

  RenderScenes(app.scnMgr);

  Render2DEnd(app.renderer);
}

void RunApp(Application& app)
{
  while(IsWindowRunning(app.window) && app.isRunning)
  {
    ProcessAppEvents(app);
    UpdateApp(app);
    RenderApp(app);
  }
}

void UnloadApp(Application& app)
{
  UnloadRender2D(app.renderer);
  UnloadWindow(app.window);
}

} // end of gilg
