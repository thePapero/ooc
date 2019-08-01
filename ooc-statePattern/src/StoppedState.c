#include <time.h>

#include "StoppedState.h"
/* Possible transition to this states */
#include "StartedState.h"

static char* stopStateName = "Stop";

static void startWatch(watchState* state)
{
    transitionToStarted(state); //go to start
}

void transitionToStopped(watchState* state)
{
    /* init the state with default implementation. Clear all state and leave only possible transitions. */
    defaultImplementation(state);
    /* override default implementation only for function we will use */
    state->actualStateName = stopStateName;
    
    time_t startTime = state->elapsedTime;
    time(&(state->elapsedTime));
    state->elapsedTime = state->elapsedTime - startTime;

    state->start = startWatch; //next possible transition
    /* other possible transition goes here */
}