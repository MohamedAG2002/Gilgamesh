#pragma once

#include "Gilgamesh/GilgPCH.hpp"
#include "Gilgamesh/Components/Anchor.hpp"

namespace gilg { // beginning of gilg

namespace util { // beginning of util

Vec2F GetPositionByAnchor(Anchor anc, Vec2F offset, Vec2F surfaceSize);
  
} // end of util

} // end of gilg
