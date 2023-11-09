#ifndef camus_env_h
#define camus_env_h

#include <stdlib.h>
#include <string.h>

#include "../optionals.h"
#include "../../vm/vm.h"

Value createEnvModule(CamusVM *vm);

#endif //camus_env_h
