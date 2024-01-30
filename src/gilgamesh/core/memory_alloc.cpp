#include "memory_alloc.h"
#include "gilgamesh/core/defines.h"
#include "gilgamesh/core/logger.h"
#include "gilgamesh/core/gilg_asserts.h"

#include <cstdlib>
#include <cstring>

namespace gilg {

// Memory status
/////////////////////////////////////////////
typedef struct mem_status 
{
  usizei total_allocs, total_freed, total_usage;
} mem_status;

static mem_status mstatus;
/////////////////////////////////////////////

// Memory allocater functions
/////////////////////////////////////////////
b8 init_memory_allocater(void)
{
  mstatus.total_allocs = 0;
  mstatus.total_freed  = 0;
  mstatus.total_usage  = 0;

  GILG_LOG_INFO("Memory allocater successfully initialized");

  return true;
}

void shutdown_memory_allocater(void)
{
  GILG_ASSERT_MSG(mstatus.total_freed == 0, "Some allocations were not freed");
  GILG_LOG_INFO("Memory allocater successfully shutdown");
}

void* alloc_memory(usizei size)
{
  void* m = malloc(size);

  if(m == NULL)
    GILG_LOG_FATAL("Failed to allocate memory");

  mstatus.total_allocs += size;
  
  GILG_LOG_INFO("Allocated %zu", size);
  return m;  
}

void* calloc_memory(usizei count, usizei size)
{
  void* m = calloc(count, size);

  if(m == NULL)
    GILG_LOG_FATAL("Failed to allocate memory");

  mstatus.total_allocs += size * count;
  
  GILG_LOG_INFO("Allocated %zu", size * count);
  return m;  
}

void* realloc_memory(void* mem, usizei new_size)
{
  void* m = realloc(mem, new_size);

  if(m == NULL)
    GILG_LOG_FATAL("Failed to allocate memory");

  mstatus.total_allocs += new_size;
  
  GILG_LOG_INFO("Re-allocated memory block to size %zu", new_size);
  return m;  
}

void free_memory(void* mem, usizei size)
{
  free(mem);

  mstatus.total_freed += size;
  mstatus.total_usage = mstatus.total_allocs - mstatus.total_freed;

  GILG_LOG_INFO("Freed memory block of size %zu", size);
}

void* set_memory(void* mem, i32 value, usizei size)
{
  void* m = memset(mem, value, size);

  if(m == NULL)
    GILG_LOG_FATAL("Failed to set memory");

  GILG_LOG_INFO("Set memory block of size %zu to vlaue %i", size, value);
  return m;  
}

void* copy_memory(void* src, void* dest, usizei src_size)
{
  void* m = memcpy(dest, src, src_size);

  if(m == NULL)
    GILG_LOG_FATAL("Failed to copy memory");

  GILG_LOG_INFO("Copied memory block of size %zu", src_size);
  return m;  
}

void* zero_out_memory(void* mem, usizei size)
{
  GILG_LOG_INFO("Set memory block of size %zu to 0", size);
  return set_memory(mem, 0, size);
}
/////////////////////////////////////////////

}
