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
    time(&(me->elapsedTime));
}

void digWatch_destroy(DigitalWatch* me)
{
    free(me);
}

void startWatch(DigitalWatch* me)
{
    time(&(me->elapsedTime));
    me->state.start(&(me->state));
}

void stopWatch(DigitalWatch* me)
{
    time_t startTime = me->elapsedTime;
    time(&(me->elapsedTime));
    me->elapsedTime = me->elapsedTime - startTime;
    me->state.stop(&(me->state));
}

void printElapsedTime(DigitalWatch* me)
{
    printf("Elapsed time: %d seconds\n",(int)me->elapsedTime);
}
