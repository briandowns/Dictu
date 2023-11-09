#ifndef camus_util_h
#define camus_util_h

#include "vm.h"

char *readFile(CamusVM *vm, const char *path);

ObjString *getDirectory(CamusVM *vm, char *source);

void defineNative(CamusVM *vm, Table *table, const char *name, NativeFn function);

void defineNativeProperty(CamusVM *vm, Table *table, const char *name, Value value);

bool isValidKey(Value value);

Value boolNative(CamusVM *vm, int argCount, Value *args);

ObjString *dirname(CamusVM *vm, char *path, int len);

bool resolvePath(char *directory, char *path, char *ret);

#endif //camus_util_h
