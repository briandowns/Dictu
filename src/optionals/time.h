#ifndef dictu_time_h
#define dictu_time_h

#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE
#endif
#ifndef __USE_XOPEN
#define __USE_XOPEN
#endif

#include <time.h>

#include "optionals.h"

Value createTimeModule(DictuVM *vm);

#endif //dictu_time_h
