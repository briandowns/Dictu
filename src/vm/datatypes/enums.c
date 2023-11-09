#include "enums.h"

static Value values(CamusVM *vm, int argCount, Value *args) {
    if (argCount != 0) {
        runtimeError(vm, "values() takes 0 arguments (%d given)", argCount);
        return EMPTY_VAL;
    }

    ObjEnum *objEnum = AS_ENUM(args[0]);
    ObjDict *dict = newDict(vm);
    push(vm, OBJ_VAL(dict));

    for (int i = 0; i < objEnum->values.capacityMask + 1; ++i) {
        if (objEnum->values.entries[i].key == NULL) {
            continue;
        }

        dictSet(vm, dict, OBJ_VAL(objEnum->values.entries[i].key), objEnum->values.entries[i].value);
    }

    pop(vm);

    return OBJ_VAL(dict);
}

void declareEnumMethods(CamusVM *vm) {
    defineNative(vm, &vm->enumMethods, "values", values);
}
