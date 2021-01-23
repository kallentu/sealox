#ifndef SEALOX_DEBUG_H
#define SEALOX_DEBUG_H

#include "chunk.h"

/// Disassembles all the instructions in the chunk.
void disassembleChunk(Chunk* chunk, const char* name);

int disassembleInstruction(Chunk* chunk, int offset);

#endif // SEALOX_DEBUG_H
