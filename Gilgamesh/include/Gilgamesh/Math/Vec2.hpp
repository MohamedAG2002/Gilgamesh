#pragma once

#include "Gilgamesh/GilgPCH.hpp"

namespace gilg { // beginning of gilg
 
template<typename T>
struct Vec2
{
  T x, y; 

  // CTORs
  Vec2() = default;
  Vec2(T x, T y)
    :x(x), y(y)
  {}

  //////////////////////////////////////
  // = operator overloading
  const Vec2<T>& operator=(const Vec2<T>& other)
  {
    this->x = other.x;
    this->y = other.y;
  }
  //////////////////////////////////////
};

// Template definitions 
using Vec2I = Vec2<I32>;
using Vec2F = Vec2<F32>;
using Vec2U = Vec2<U32>;

//////////////////////////////////////
// comparison operator overloading
template<typename T>
bool operator==(const Vec2<T>& vec, const Vec2<T>& other)
{
  return (vec.x == other.x) && (vec.y == other.y);
}

template<typename T>
bool operator!=(const Vec2<T>& vec, const Vec2<T>& other)
{
  return (vec.x != other.x) && (vec.y != other.y);
}

template<typename T>
bool operator>(const Vec2<T>& vec, const Vec2<T>& other)
{
  return (vec.x > other.x) && (vec.y > other.y);
}

template<typename T>
bool operator>=(const Vec2<T>& vec, const Vec2<T>& other)
{
  return (vec.x >= other.x) && (vec.y >= other.y);
}

template<typename T>
bool operator<(const Vec2<T>& vec, const Vec2<T>& other)
{
  return (vec.x < other.x) && (vec.y < other.y);
}

template<typename T>
bool operator<=(const Vec2<T>& vec, const Vec2<T>& other)
{
  return (vec.x <= other.x) && (vec.y <= other.y);
}
//////////////////////////////////////

//////////////////////////////////////
// + += operator overloading 
template<typename T>
Vec2<T> operator+(const Vec2<T>& vec, const Vec2<T>& other)
{
  return Vec2<T>{vec.x + other.x, vec.y + other.y};
}

template<typename T>
Vec2<T> operator+(const Vec2<T>& vec, float f)
{
  return Vec2<T>{vec.x + f, vec.y + f};
}

template<typename T>
void operator+=(Vec2<T>& vec, Vec2<T> other)
{
  vec.x += other.x;
  vec.y += other.y;
}

template<typename T>
void operator+=(Vec2<T>& vec, float f)
{
  vec.x += f;
  vec.y += f;
}
//////////////////////////////////////

} // end of gilg
