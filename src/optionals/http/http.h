#ifndef camus_http_h
#define camus_http_h

#include "../optionals.h"
#include "../../vm/vm.h"

#ifndef DISABLE_HTTP
#include <curl/curl.h>
#endif

typedef struct response {
    CamusVM *vm;
    ObjList *headers;
    char *res;
    size_t len;
    long statusCode;
    bool firstIteration;
} Response;

Value createHTTPModule(CamusVM *vm);

#endif //camus_http_h
