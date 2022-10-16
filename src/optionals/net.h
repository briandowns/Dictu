#ifndef dictu_net_h
#define dictu_net_h

#include "optionals.h"
#include "../vm/vm.h"
#include "../vm/memory.h"
#include "../vm/object.h"

#ifdef __FreeBSD__
#include <netinet/in.h>
#endif

Value createNetModule(DictuVM *vm);

#endif //dictu_net_h
