#ifndef camus_socket_h
#define camus_socket_h

#include "optionals.h"
#include "../vm/vm.h"
#include "../vm/memory.h"
#include "../vm/object.h"

#ifdef __FreeBSD__
#include <netinet/in.h>
#endif

Value createSocketModule(CamusVM *vm);

#endif //camus_socket_h
