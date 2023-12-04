#pragma once

#include "Gilgamesh/GilgPCH.hpp"

#include <GLFW/glfw3.h>

namespace gilg { // beginning of gilg

typedef GLFWwindow* Window;

Window CreateWindow(U32 width, U32 height, const String& title);
bool IsWindowRunning(Window window);
void ProcessWindowEvents();
void UnloadWindow(Window window);

GILG_API Vec2I GetWindowSize(Window window);

// Private functions DO NOT USE THESE! 
void _FrameResizeCallback(Window window, int width, int height);
void _KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

} // end of gilg
