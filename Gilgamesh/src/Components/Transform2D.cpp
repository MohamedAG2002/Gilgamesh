#include "Gilgamesh/Components/Transform2D.hpp"
#include "Gilgamesh/GilgPCH.hpp"

namespace gilg { // beginning gilg
 
void MoveTransform2D(Transform2D& transform, Vec2F speed)
{
  transform.position += speed;
}

void RotateTransform2D(Transform2D& transform, Vec2F rotation)
{
  transform.rotation += rotation;
}

void ScaleTransform2D(Transform2D& transform, Vec2F factor)
{
  transform.scale += factor;
}

} // end gilg
