#include <stdio.h>

#include "debug.h"

static int simpleInstruction(const char* name, int offset) {
  printf("%s\n", name);
  return offset + 1;
}

void disassembleChunk(Chunk* chunk, const char* name) {
  // Print header to indicate which chunk we are looking at.
  printf("== %s ==\n", name);

  for (int offset = 0; offset < chunk->count;) {
    offset = disassembleInstruction(chunk, offset);
  }
}

int disassembleInstruction(Chunk* chunk, int offset) {
  // Prints byte offset of given instruction, telling us where in the chunk
  // the instruction is.
  printf("%04d ", offset);

  // For each instruction, dispatch to utility function for displaying it.
  uint8_t instruction = chunk->code[offset];
  switch (instruction) {
    case OP_RETURN:
      return simpleInstruction("OP_RETURN", offset);
    default:
      printf("Unknown opcode %d\n", instruction);
      return offset + 1;
  }
}