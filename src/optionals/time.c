#define _POSIX_C_SOURCE 199309L

#include <stdlib.h>
#include <time.h>

#include "optionals.h"
#include "time.h"
#include "../vm/vm.h"

#define ISO8601Format "%m/%d/%Y %H:%M:%S %Z"
#define RFC3339Format "%Y-%m-%dT%T%Z"

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
    
    return newResultSuccess(vm, OBJ_VAL(copyString(vm, buf, 64)));
}

ObjAbstract* newTimeObj(DictuVM *vm) {
    ObjAbstract *abstract = newAbstract(vm, freeTime, timeTypeToString);
    push(vm, OBJ_VAL(abstract));
    
    struct timespec wall, mono;
    clock_gettime(CLOCK_MONOTONIC, &mono);
    clock_gettime(CLOCK_REALTIME, &wall);

    Time *time = ALLOCATE(vm, Time, 1);

    time->mono = mono.tv_sec;
    time->wall = wall.tv_sec;

    /**
     * Setup Time object methods
     */
    defineNative(vm, &abstract->values, "add", addTime);
    defineNative(vm, &abstract->values, "sub", subTime);
    defineNative(vm, &abstract->values, "format", formatTime);
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

Value createTimeModule(DictuVM *vm) {
    ObjString *name = copyString(vm, "Time", 4);
    push(vm, OBJ_VAL(name));
    ObjModule *module = newModule(vm, name);
    push(vm, OBJ_VAL(module));

    /**
     * Define Datetime methods
     */
    defineNative(vm, &module->values, "now", nowTime);

    /**
     * Define Datetime properties
     */
    defineNativeProperty(vm, &module->values, "SECONDS_IN_MINUTE", NUMBER_VAL(60));
    defineNativeProperty(vm, &module->values, "SECONDS_IN_HOUR", NUMBER_VAL(3600));
    defineNativeProperty(vm, &module->values, "SECONDS_IN_DAY", NUMBER_VAL(86400));
    defineNativeProperty(vm, &module->values, "SECONDS_IN_WEEK", NUMBER_VAL(604800));

    defineNativeProperty(vm, &module->values, "RFC3339", OBJ_VAL(copyString(vm, RFC3339Format, strlen(RFC3339Format))));
    defineNativeProperty(vm, &module->values, "ISO8601", OBJ_VAL(copyString(vm, ISO8601Format, strlen(ISO8601Format))));

    pop(vm);
    pop(vm);

    return OBJ_VAL(module);
}
