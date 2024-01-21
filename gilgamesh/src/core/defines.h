#pragma once

#include <cstddef>

namespace gilg {

// Unsigned types
////////////////////////////
typedef unsigned char  u8;
typedef unsigned char  b8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned long  u64;
typedef size_t         usizei;
////////////////////////////

// Signed types 
////////////////////////////
typedef char  i8;
typedef short i16;
typedef int   i32;
typedef long  i64;

typedef float  f32;
typedef double f64;
////////////////////////////

// Build types 
////////////////////////////
#define GILG_RELEASE 0
#define GILG_DEBUG   1
////////////////////////////

// Platform detection stuff
////////////////////////////
// ---- Windows ----- 
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
#define GILG_PLATFORM_WINDOWS 1
#ifndef _WIN64
#error "[GILG-PLATFORM-ERROR]: Gilgamesh does not support 32 bit\n" 
#endif
// ---- Windows ----- 

// ----- Linux -----
#elif defined(__linux__) || defined(__gnu_linux__)
#define GILG_PLATFORM_LINUX 1 
// ----- Linux -----

// ----- Posix -----
#elif defined(_POSIX_VERSION)
#define GILG_PLATFORM_POSIX 1
// ----- Posix -----

// ----- Unix -----
#elif defined(__unix__)
#define GILG_PLATFORM_UNIX 1
// ----- Unix -----

// ----- OSX/Max -----
#elif __APPLE__ 
#define GILG_PLATFORM_APPLE
// ----- OSX/Max -----

// ----- Unknown -----
#elif 
#error "[GILG-PLATFORM-ERROR]: Platform not supported\n"
// ----- Unknown -----
#endif
////////////////////////////

// Imports/Exports
////////////////////////////
#define GILG_API
////////////////////////////

}
