#ifndef camus_math_h
#define camus_math_h

#include <string.h>
#include <math.h>

#include "optionals.h"
#include "../vm/vm.h"

#define FLOAT_TOLERANCE 0.00001

Value createMathsModule(CamusVM *vm);

#endif //camus_math_h
