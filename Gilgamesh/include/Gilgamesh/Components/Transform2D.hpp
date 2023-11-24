#pragma once

#include "Gilgamesh/GilgPCH.hpp"

namespace gilg { // beginning gilg
 
struct Transform2D 
{
  Vec2F position, rotation, scale;
  
  Transform2D() = default;
  Transform2D(Vec2F position, 
              Vec2F rotation = Vec2(0.0f, 0.0f), 
              Vec2F scale = Vec2(1.0f, 1.0f))
    :position(position), rotation(rotation), scale(scale)
  {}
};

void MoveTransform2D(Transform2D& transform, Vec2F speed);
void RotateTransform2D(Transform2D& transform, Vec2F rotation);
void ScaleTransform2D(Transform2D& transform, Vec2F factor);

} // end gilg
