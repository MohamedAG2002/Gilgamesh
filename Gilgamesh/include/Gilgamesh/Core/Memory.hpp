#pragma once

#include "Defines.hpp"

namespace gilg { // beginning of gilg

/* Size macros*/
// Converts 'x' to Kibibytes (KB)
#define KIB(x) (x * 1024)

// Coverts 'x' to Mebibytes (MB)
#define MIB(x) ((x) * 1024 * 1024) 

// Converts 'x' to Gibibytes (GB)
#define GIB(x) ((x) * 1024 * 1024 * 1024) 

bool InitMemorySystem();
void UnloadMemorySystem();

void* AllocMem(ISize size);
void* CAllocMem(ISize count, ISize size);
void* ReAllocMem(void* mem, ISize newSize);
void FreeMem(void* mem);
void* SetMem(void* mem, int val, ISize size);
void* CopyMem(const void* src, void* dest, ISize size);

} // end of gilg
