/**
 * WatchState.h
 * 
 * Store all possible event that can happen into SM.
 * Store SM object member.
 * All action where delegated to state classes.
 */
#include <time.h>

#ifndef _WATCH_STATE_H_
#define _WATCH_STATE_H_

typedef struct WatchState watchState;

/* function pointer. All possible event that can happen in SM */
typedef void (*eventStartFunc)(watchState*);
typedef void (*eventStopFunc)(watchState*);

struct WatchState {
    time_t elapsedTime;
    char* actualStateName;
    eventStartFunc start;
    eventStopFunc stop;
};

void defaultImplementation(watchState* state);

#endif
