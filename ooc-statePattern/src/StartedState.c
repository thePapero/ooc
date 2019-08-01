#include "StartedState.h"
/* Possible transition to this states */
#include "StoppedState.h"

static char* startStateName = "Start";

static void stopWatch(watchState* state)
{
    transitionToStopped(state); //go to stop
}

void transitionToStarted(watchState* state)
{
    /* init the state with default implementation. Clear all state and leave only possible transitions. */
    defaultImplementation(state);
    /* override default implementation only for function we will use */
    state->actualStateName = startStateName;
    state->stop = stopWatch; //next possible transition
    /* other possible transition goes here */
}