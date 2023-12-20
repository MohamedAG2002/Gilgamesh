#include "Gilgamesh/Core/Application.hpp"
#include "Gilgamesh/Core/Window.hpp"
#include "Gilgamesh/GilgPCH.hpp"

#include <GLFW/glfw3.h>

namespace gilg { // beginning of gilg

static Application s_App;

void InitApp(U32 width, U32 height, const String& title)
{
  // Variables init
  s_App.isRunning = true;
  s_App.lastFrame = 0.0f;
  s_App.deltaTime = 0.0f;

  // Init systems
  InitMemorySystem();
 
  // Create window
  s_App.window = CreateWindow(width, height, title);
}

void UpdateApp()
{
}

void RenderApp()
{
}

void RunApp()
{
  while(IsWindowRunning(s_App.window) && s_App.isRunning)
  {
    glfwPollEvents();

    UpdateApp();
    RenderApp();

    glfwSwapBuffers(s_App.window);
  }
}

void UnloadApp()
{
  UnloadWindow(s_App.window);
  UnloadMemorySystem();
}

} // end of gilg
