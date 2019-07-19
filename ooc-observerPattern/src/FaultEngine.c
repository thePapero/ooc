/*
 * FaultEngine.c
 * 
 * A class that act like an observed in observer pattern
 *
 *  Created on: 16 lug 2019
 *      Author: User
 */

#include <stdlib.h>
#include <string.h>
#include "FaultEngine.h"

static void cleanupRelations(FaultEngine* me);

FaultEngine* FaultEngine_create()
{
    FaultEngine* me = (FaultEngine *)malloc(sizeof(FaultEngine));
    if(me != NULL)
    {
        FaultEngine_init(me);
    }
    return me;
}

void FaultEngine_destroy(FaultEngine* const me)
{
    if(me != NULL)
    {
        FaultEngine_cleanup(me);
    }
    free(me);
}

void FaultEngine_init(FaultEngine* const me)
{
    me->itsTMDQueue = NULL;
}

void FaultEngine_cleanup(FaultEngine* const me)
{
    cleanupRelations(me);
}

HES_ErrorType FaultEngine_log(FaultEngine* const me, ubyte2 code, char *desc)
{
    HES_ErrorType status = HES_E_OK;
    ubyte1 seconds = 0;
    ubyte1 minutes = 1;
    ubyte1 hours = 2;
    ubyte1 days = 3;
    ubyte1 months = 4;
    ubyte1 years = 5;
    TimeMarkedData logData;

    logData.seconds = seconds;
    logData.minutes = minutes;
    logData.hours = hours;
    logData.days = days;
    logData.months = months;
    logData.years = years;
    logData.code = code;
    strncpy(logData.desc, desc, TIME_MARKED_DATA_DESC_SIZE);

    TMDQueue_insert(me->itsTMDQueue, logData);

    return status;
}

struct TMDQueue* FaultEngine_getItsTDMSQueue(const FaultEngine* const me)
{
    return (struct TMDQueue*)me->itsTMDQueue;
}

void FaultEngine_setItsTDMSQueue(FaultEngine* const me, struct TMDQueue* p_TMDQueue)
{
    me->itsTMDQueue = p_TMDQueue;
}

static void cleanupRelations(FaultEngine* me)
{
    if(me->itsTMDQueue != NULL)
        me->itsTMDQueue = NULL;
}
