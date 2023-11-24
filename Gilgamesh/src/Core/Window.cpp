#include "Gilgamesh/Core/Window.hpp"
#include "Gilgamesh/GilgPCH.hpp"

#include <GLFW/glfw3.h>

namespace gilg { // beginning of gilg

// Extern variable init 
Window window;

void CreateWindow(U32 width, U32 height, const std::string& title)
{
  glfwInit();
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
}

bool IsWindowRunning()
{
  return !glfwWindowShouldClose(window);
}

Vec2I GetWindowSize()
{
  Vec2I size;
  
  glfwGetWindowSize(window, &size.x, &size.y);

  return size;
}

void ProcessWindowEvents()
{
  glfwPollEvents();
}

void UnloadWindow()
{
  glfwDestroyWindow(window);
  glfwTerminate();
}

} // end of gilg
