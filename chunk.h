#ifndef SEALOX_CHUNK_H
#define SEALOX_CHUNK_H

/// Define the code representation with sequences of bytecode.
/// Each instruction has a one-byte operation code.

#include "common.h"
#include "value.h"

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
  ValueArray constants;
} Chunk;

/// Initialize new chunk, starts completely empty.
void initChunk(Chunk* chunk);

/// Deallocating the memory.
void freeChunk(Chunk* chunk);

/// Append a byte to the end of the chunk.
void writeChunk(Chunk* chunk, uint8_t byte);

/// Convenience method to add a new constant to the chunk.
/// Returns the index where the constant was appended.
int addConstant(Chunk* chunk, Value value);

#endif // SEALOX_CHUNK_H
