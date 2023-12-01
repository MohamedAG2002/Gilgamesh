#include "Gilgamesh/Graphics/Renderer2D.hpp"
#include "Gilgamesh/Graphics/Color.hpp"
#include "Gilgamesh/Core/Window.hpp"
#include "Gilgamesh/GilgPCH.hpp"

namespace gilg { // beginning of gilg

Renderer2D::Renderer2D()
{
}

void Render2DClear(Renderer2D& renderer, Color color)
{
}

void Render2DBegin(Renderer2D& renderer)
{
}

void Render2DEnd(Renderer2D& renderer)
{
}

void UnloadRender2D(Renderer2D& renderer)
{
}

void RenderRectangle(Renderer2D& renderer, Vec2F pos, Vec2F size, Color color)
{
}

void RenderRectangleOutline(Renderer2D& renderer, Vec2F pos, Vec2F size, Color color)
{
}

void RenderLine(Renderer2D& renderer, Vec2F startPos, Vec2F endPos, Color color)
{
}

void RenderPoint(Renderer2D& renderer, Vec2F pos, Color color)
{ 
}

void* Render2DLoadTexture(Renderer2D& renderer, const std::string& path)
{
  return nullptr;
}

} // end of gilg
