#ifndef camus_json_h
#define camus_json_h

#include "json/jsonParseLib.h"
#include "json/jsonBuilderLib.h"
#include "optionals.h"
#include "../vm/vm.h"

Value createJSONModule(CamusVM *vm);

#endif //camus_json_h
