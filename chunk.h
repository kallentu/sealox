#ifndef SEALOX_CHUNK_H
#define SEALOX_CHUNK_H

/// Define the code representation with sequences of bytecode.
/// Each instruction has a one-byte operation code.

#include "common.h"
#include "value.h"

typedef enum {
  OP_CONSTANT,
  OP_RETURN,          // Return from current function
} OpCode;

/// Wrapper around an array of bytes.
typedef struct {
  /// Number of allocated elements that are currently in use.
  int count;

  /// Number of elements in the array that we have allocated.
  int capacity;

  uint8_t* code;

  /// Array to hold line information, used to determine what line an error
  /// is occurring on.
  int* lines;

  /// Instruction index that the line starts at. Will have same size as [lines].
  int* instructionIndices;

  /// Current line index. Starts at 0, will keep track of the current line
  /// the chunk is on.
  int currentLineIndex;

  ValueArray constants;
} Chunk;

/// Initialize new chunk, starts completely empty.
void initChunk(Chunk* chunk);

/// Deallocating the memory.
void freeChunk(Chunk* chunk);

/// Append a byte to the end of the chunk.
/// When written, need to know what source line it came from to trace back.
void writeChunk(Chunk* chunk, uint8_t byte, int line);

/// Convenience method to add a new constant to the chunk.
/// Returns the index where the constant was appended.
int addConstant(Chunk* chunk, Value value);

/// Given the index of an instruction, determines the line where the instruction
/// occurs.
int getLine(Chunk* chunk, int instructionIndex);

#endif // SEALOX_CHUNK_H
