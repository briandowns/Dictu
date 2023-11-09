#ifndef camus_sqlite_h
#define camus_sqlite_h

#ifdef INCLUDE_SQLITE_LIB
#include <sqlite3.h>
#else
#include "sqlite/sqlite3.h"
#endif


#include "optionals.h"
#include "../vm/vm.h"

Value createSqliteModule(CamusVM *vm);

#endif //camus_sqlite_h
