#pragma once

#include "Window.hpp"
#include "Gilgamesh/GilgPCH.hpp"

namespace gilg { // beginning of gilg

struct Application 
{
  bool isRunning;
  F32 lastFrame, deltaTime;

  Window window;
};

void UpdateApp();
void RenderApp();

GILG_API void InitApp(U32 width, U32 height, const String& title);
GILG_API void RunApp();
GILG_API void UnloadApp();

} // end of gilg
