/**
 * WatchState.h
 */

#ifndef _WATCH_STATE_H_
#define _WATCH_STATE_H_

typedef struct WatchState watchState;

/* function pointer */
typedef void (*eventStartFunc)(watchState*);
typedef void (*eventStopFunc)(watchState*);

struct WatchState {
    char* actualStateName;
    eventStartFunc start;
    eventStopFunc stop;
};

void defaultImplementation(watchState* state);

#endif
