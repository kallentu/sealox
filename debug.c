#include <stdio.h>

#include "debug.h"
#include "value.h"

static int simpleInstruction(const char* name, int offset) {
  printf("%s\n", name);
  return offset + 1;
}

static int constantInstruction(const char* name, Chunk* chunk, int offset) {
  // Pulls constant index from the byte in the chunk.
  uint8_t constant = chunk->code[offset+1];
  printf("%-16s %4d '", name, constant);

  // Grab actual value of the constant to print something readable.
  printValue(chunk->constants.values[constant]);
  printf("'\n");

  // Moves the offset past the current instruction (opcode and operand)
  return offset + 2;
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

  if (offset > 0 &&
      getLine(chunk, offset) == getLine(chunk, offset - 1)) {
    // For any instruction that comes from the same source as the preceding one.
    printf("   | ");
  } else {
    printf("%4d ", getLine(chunk, offset));
  }

  // For each instruction, dispatch to utility function for displaying it.
  uint8_t instruction = chunk->code[offset];
  switch (instruction) {
    case OP_CONSTANT:
      return constantInstruction("OP_CONSTANT", chunk, offset);
    case OP_RETURN:
      return simpleInstruction("OP_RETURN", offset);
    default:
      printf("Unknown opcode %d\n", instruction);
      return offset + 1;
  }
}