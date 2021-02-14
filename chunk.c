#include <stdlib.h>

#include "chunk.h"
#include "memory.h"

void initChunk(Chunk* chunk) {
  chunk->count = 0;
  chunk->capacity = 0;
  chunk->code = NULL;
  chunk->lines = NULL;
  chunk->currentLineIndex = 0;

  // Must also initialize the constant list when we initialize the chunk.
  initValueArray(&chunk->constants);
}

void writeChunk(Chunk* chunk, uint8_t byte, int line) {
  // If capacity is full, need to increase capacity.
  if (chunk->capacity < chunk->count + 1) {
    int oldCapacity = chunk->capacity;
    chunk->capacity = GROW_CAPACITY(oldCapacity);
    chunk->code = GROW_ARRAY(uint8_t, chunk->code, oldCapacity, chunk->capacity);
    chunk->lines = GROW_ARRAY(int, chunk->lines, oldCapacity, chunk->capacity);
  }

  chunk->code[chunk->count] = byte;

  // Check if line is different than the one used by the chunk before, if so,
  // then add to the line count.
  if (chunk->count == 0 || chunk->lines[chunk->currentLineIndex - 1] != line) {
    // Add line to lines array and add instruction index as well.
    chunk->lines[chunk->currentLineIndex] = line;
    chunk->instructionIndices[chunk->currentLineIndex] = chunk->count;
    chunk->currentLineIndex++;
  }

  chunk->count++;
}

void freeChunk(Chunk* chunk) {
  FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
  FREE_ARRAY(int, chunk->lines, chunk->capacity);

  // Free the constants when we free the chunk.
  freeValueArray(&chunk->constants);

  // Zero out the fields used.
  initChunk(chunk);
}

int addConstant(Chunk* chunk, Value value) {
  writeValueArray(&chunk->constants, value);
  return chunk->constants.count - 1;
}

int getLine(Chunk* chunk, int instructionIndex) {
  int line = 0;

  // Find lowest line number in range for the instruction index.
  for (int lineIndex = 0; lineIndex < chunk->currentLineIndex; lineIndex++) {
    // Break if we are out of range already, thus already found current line info.
    if (chunk->instructionIndices[lineIndex] > instructionIndex) break;
    line = chunk->lines[lineIndex];
  }

  return line;
}