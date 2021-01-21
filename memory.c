#include <stdlib.h>

#include "memory.h"

/// If [oldSize] is 0 and [newSize] is > 0 => allocate new block
/// If [oldSize] is > 0 and [newSize] is 0 => free the memory
/// If [oldSize] is > 0 and [newSize] < [oldSize] => shrink
/// If [oldSize] is > 0 and [newSize] > [oldSize] => grow
void* reallocate(void* ptr, size_t oldSize, size_t newSize) {
  // Handle deallocation ourselves by calling free from the stdlib.
  if (newSize == 0) {
    free(ptr);
    return NULL;
  }

  // Tell realloc() to resize the block. If there isn't room to grow,
  // realloc() will allocate a new block of memory, copy over bytes and free
  // old block.
  void* result = realloc(ptr, newSize);

  // Allocation can fail if there isn't enough memory.
  if (result == NULL) exit(1);

  return result;
}
