#include "re.h"

#define AS_RE(v) ((regex_t*)AS_ABSTRACT(v)->data)

static Value reCompileNative(DictuVM *vm, int argCount, Value *args) {
    if (argCount != 1) {
        runtimeError(vm, "isatty() takes 1 argument (%d given)", argCount);
        return EMPTY_VAL;
    }

    if (!IS_NUMBER(args[0])) {
        runtimeError(vm, "arg passed to isatty must be a number.");
        return EMPTY_VAL;
    }

    if (isatty(AS_NUMBER(args[0]))) {
        return BOOL_VAL(true);
    }

    return BOOL_VAL(false);
}

static Value reMatchpNative(DictuVM *vm, int argCount, Value *args) {
    if (argCount != 1) {
        runtimeError(vm, "isatty() takes 1 argument (%d given)", argCount);
        return EMPTY_VAL;
    }

    if (!IS_NUMBER(args[0])) {
        runtimeError(vm, "arg passed to isatty must be a number.");
        return EMPTY_VAL;
    }

    if (isatty(AS_NUMBER(args[0]))) {
        return BOOL_VAL(true);
    }

    return BOOL_VAL(false);
}

static Value reMatchNative(DictuVM *vm, int argCount, Value *args) {
    if (argCount != 1) {
        runtimeError(vm, "isatty() takes 1 argument (%d given)", argCount);
        return EMPTY_VAL;
    }

    if (!IS_NUMBER(args[0])) {
        runtimeError(vm, "arg passed to isatty must be a number.");
        return EMPTY_VAL;
    }

    if (isatty(AS_NUMBER(args[0]))) {
        return BOOL_VAL(true);
    }

    return BOOL_VAL(false);
}


Value createReModule(DictuVM *vm) {
    ObjString *name = copyString(vm, "RE", 2);
    push(vm, OBJ_VAL(name));
    ObjModule *module = newModule(vm, name);
    push(vm, OBJ_VAL(module));

    /**
     * Define RE methods
     */
    defineNative(vm, &module->values, "compile", reCompileNative);
    defineNative(vm, &module->values, "matchp", reMatchpNative);
    defineNative(vm, &module->values, "match", reMatchNative);

    /**
     * Define RE properties
     */

    pop(vm);
    pop(vm);

    return OBJ_VAL(module);
}
