#include "argparse.h"

#include "argparse-source.h"

Value createArgParseModule(CamusVM *vm) {
    ObjClosure *closure = compileModuleToClosure(vm, "Argparse", CAMUS_ARGPARSE_SOURCE);

    if (closure == NULL) {
        return EMPTY_VAL;
    }

    return OBJ_VAL(closure);
}
