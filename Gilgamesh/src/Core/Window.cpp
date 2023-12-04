#include "Gilgamesh/Core/Window.hpp"
#include "Gilgamesh/GilgPCH.hpp"
#include "Gilgamesh/Input/KeyCode.hpp"

#include <GLFW/glfw3.h>

#include <iostream>

namespace gilg { // beginning of gilg

Window CreateWindow(U32 width, U32 height, const String& title)
{
  glfwInit();
  
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  Window window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr); 
  GILG_ASSERT_MSG(window != nullptr, "Failed to create window");

  glfwSetFramebufferSizeCallback(window, _FrameResizeCallback);
  glfwSetKeyCallback(window, _KeyCallback);

  return window;
}

bool IsWindowRunning(Window window)
{
  return !glfwWindowShouldClose(window);
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

Vec2I GetWindowSize(Window window)
{
  Vec2I size;
  
  glfwGetWindowSize(window, &size.x, &size.y);

  return size;
}

void _FrameResizeCallback(Window window, int width, int height)
{
  // Glad resize stuff
}

void _KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  KeyCode gilgKey = (KeyCode)key;

  if(gilgKey == KeyCode::ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}

} // end of gilg
