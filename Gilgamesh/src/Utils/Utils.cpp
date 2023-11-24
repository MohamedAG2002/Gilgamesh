#include "Gilgamesh/Utils/Utils.hpp"
#include "Gilgamesh/Components/Anchor.hpp"
#include "Gilgamesh/Core/Window.hpp"
#include "Gilgamesh/GilgPCH.hpp"

namespace gilg { // beginning of gilg

namespace util { // beginning of util

Vec2 GetPositionByAnchor(Anchor anc, Vec2 offset, Vec2 surfaceSize)
{
  // Variables for easier visualization
  Vec2 screenSize = GetWindowSize();

  switch(anc)
  {
    case Anchor::TOP_LEFT:
      return Vec2{10.0f + offset.x, 10.0f + offset.y};
      break;
    case Anchor::TOP_CENTER:
      return Vec2{screenSize.x / 2.0f - surfaceSize.x / 2.0f + offset.x, 10.0f + offset.y};
      break;
    case Anchor::TOP_RIGHT:
      return Vec2{(screenSize.x - surfaceSize.x - 10.0f) + offset.x, 10.0f + offset.y};
      break;
    case Anchor::CENTER_LEFT:
      return Vec2{10.0f + offset.x, screenSize.y / 2.0f - surfaceSize.y / 2.0f + offset.y};
      break;
    case Anchor::CENTER:
      return Vec2{screenSize.x / 2.0f - surfaceSize.x / 2.0f + offset.x, 
                      screenSize.y / 2.0f - surfaceSize.y / 2.0f + offset.y};
      break;
    case Anchor::CENTER_RIGHT:
      return Vec2{(screenSize.x - surfaceSize.x - 10.0f) + offset.x, 
                      screenSize.y / 2.0f - surfaceSize.y / 2.0f + offset.y};
      break;
    case Anchor::BOTTOM_LEFT:
      return Vec2{10.0f + offset.x, (screenSize.y - surfaceSize.y - 10.0f) + offset.y};
      break;
    case Anchor::BOTTOM_CENTER:
      return Vec2{screenSize.x / 2.0f - surfaceSize.x / 2.0f + offset.x, 
                      (screenSize.y - surfaceSize.y - 10.0f) + offset.y};
      break;
    case Anchor::BOTTOM_RIGHT:
      return Vec2{(screenSize.x - surfaceSize.x - 10.0f) + offset.x, 
                      (screenSize.y - surfaceSize.y - 10.0f) + offset.y};
      break;
    default:
      return Vec2(0.0f, 0.0f);
      break;
  }
}
  
} // end of util

} // end of gilg
