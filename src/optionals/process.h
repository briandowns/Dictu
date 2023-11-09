#ifndef camus_process_h
#define camus_process_h

#ifndef _WIN32
#include <sys/wait.h>
#endif // !_WIN32

#include "optionals.h"

Value createProcessModule(CamusVM *vm);

#endif //camus_process_h
