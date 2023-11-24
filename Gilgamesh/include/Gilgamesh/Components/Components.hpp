#pragma once

#include "Gilgamesh/GilgPCH.hpp"
#include "Gilgamesh/Graphics/Color.hpp"
#include "Shape2DType.hpp"
#include "Anchor.hpp"
#include "TextType.hpp"

namespace gilg { // beginning of gilg

struct Text
{
};

struct Button 
{

};

struct Sprite2D
{

};

struct Shape2D 
{
  Shape2DType type; 
  Vec2F size;
  Color color;

  Shape2D() = default;
  Shape2D(Shape2DType type, Vec2F size, Color color)
    :type(type), size(size), color(color)
  {}
};

struct BoxCollider2D 
{

};

struct Sound2D 
{

};

struct Music2D
{

};

struct Timer 
{

};

struct Particles2D 
{

};
  

} // end of gilg
