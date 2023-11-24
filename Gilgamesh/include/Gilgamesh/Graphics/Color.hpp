#pragma once

#include "Gilgamesh/GilgPCH.hpp"

namespace gilg { // beginning of gilg
 
struct Color 
{
  U8 r, g, b, a;
 
  Color()
    :r(0), g(0), b(0), a(255)
  {}

  Color(U8 r, U8 g, U8 b, U8 a = 255)
    :r(r), g(g), b(b), a(a)
  {}

  // Static variables
  ///////////////////////
  static const Color Red;
  static const Color Green;
  static const Color Blue; 
  static const Color Black;
  static const Color White;
  static const Color Magenta;
  static const Color Yellow; 
  static const Color Cyan;
  static const Color Gray; 
  static const Color Brown;
  ///////////////////////
};

} // end of gilg
