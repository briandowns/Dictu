#ifndef camus_random_h
#define camus_random_h

#include <stdlib.h>
#include <time.h>

#include "optionals.h"
#include "../vm/vm.h"

Value createRandomModule(CamusVM *vm);

#endif //camus_random_h
