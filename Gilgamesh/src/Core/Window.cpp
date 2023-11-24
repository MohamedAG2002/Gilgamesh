#include "Gilgamesh/Core/Window.hpp"
#include "Gilgamesh/GilgPCH.hpp"

#include <GLFW/glfw3.h>

namespace gilg { // beginning of gilg

Window CreateWindow(U32 width, U32 height, const std::string& title)
{
  glfwInit();
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  Window window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr); 
  GILG_ASSERT_MSG(window != NULL, "Failed to create window");

  return window;
}

bool IsWindowRunning(Window window)
{
  return !glfwWindowShouldClose(window);
}

Vec2I GetWindowSize(Window window)
{
  Vec2I size;
  
  glfwGetWindowSize(window, &size.x, &size.y);

  return size;
}

void ProcessWindowEvents()
{
  glfwPollEvents();
}

void UnloadWindow(Window window)
{
  glfwDestroyWindow(window);
  glfwTerminate();
}

} // end of gilg
