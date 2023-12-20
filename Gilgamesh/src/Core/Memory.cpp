#include "Gilgamesh/Core/Memory.hpp"
#include "Gilgamesh/Core/Asserts.hpp"
#include "Gilgamesh/Core/Log.hpp"

#include <cstdlib>
#include <cstring>

namespace gilg { // beginning of gilg

int allocCount = 0;

bool InitMemorySystem()
{
  //@TODO
  return true;
}

void UnloadMemorySystem()
{
  //@TODO

  if(allocCount > 0)
    GILG_LOG_WARNING("\'%i\' allocation(s) were not freed", allocCount);
  else 
    GILG_LOG_WARNING("All allocations were freed!");
}

void* AllocMem(ISize size)
{
  void* data = malloc(size);
  GILG_ASSERT(data != nullptr);
  
  allocCount++;
  GILG_LOG_DEBUG("Successfully allocated memory block of size \'%zu\'", size);

  return data;  
}

void* CAllocMem(ISize count, ISize size)
{
  void* data = calloc(count, size);
  GILG_ASSERT(data != nullptr);

  allocCount += count;
  GILG_LOG_DEBUG("Allocated \'%zu\' blocks of memory of size \'%zu\' each", count, size);

  return data;  
}

void* ReAllocMem(void* mem, ISize newSize)
{
  void* data = realloc(mem, newSize);
  GILG_ASSERT(data != nullptr);

  GILG_LOG_DEBUG("Successfully re-allocated memory block to size \'%zu\'", newSize);

  return data;  
}

void FreeMem(void* mem)
{
  free(mem);

  allocCount--;
  GILG_LOG_DEBUG("A block of memory was successfully freed");
}

void* SetMem(void* mem, int val, ISize size)
{
  void* data = memset(mem, val, size);
  GILG_ASSERT(data != nullptr);

  GILG_LOG_DEBUG("Memory block of size \'%zu\' was set to \'%i\'", size, val);

  return data;  
}

void* CopyMem(const void* src, void* dest, ISize size)
{
  void* data = memcpy(dest, src, size);
  GILG_ASSERT(data != nullptr);

  GILG_LOG_DEBUG("A memory block of size \'%zu\' was successfully copied into another memory block", size);

  return data;  
}

} // end of gilg
