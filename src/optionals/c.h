#include "optionals.h"
#include "../vm/vm.h"

#ifndef camus_c_h
#define camus_c_h

#ifndef _GNU_SOURCE
#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 200809L
#endif
#if (_POSIX_C_SOURCE >= 200112L)
#define POSIX_STRERROR
#endif
#endif


// error codes taken from https://github.com/torvalds/linux/blob/master/include/uapi/asm-generic/errno.h
#ifdef __FreeBSD__
#define EHWPOISON 133
#define ENOSTR 60
#define ENODATA 61
#define ETIME 62
#define ENOSR 63
#endif

#include <string.h>
#include <errno.h>

#ifdef __APPLE__
#define LAST_ERROR 106
#elif defined(_WIN32)
#define LAST_ERROR EWOULDBLOCK
#else
#define LAST_ERROR EHWPOISON
#endif

#include "optionals.h"
#include "../include/camus_include.h"
#include "../vm/vm.h"
#include "../vm/memory.h"

Value createCModule(CamusVM *vm);

void getStrerror(char *buf, int error);

#endif //camus_c_h
