#include <stdio.h>
#include "DigitalWatch.h"

DigitalWatch* digWatch_create()
{
    DigitalWatch* me = (DigitalWatch*)malloc(sizeof(DigitalWatch));
    if(me != NULL)
    {
        digWatch_constructor(me);
    }
    return me;
}

void digWatch_constructor(DigitalWatch* me)
{
    transitionToStopped(&(me->state)); //set the initial state
}

void digWatch_destroy(DigitalWatch* me)
{
    free(me);
}

void startWatch(DigitalWatch* me)
{
    me->state.start(&(me->state));
}

void stopWatch(DigitalWatch* me)
{
    me->state.stop(&(me->state));
}

void printElapsedTime(DigitalWatch* me)
{
    printf("Elapsed time: %d seconds\n",(int)me->state.elapsedTime);
}
