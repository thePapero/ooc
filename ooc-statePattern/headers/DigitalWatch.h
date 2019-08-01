#include <stdlib.h>
#include "WatchState.h"
#include "StartedState.h"
#include "StoppedState.h"

#ifndef _DIGITAL_WATCH_H
#define _DIGITAL_WATCH_H

typedef struct DigitalWatch DigitalWatch;

struct DigitalWatch
{
    watchState state;
};

DigitalWatch* digWatch_create();

void digWatch_constructor(DigitalWatch* me);

void digWatch_destroy(DigitalWatch* me);

void startWatch(DigitalWatch* me);

void stopWatch(DigitalWatch* me);

void printElapsedTime(DigitalWatch* me);

#endif