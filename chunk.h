// This module is used to represent code representation

#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"

// Used to store one byte instruction code which signifies the type of information.
typedef enum
{
    OP_CONSTANT,
    OP_RETURN,
} OpCode;

// Used to store a instruction along with necessary addational data in form of dynamic array
typedef struct
{
    int count;
    int capacity;
    uint8_t *code;
    int *lines;
    ValueArray constants;
} Chunk;

void initChunk(Chunk *chunk);
void freeChunk(Chunk *chunk);
void writeChunk(Chunk *chunk, uint8_t byte, int line);
int addConstant(Chunk *chunk, Value value);

#endif
