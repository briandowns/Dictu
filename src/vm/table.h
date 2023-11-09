#ifndef camus_table_h
#define camus_table_h

#include <stdio.h>

#include "common.h"
#include "value.h"

typedef struct {
    ObjString *key;
    Value value;
    uint32_t psl;
} Entry;

typedef struct {
    int count;
    int capacityMask;
    Entry *entries;
} Table;

void initTable(Table *table);

void freeTable(CamusVM *vm, Table *table);

bool tableGet(Table *table, ObjString *key, Value *value);

bool tableSet(CamusVM *vm, Table *table, ObjString *key, Value value);

bool tableDelete(CamusVM *vm, Table *table, ObjString *key);

void tableAddAll(CamusVM *vm, Table *from, Table *to);

ObjString *tableFindString(Table *table, const char *chars, int length,
                           uint32_t hash);

void tableRemoveWhite(CamusVM *vm, Table *table);

void grayTable(CamusVM *vm, Table *table);

#endif
