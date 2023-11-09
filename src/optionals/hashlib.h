#ifndef camus_hashlib_h
#define camus_hashlib_h

#include "optionals.h"
#include "hashlib/utils.h"
#include "hashlib/sha256.h"
#include "hashlib/hmac.h"
#include "hashlib/bcrypt/bcrypt.h"

Value createHashlibModule(CamusVM *vm);

#endif //camus_hashlib_h
