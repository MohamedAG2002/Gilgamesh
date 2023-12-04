#pragma once

#include "Window.hpp"
#include "Gilgamesh/GilgPCH.hpp"
#include "Gilgamesh/Graphics/Renderer2D.hpp"

namespace gilg { // beginning of gilg

struct Application 
{
  bool isRunning;
  F32 lastFrame, deltaTime;

  Window window;
  Renderer2D renderer;

  Application(U32 width, U32 height, const String& title);
};

void ProcessAppEvents(Application& app);
void UpdateApp(Application& app);
void RenderApp(Application& app);

GILG_API void RunApp(Application& app);
GILG_API void UnloadApp(Application& app);

} // end of gilg
