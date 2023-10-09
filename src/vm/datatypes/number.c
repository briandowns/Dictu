#include "number.h"
#include "../memory.h"

static Value negateNumber(DictuVM *vm, int argCount, Value *args) {
    if (argCount != 0) {
        runtimeError(vm, "negate() takes no arguments (%d given)", argCount);
        return EMPTY_VAL;
    }

    double number = AS_NUMBER(args[0]);

    return NUMBER_VAL(number * -1);
}

static Value toStringNumber(DictuVM *vm, int argCount, Value *args) {
    if (argCount != 0) {
        runtimeError(vm, "toString() takes no arguments (%d given)", argCount);
        return EMPTY_VAL;
    }

    double number = AS_NUMBER(args[0]);
    int numberStringLength = snprintf(NULL, 0, "%.15g", number) + 1;
    
    char *numberString = ALLOCATE(vm, char, numberStringLength);

    if (numberString == NULL) {
        runtimeError(vm, "Memory error on toString()!");
        return EMPTY_VAL;
    }
    
    snprintf(numberString, numberStringLength, "%.15g", number);
    return OBJ_VAL(takeString(vm, numberString, numberStringLength - 1));
}

void declareNumberMethods(DictuVM *vm) {
    defineNative(vm, &vm->numberMethods, "negate", negateNumber);
    defineNative(vm, &vm->numberMethods, "toString", toStringNumber);
    defineNative(vm, &vm->numberMethods, "toBool", boolNative); // Defined in util
}
