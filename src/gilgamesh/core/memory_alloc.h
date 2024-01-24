#pragma once

#include "defines.h"

namespace gilg {

// Macros
/////////////////////////////////////////////
// Converts 'x' to Kibibytes (KB)
#define KIB(x) (x * 1024)

// Coverts 'x' to Mebibytes (MB)
#define MIB(x) ((x) * 1024 * 1024) 

// Converts 'x' to Gibibytes (GB)
#define GIB(x) ((x) * 1024 * 1024 * 1024) 
/////////////////////////////////////////////

// Memory allocater functions
/////////////////////////////////////////////
b8 init_memory_allocater(void);
void shutdown_memory_allocater(void);

void* alloc_memory(usizei size);
void* calloc_memory(usizei count, usizei size);
void* realloc_memory(void* mem, usizei new_size);
void free_memory(void* mem, usizei size);
void* set_memory(void* mem, i32 value, usizei size);
void* copy_memory(void* src, void* dest, usizei src_size);
void* zero_out_memory(void* mem, usizei size);
/////////////////////////////////////////////

}
