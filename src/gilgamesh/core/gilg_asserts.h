#pragma once

#include "gilgamesh/core/logger.h"

namespace gilg {

#define GILG_ASSERT_ENABLED

// Asserts
////////////////////////////////////////////////////////////////
#ifdef GILG_ASSERT_ENABLED

// Defining DEBUG_BREAK based on the platform
#if _MSC_VERT
#include <intrin.h>
#define DEBUG_BREAK() __debugbreak()
#else
#define DEBUG_BREAK() __builtin_trap()
#endif

// Defining the asserts
#define GILG_ASSERT(expr)                                \
        {                                                \
          if(expr) {                                     \
          }                                              \
          else {                                         \
            log_assertion(#expr, "", __FILE__, __LINE__); \
            DEBUG_BREAK();                               \
          }                                              \
        }                                                \

#define GILG_ASSERT_MSG(expr, msg)                        \
        {                                                 \
          if(expr) {                                      \
          }                                               \
          else {                                          \
            log_assertion(#expr, msg, __FILE__, __LINE__); \
            DEBUG_BREAK();                                \
          }                                               \
        }                                                 \

// @TODO: fix later
/*
#if GILG_DEBUG == 1
#define GILG_ASSERT_DEBUG(expr)                                \
        {                                                      \
          if(expr) {                                           \
          }                                                    \
          else {                                               \
            log_assertion(#expr, "", __FILE__, __LINE__);      \
            DEBUG_BREAK();                                     \
          }                                                    \
        }                                                      \
#else
#define GILG_ASSERT_DEBUG()
#endif
*/

#else 
#define GILG_ASSERT()
#define GILG_ASSERT_LOG()
#define GILG_ASSERT_DEBUG()
#endif
////////////////////////////////////////////////////////////////

}
