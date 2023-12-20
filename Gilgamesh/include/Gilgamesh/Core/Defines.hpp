#pragma once

#include <string>

namespace gilg { // beginning of gilg

/* Types typedefs */
// Ints
typedef char  I8;
typedef short I16;
typedef int   I32;
typedef long  I64;
typedef size_t ISize;

// Unsigned ints
typedef unsigned char  U8;
typedef unsigned short U16;
typedef unsigned int   U32;
typedef unsigned long  U64;

// Decimals
typedef float  F32;
typedef double F64;

// String
typedef std::string String;

// Build types
#define GILG_RELEASE 0
#define GILG_DEBUG   1

/* Platform detection macros */
// Windows 
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) 
#define GILG_PLATFORM_WINDOWS 1
#ifndef _WIN64 // NEED windows 64 bit
#error "[PLATFORM ERROR]: 64-BIT windows is required\n"
#endif // _WIN64

// Linux 
#elif defined(__linux__) || defined(__gnu_linux__) 
#define GILG_PLATFORM_LINUX 1

// Unix 
#elif defined(__unix__) 
#define GILG_PLATFORM_UNIX 1

// Posix
#elif defined(_POSIX_VERSION) 
#define GILG_PLATFORM_POSIX 1

// Apple
#elif __APPLE__ 
#define GILG_PLATFORM_APPLE 1

// ?????
#else
#error "[PLATFORM ERROR]: What OS are you on??????\n"
#endif

// Exports
#ifdef GILG_EXPORT
#ifdef _MSC_VER
#define GILG_API __declspec(dllexport)
#else 
#define GILG_API __attribute__(visibility("default"))
#endif

// Imports
#else 
#ifdef _MSC_VER
#define GILG_API __declspec(dllimport)
#else 
#define GILG_API
#endif

#endif

} // end gilg
