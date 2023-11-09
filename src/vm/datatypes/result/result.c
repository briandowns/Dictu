#include "result.h"

#include "result-source.h"

static Value unwrap(CamusVM *vm, int argCount, Value *args) {
    if (argCount != 0) {
        runtimeError(vm, "unwrap() takes no arguments (%d given)", argCount);
        return EMPTY_VAL;
    }

    ObjResult *result = AS_RESULT(args[0]);

    if (result->status == ERR) {
        runtimeError(vm, "Attempted unwrap() on an error Result value '%s'", AS_CSTRING(result->value));
        return EMPTY_VAL;
    }

    return result->value;
}

static Value unwrapError(CamusVM *vm, int argCount, Value *args) {
    if (argCount != 0) {
        runtimeError(vm, "unwrapError() takes no arguments (%d given)", argCount);
        return EMPTY_VAL;
    }

    ObjResult *result = AS_RESULT(args[0]);

    if (result->status == SUCCESS) {
        runtimeError(vm, "Attempted unwrapError() on a success Result value");
        return EMPTY_VAL;
    }

    return result->value;
}

static Value success(CamusVM *vm, int argCount, Value *args) {
    if (argCount != 0) {
        runtimeError(vm, "success() takes no arguments (%d given)", argCount);
        return EMPTY_VAL;
    }

    ObjResult *result = AS_RESULT(args[0]);
    return BOOL_VAL(result->status == SUCCESS);
}

void declareResultMethods(CamusVM *vm) {
    defineNative(vm, &vm->resultMethods, "unwrap", unwrap);
    defineNative(vm, &vm->resultMethods, "unwrapError", unwrapError);
    defineNative(vm, &vm->resultMethods, "success", success);

    camusInterpret(vm, "Result", CAMUS_RESULT_SOURCE);

    Value Result;
    tableGet(&vm->modules, copyString(vm, "Result", 6), &Result);

    ObjModule *ResultModule = AS_MODULE(Result);
    push(vm, Result);
    tableAddAll(vm, &ResultModule->values, &vm->resultMethods);
    pop(vm);
}
