#pragma once

#include "Color.hpp"
#include "Gilgamesh/GilgPCH.hpp"
#include "Gilgamesh/Components/Components.hpp"

namespace gilg { // beginning of gilg
 
struct Renderer2D
{
  Renderer2D();
};

void Render2DClear(Renderer2D& renderer, Color color);
void Render2DBegin(Renderer2D& renderer);
void Render2DEnd(Renderer2D& renderer);
void UnloadRender2D(Renderer2D& renderer);

void RenderRectangle(Renderer2D& renderer, Vec2F pos, Vec2F size, Color color);
void RenderRectangleOutline(Renderer2D& renderer, Vec2F pos, Vec2F size, Color color);
void RenderLine(Renderer2D& renderer, Vec2F startPos, Vec2F endPos, Color color);
void RenderPoint(Renderer2D& renderer, Vec2F pos, Color color);
void RenderText(Text& text);
void RenderSprite(Renderer2D& renderer, Sprite2D& sprite, Vec2F position);
// RenderTriangle
// RenderCircle

void* Render2DLoadTexture(Renderer2D& renderer, const std::string& path);

} // end of gilg
