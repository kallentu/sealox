#ifndef SEALOX_CHUNK_H
#define SEALOX_CHUNK_H

/// Define the code representation with sequences of bytecode.
/// Each instruction has a one-byte operation code.

#include "common.h"

typedef enum {
    OP_RETURN,          // Return from current function
} OpCode;

#endif // SEALOX_CHUNK_H
