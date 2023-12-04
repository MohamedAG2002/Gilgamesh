#pragma once

#include "Color.hpp"
#include "Gilgamesh/GilgPCH.hpp"

namespace gilg { // beginning of gilg
 
struct Renderer2D
{
  Renderer2D();
};

void Render2DClear(Renderer2D& renderer, Color color);
void Render2DBegin(Renderer2D& renderer);
void Render2DEnd(Renderer2D& renderer);
void UnloadRender2D(Renderer2D& renderer);

GILG_API void RenderRectangle(Renderer2D& renderer, Vec2F pos, Vec2F size, Color color);
GILG_API void RenderRectangleOutline(Renderer2D& renderer, Vec2F pos, Vec2F size, Color color);
GILG_API void RenderLine(Renderer2D& renderer, Vec2F startPos, Vec2F endPos, Color color);
GILG_API void RenderPoint(Renderer2D& renderer, Vec2F pos, Color color);
GILG_API void RenderText(Renderer2D& renderer);
GILG_API void RenderSprite(Renderer2D& renderer);
GILG_API void RenderTriangle(Renderer2D& renderer);
GILG_API void RenderCircle(Renderer2D& renderer);

void* Render2DLoadTexture(Renderer2D& renderer, const std::string& path);

} // end of gilg
