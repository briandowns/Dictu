#include "optionals.h"

BuiltinModules modules[] = {
    {"C", &createCModule, false},
    {"Argparse", &createArgParseModule, false},
    {"Math", &createMathsModule, false},
    {"Env", &createEnvModule, true},
    {"IO", &createIOModule, false},
    {"JSON", &createJSONModule, false},
    {"Log", &createLogModule, false},
    {"Path", &createPathModule, false},
    {"Datetime", &createDatetimeModule, false},
    {"Socket", &createSocketModule, false},
    {"Net", &createNetModule, false},
    {"Random", &createRandomModule, false},
    {"Base64", &createBase64Module, false},
    {"Hashlib", &createHashlibModule, false},
    {"Queue", &createQueueModule, false},
    {"Stack", &createStackModule, false},
    {"Sqlite", &createSqliteModule, false},
    {"Process", &createProcessModule, false},
    {"System", &createSystemModule, false},
    {"Term", &createTermModule, false},
#ifndef DISABLE_UUID
    {"UUID", &createUuidModule, false},
#endif
    {"UnitTest", &createUnitTestModule, true},
    {"Inspect", &createInspectModule, false},
    {"Object", &createObjectModule, true},
#ifndef DISABLE_HTTP
    {"HTTP", &createHTTPModule, true},
#endif
    {"BigInt", &createBigIntModule, false},
    {NULL, NULL, false}
};

Value importBuiltinModule(CamusVM *vm, int index) {
    return modules[index].module(vm);
}

int findBuiltinModule(char *name, int length, bool *camusSource) {
    for (int i = 0; modules[i].module != NULL; ++i) {
        if (strncmp(modules[i].name, name, length) == 0) {
            *camusSource = modules[i].camusSource;

            return i;
        }
    }

    return -1;
}
