#include "nil.h"

static Value toStringNil(CamusVM *vm, int argCount, Value *args) {
    UNUSED(args);

    if (argCount != 0) {
        runtimeError(vm, "toString() takes no arguments (%d given)", argCount);
        return EMPTY_VAL;
    }

    return OBJ_VAL(copyString(vm, "nil", 3));
}

void declareNilMethods(CamusVM *vm) {
    defineNative(vm, &vm->nilMethods, "toString", toStringNil);
    defineNative(vm, &vm->nilMethods, "toBool", boolNative); // Defined in util
}
