#include <string.h>
#include <time.h>

//#include "archive.h"
#include "optionals.h"
#include "../vm/vm.h"

static Value tar(DictuVM *vm, int argCount, Value *args) {
    UNUSED(vm);
    UNUSED(argCount);
    UNUSED(args);
    return OBJ_VAL(NULL);
}

static Value untar(DictuVM *vm, int argCount, Value *args) {
    UNUSED(vm);
    UNUSED(argCount);
    UNUSED(args);
    return OBJ_VAL(NULL);
}

Value createArchiveModule(DictuVM *vm) {
    ObjString *name = copyString(vm, "Archive", 7);
    push(vm, OBJ_VAL(name));
    ObjModule *module = newModule(vm, name);
    push(vm, OBJ_VAL(module));

    /**
     * Define Archive methods
     */
    defineNative(vm, &module->values, "tar", tar);
    defineNative(vm, &module->values, "untar", untar);

    pop(vm);
    pop(vm);

    return OBJ_VAL(module);
}
