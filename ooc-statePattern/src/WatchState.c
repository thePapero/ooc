#include <assert.h>
#include "WatchState.h"

/* The default implementation is used to avoid to define all the functions to be pointed at for all the state */
static char* defaultName = "defaultImplementation";

static void defaultStart(watchState* state)
{
    /* the default implementation for the start state */
    assert(0);
}

static void defaultStop(watchState* state)
{
    /* the default implementation for the stop state */
    assert(0);
}

void defaultImplementation(watchState* state)
{
    state->actualStateName = defaultName;
    state->start = defaultStart;
    state->stop = defaultStop;
}