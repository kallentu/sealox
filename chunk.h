#ifndef SEALOX_CHUNK_H
#define SEALOX_CHUNK_H

/// Define the code representation with sequences of bytecode.
/// Each instruction has a one-byte operation code.

#include "common.h"

typedef enum {
  OP_RETURN,          // Return from current function
} OpCode;

/// Wrapper around an array of bytes.
typedef struct {
  /// Number of allocated elements that are currently in use.
  int count;

  /// Number of elements in the array that we have allocated.
  int capacity;

  uint8_t* code;
} Chunk;

/// Initialize new chunk, starts completely empty.
void initChunk(Chunk* chunk);

#endif // SEALOX_CHUNK_H
