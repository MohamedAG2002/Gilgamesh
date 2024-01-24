#pragma once

#include "core/defines.h"

namespace gilg {

// Random functions
///////////////////////////////////////////////////////////////
GILG_API void random_set_seed(const u64 seed);

GILG_API i32 random_int();
GILG_API i32 random_int(i32 min, i32 max);

GILG_API i64 random_long();
GILG_API i64 random_long(i64 min, i64 max);

GILG_API u32 random_uint();
GILG_API u32 random_uint(u32 min, u32 max);

GILG_API u64 random_ulong();
GILG_API u64 random_ulong(u64 min, u64 max);

GILG_API f32 random_float();
GILG_API f32 random_float(f32 min, f32 max);
///////////////////////////////////////////////////////////////

}
