#include "math_utils.h"
#include "gilgamesh/core/defines.h"

namespace gilg {

// Utility math functions
///////////////////////////////////////////////////////
i32 convert_range_int(i32 value, i32 old_min, i32 old_max, i32 new_min, i32 new_max)
{
  i32 old_range = old_max - old_min; 
  i32 new_range = new_max - new_min;
  
  if(old_range == 0)
    return new_min; 
  else 
    return (((value - old_min) * new_range) / old_range) + new_min;
}

u32 convert_range_uint(u32 value, u32 old_min, u32 old_max, u32 new_min, u32 new_max)
{
  u32 old_range = old_max - old_min; 
  u32 new_range = new_max - new_min;
  
  if(old_range == 0)
    return new_min; 
  else 
    return (((value - old_min) * new_range) / old_range) + new_min;
}

f32 convert_range_float(f32 value, f32 old_min, f32 old_max, f32 new_min, f32 new_max)
{
  f32 old_range = old_max - old_min; 
  f32 new_range = new_max - new_min;
  
  if(old_range == 0)
    return new_min; 
  else 
    return (((value - old_min) * new_range) / old_range) + new_min;
}
///////////////////////////////////////////////////////

}
