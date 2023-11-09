#ifndef camus_term_h
#define camus_term_h

#ifdef _WIN32
#include "windowsapi.h"
#else
#include <sys/ioctl.h>
#include <unistd.h>
#endif

#include "optionals.h"
#include "../vm/vm.h"
#include "../vm/memory.h"

Value createTermModule(CamusVM *vm);

#endif //camus_term_h
