#include "Gilgamesh/Core/Application.hpp"
#include "Gilgamesh/Core/Window.hpp"
#include "Gilgamesh/GilgPCH.hpp"
#include "Gilgamesh/Managers/SceneManager.hpp"
#include "Gilgamesh/Scene/Scene2D.hpp"

namespace gilg { // beginning of gilg

Application::Application(U32 width, U32 height, const std::string&& title)
{
  isRunning = true;
  lastFrame = 0.0f;
  deltaTime = 0.0f;

  // Window init 
  CreateWindow(width, height, title);
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
  RenderScenes(app.scnMgr);
}

void RunApp(Application& app)
{
  while(IsWindowRunning() && app.isRunning)
  {
    ProcessAppEvents(app);
    UpdateApp(app);
    RenderApp(app);
  }
}

void UnloadApp(Application& app)
{
  UnloadWindow();
}

} // end of gilg
