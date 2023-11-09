#ifndef camus_uuid_h
#define camus_uuid_h

#include "optionals.h"
#include "../vm/vm.h"
#include "../vm/memory.h"

#ifndef _WIN32
#include <uuid/uuid.h>
#endif 

Value createUuidModule(CamusVM *vm);

#endif //camus_uuid_h
