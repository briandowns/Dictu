#ifndef camus_path_h
#define camus_path_h

#include <limits.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "optionals.h"
#include "../vm/vm.h"
#include "../vm/memory.h"

#ifdef _WIN32
#include "windowsapi.h"
#else
#include <dirent.h>
#endif

Value createPathModule(CamusVM *vm);

#endif //camus_path_h
