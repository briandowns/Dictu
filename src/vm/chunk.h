#ifndef camus_chunk_h
#define camus_chunk_h

#include "common.h"
#include "value.h"

typedef struct {
    int count;
    int capacity;
    uint8_t *code;
    int *lines;
    ValueArray constants;
} Chunk;

typedef enum {
    #define OPCODE(name) OP_##name,
    #include "opcodes.h"
    #undef OPCODE
} OpCode;

void initChunk(CamusVM *vm, Chunk *chunk);

void freeChunk(CamusVM *vm, Chunk *chunk);

void writeChunk(CamusVM *vm, Chunk *chunk, uint8_t byte, int line);

int addConstant(CamusVM *vm, Chunk *chunk, Value value);

#endif
