#ifndef SEALOX_VM_H
#define SEALOX_VM_H

#include "chunk.h"

/// The virtual machine runs a chunk of code.
typedef struct {
  Chunk* chunk;
} VM;

/// Initialize the virtual machine.
void initVM();

/// Destroy the virtual machine.
void freeVM();

#endif // SEALOX_VM_H
