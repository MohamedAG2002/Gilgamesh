#pragma once 

#include "Log.hpp"

namespace gilg { // beginning of gilg

#define GILG_ASSERT_ENABLED

#ifdef GILG_ASSERT_ENABLED
#if _MSC_VERT
#include <intrin.h>
#define DEBUG_BREAK() __debugbreak()
#else
#define DEBUG_BREAK() __builtin_trap()
#endif

#define GILG_ASSERT(expr)                                \
        {                                                \
          if(expr) {                                     \
          }                                              \
          else {                                         \
            LogAssertion(#expr, "", __FILE__, __LINE__); \
            DEBUG_BREAK();                               \
          }                                              \
        }                                                \

#define GILG_ASSERT_MSG(expr, msg)                        \
        {                                                 \
          if(expr) {                                      \
          }                                               \
          else {                                          \
            LogAssertion(#expr, msg, __FILE__, __LINE__); \
            DEBUG_BREAK();                                \
          }                                               \
        }                                                 \

#define GILG_ASSERT_DEBUG(expr)                                \
        {                                                      \
          if(expr) {                                           \
          }                                                    \
          else {                                               \
            LogAssertion(#expr, "", __FILE__, __LINE__);       \
            DEBUG_BREAK();                                     \
          }                                                    \
        }                                                      \

#else 
#define GILG_ASSERT()
#define GILG_ASSERT_LOG()
#define GILG_ASSERT_DEBUG()
#endif

} // end of gilg
