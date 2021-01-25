#ifndef SEALOX_VALUE_H
#define SEALOX_VALUE_H

#include "common.h"

/// How our VM represents values.
typedef double Value;

typedef struct {
  int capacity;
  int count;
  Value* values;
} ValueArray;

void initValueArray(ValueArray* array);
void writeValueArray(ValueArray* array, Value value);
void freeValueArray(ValueArray* array);

#endif // SEALOX_VALUE_H
