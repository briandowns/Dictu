#define _POSIX_C_SOURCE 199309L

#ifdef __APPLE__
#define _XOPEN_SOURCE 600
#else
#define _XOPEN_SOURCE 500
#endif

#ifdef _WIN32
#define localtime_r(TIMER, BUF) localtime_s(BUF, TIMER)
// Assumes length of BUF is 26
#define asctime_r(TIME_PTR, BUF) (asctime_s(BUF, 26, TIME_PTR), BUF)
#define gmtime_r(TIMER, BUF) gmtime_s(BUF, TIMER)
#else
#define HAS_STRPTIME
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "time.h"
#include "optionals.h" 
#include "../vm/vm.h"

#define ISO8601Format "%m/%d/%Y %H:%M:%S %Z"
#define RFC3339Format "%Y-%m-%dT%T%Z"
#define RFC2822Format "%a, %d %b %Y %T %z"

#define AS_TIME(v) ((Time*)AS_ABSTRACT(v)->data)

ObjAbstract* newTimeObj(DictuVM *vm);

typedef struct {
    int64_t wall;
    int64_t mono;
} Time;

void freeTime(DictuVM *vm, ObjAbstract *abstract) {
    FREE(vm, Time, abstract->data);
}

char *timeTypeToString(ObjAbstract *abstract) {
    UNUSED(abstract);

    char *timeString = malloc(sizeof(char) * 7);
    snprintf(timeString, 7, "<Time>");
    return timeString;
}

static Value addTime(DictuVM *vm, int argCount, Value *args) {
    if (argCount != 1) {
        runtimeError(vm, "add() takes 1 argument (%d given)", argCount);
        return EMPTY_VAL;
    }

    if (!IS_NUMBER(args[1])) {
        runtimeError(vm, "Argument needs to be a number");
        return EMPTY_VAL;
    }
    int duration = AS_NUMBER(args[1]);

    Time *t1 = AS_TIME(args[0]);

    ObjAbstract* absT2 = newTimeObj(vm);
    Time *t2 = absT2->data;
    t2->mono = t1->mono + duration;
    t2->wall = t1->wall + duration;

    return OBJ_VAL(absT2);
}

static Value subTime(DictuVM *vm, int argCount, Value *args) {
    if (argCount != 1) {
        runtimeError(vm, "sub() takes 1 argument (%d given)", argCount);
        return EMPTY_VAL;
    }

    if (!IS_NUMBER(args[1])) {
        runtimeError(vm, "Argument needs to be a number");
        return EMPTY_VAL;
    }
    int duration = AS_NUMBER(args[1]);

    Time *t1 = AS_TIME(args[0]);

    ObjAbstract* absT2 = newTimeObj(vm);
    Time *t2 = absT2->data;
    t2->mono = t1->mono - duration;
    t2->wall = t1->wall - duration;

    return OBJ_VAL(absT2);
}

static Value getTZTime(DictuVM *vm, int argCount, Value *args) {
    if (argCount != 0) {
        runtimeError(vm, "getTZ() takes 0 arguments (%d given)", argCount);
        return EMPTY_VAL;
    }

    Time *t1 = AS_TIME(args[0]);
    time_t tVal = t1->wall;

    struct tm local;
    localtime_r(&tVal, &local);

    return OBJ_VAL(copyString(vm, local.tm_zone, strlen(local.tm_zone)));
}

static Value formatTime(DictuVM *vm, int argCount, Value *args) {
    if (argCount != 1) {
        runtimeError(vm, "format() takes 1 argument (%d given)", argCount);
        return EMPTY_VAL;
    }

    if (!IS_STRING(args[1])) {
        runtimeError(vm, "Argument needs to be a string");
        return EMPTY_VAL;
    }
    char *format = AS_STRING(args[1])->chars;

    Time *t1 = AS_TIME(args[0]);
    time_t tVal = t1->wall;

    struct tm local;
    localtime_r(&tVal, &local);
    
    char *tmbuf = ALLOCATE(vm, char, 64);
    char *buf = ALLOCATE(vm, char, 64);

    strftime(tmbuf, 64, format, &local);
    sprintf(buf, "%s", tmbuf);
    ObjString *out = copyString(vm, buf, 64);

    FREE_ARRAY(vm, char, tmbuf, 64);
    FREE_ARRAY(vm, char, buf, 64);
    
    return newResultSuccess(vm, OBJ_VAL(out));
}

static Value toNumberTime(DictuVM *vm, int argCount, Value *args) {
    if (argCount != 0) {
        runtimeError(vm, "toNumber() takes no arguments (%d given)", argCount);
        return EMPTY_VAL;
    }

    Time *t1 = AS_TIME(args[0]);

    return NUMBER_VAL(t1->wall);
}

ObjAbstract* newTimeObj(DictuVM *vm) {
    ObjAbstract *abstract = newAbstract(vm, freeTime, timeTypeToString);
    push(vm, OBJ_VAL(abstract));
    
    struct timespec wall, mono;
    clock_gettime(CLOCK_MONOTONIC, &mono);
    clock_gettime(CLOCK_REALTIME, &wall);

    Time *time = ALLOCATE(vm, Time, 1);

    struct timespec ts;
    timespec_get(&ts, TIME_UTC);
    
    time->mono = mono.tv_sec;
    time->wall = wall.tv_sec;

    /**
     * Setup Time object methods
     */
    defineNative(vm, &abstract->values, "add", addTime);
    defineNative(vm, &abstract->values, "sub", subTime);
    defineNative(vm, &abstract->values, "getTZ", getTZTime);
    defineNative(vm, &abstract->values, "format", formatTime);
    defineNative(vm, &abstract->values, "toNumber", toNumberTime);
    // defineNative(vm, &abstract->values, "since", sinceTime);
    // defineNative(vm, &abstract->values, "addDate", addDateTime);
    // defineNative(vm, &abstract->values, "before", beforeTime);
    // defineNative(vm, &abstract->values, "compare", compareTime);
    // defineNative(vm, &abstract->values, "date", dateTime);// year, month, day
    // defineNative(vm, &abstract->values, "equal", equalTime);

    abstract->data = time;

    pop(vm);

    return abstract;
}

static Value nowTime(DictuVM *vm, int argCount, Value *args) {
    UNUSED(args);

    if (argCount != 0) {
        runtimeError(vm, "now() takes no arguments (%d given)", argCount);
        return EMPTY_VAL;
    }

    return OBJ_VAL(newTimeObj(vm));
}

#ifdef HAS_STRPTIME
static Value parseTime(DictuVM *vm, int argCount, Value *args) {
    if (argCount != 2) {
        runtimeError(vm, "strptime() takes 2 arguments (%d given)", argCount);
        return EMPTY_VAL;
    }

    if (!IS_STRING(args[0]) || !IS_STRING(args[1])) {
        runtimeError(vm, "strptime() arguments must be strings");
        return EMPTY_VAL;
    }

    ObjAbstract* absT2 = newTimeObj(vm);
    Time *t2 = absT2->data;

    struct tm local;
    char *end = strptime(AS_CSTRING(args[1]), AS_CSTRING(args[0]), &local);
    if (end == NULL) {
        return newResultError(vm, "asdf");
    }

    t2->mono = local.tm_sec;
    t2->wall = local.tm_sec;

    return newResultSuccess(vm, OBJ_VAL(absT2));
}
#endif

Value createTimeModule(DictuVM *vm) {
    ObjString *name = copyString(vm, "Time", 4);
    push(vm, OBJ_VAL(name));
    ObjModule *module = newModule(vm, name);
    push(vm, OBJ_VAL(module));

    /**
     * Define Time methods
     */
    defineNative(vm, &module->values, "now", nowTime);
    defineNative(vm, &module->values, "parse", parseTime);

    /**
     * Define Time properties
     */
    defineNativeProperty(vm, &module->values, "SECONDS_PER_MINUTE", NUMBER_VAL(60));
    defineNativeProperty(vm, &module->values, "SECONDS_PER_HOUR", NUMBER_VAL(3600));
    defineNativeProperty(vm, &module->values, "SECONDS_PER_DAY", NUMBER_VAL(86400));
    defineNativeProperty(vm, &module->values, "SECONDS_PER_WEEK", NUMBER_VAL(604800));

    defineNativeProperty(vm, &module->values, "DAYS_PER_400_YEARS", NUMBER_VAL(365*400 + 97));
    defineNativeProperty(vm, &module->values, "DAYS_PER_100_YEARS", NUMBER_VAL(365*100 + 24));
    defineNativeProperty(vm, &module->values, "DAYS_PER_4_YEARS", NUMBER_VAL(365*4 + 1));

    defineNativeProperty(vm, &module->values, "RFC3339", OBJ_VAL(copyString(vm, RFC3339Format, strlen(RFC3339Format))));
    defineNativeProperty(vm, &module->values, "RFC2822", OBJ_VAL(copyString(vm, RFC2822Format, strlen(RFC2822Format))));
    defineNativeProperty(vm, &module->values, "ISO8601", OBJ_VAL(copyString(vm, ISO8601Format, strlen(ISO8601Format))));

    pop(vm);
    pop(vm);

    return OBJ_VAL(module);
}
