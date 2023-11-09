#ifndef camus_include_h
#define camus_include_h

#include <stdbool.h>

#define CAMUS_MAJOR_VERSION "0"
#define CAMUS_MINOR_VERSION "29"
#define CAMUS_PATCH_VERSION "0"

#define CAMUS_STRING_VERSION "Camus Version: " CAMUS_MAJOR_VERSION "." CAMUS_MINOR_VERSION "." CAMUS_PATCH_VERSION "\n"

typedef struct _vm CamusVM;

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
} CamusInterpretResult;

CamusVM *camusInitVM(bool repl, int argc, char *argv[]);

void camusFreeVM(CamusVM *vm);

CamusInterpretResult camusInterpret(CamusVM *vm, char *moduleName, char *source);

#endif //camus_include_h
