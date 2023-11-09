#ifndef camus_copy_h
#define camus_copy_h

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "../vm.h"
#include "../memory.h"

ObjList *copyList(CamusVM *vm, ObjList *oldList, bool shallow);

ObjDict *copyDict(CamusVM *vm, ObjDict *oldDict, bool shallow);

ObjInstance *copyInstance(CamusVM *vm, ObjInstance *oldInstance, bool shallow);

#endif //camus_copy_h
