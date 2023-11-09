#ifndef camus_datetime_h
#define camus_datetime_h

#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE
#endif
#ifndef __USE_XOPEN
#define __USE_XOPEN
#endif

#include <time.h>

#include "optionals.h"

Value createDatetimeModule(CamusVM *vm);

#endif //camus_datetime_h
