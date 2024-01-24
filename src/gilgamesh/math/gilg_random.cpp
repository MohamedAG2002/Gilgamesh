#include "gilg_random.h"
#include "core/defines.h"

#include <random>

namespace gilg {

// Globals
///////////////////////////////////////////////////////////////
static std::random_device rand_device;
static std::mt19937 engine(rand_device());
///////////////////////////////////////////////////////////////

// Random functions
///////////////////////////////////////////////////////////////
void random_set_seed(const u64 seed)
{
  engine.seed(seed);
}

i32 random_int()
{
  std::uniform_int_distribution<i32> uniform_dist;
  return uniform_dist(engine);
}

i32 random_int(i32 min, i32 max)
{
  std::uniform_int_distribution<i32> uniform_dist(min, max);
  return uniform_dist(engine);
}

i64 random_long()
{
  std::uniform_int_distribution<i64> uniform_dist;
  return uniform_dist(engine);
}

i64 random_long(i64 min, i64 max)
{
  std::uniform_int_distribution<i64> uniform_dist(min, max);
  return uniform_dist(engine);
}

u32 random_uint()
{
  std::uniform_int_distribution<u32> uniform_dist;
  return uniform_dist(engine);
}

u32 random_uint(u32 min, u32 max)
{
  std::uniform_int_distribution<u32> uniform_dist(min, max);
  return uniform_dist(engine);
}

u64 random_ulong()
{
  std::uniform_int_distribution<u64> uniform_dist;
  return uniform_dist(engine);
}

u64 random_ulong(u64 min, u64 max)
{
  std::uniform_int_distribution<u64> uniform_dist(min, max);
  return uniform_dist(engine);
}

f32 random_float()
{
  std::uniform_real_distribution<f32> uniform_dist;
  return uniform_dist(engine);
}

f32 random_float(f32 min, f32 max)
{
  std::uniform_real_distribution<f32> uniform_dist(min, max);
  return uniform_dist(engine);
}
///////////////////////////////////////////////////////////////

}
