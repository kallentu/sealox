#ifndef SEALOX_MEMORY_H
#define SEALOX_MEMORY_H

#include "common.h"

/// Grow capacity by a factor of two. Except initially, at 8.
#define GROW_CAPACITY(capacity) \
  ((capacity) < 8 ? 8 : (capacity) * 2)

/// Grow array to certain size.
/// Gets the size of the array's element type and casts the resulting void* to a
/// pointer of the right type.
#define GROW_ARRAY(type, pointer, oldCount, newCount) \
  (type*)reallocate(pointer, sizeof(type) * (oldCount), \
  sizeof(type) * (newCount))

/// TODO Allocating memory, freeing memory, changing size of an existing allocation.
void* reallocate(void* pointer, size_t oldSize, size_t newSize);

#endif // SEALOX_MEMORY_H
