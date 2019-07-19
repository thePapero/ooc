/*
 * log.c
 *
 *  Created on: 15 lug 2019
 *      Author: Antonio De Meis
 */

#include <stdio.h>
#include <stdlib.h>
#include "log.h"

/** Private methods */
static void cleanupRelations(LogPolicy_Terminal* const me);

LogPolicy_Terminal* LogPolicy_Terminal_Create(struct TMDQueue* p_TMDQueue)
{
    LogPolicy_Terminal* me = (LogPolicy_Terminal *)malloc(sizeof(LogPolicy_Terminal));
    if(me != NULL)
        LogPolicy_Terminal_init(me, p_TMDQueue);
    return me;
}

void LogPolicy_Terminal_Destroy(LogPolicy_Terminal* const me)
{
    if(me != NULL)
    {
        LogPolicy_Terminal_cleanup(me);
    }
    free(me);
}

void LogPolicy_Terminal_init(LogPolicy_Terminal* me, struct TMDQueue* p_TMDQueue)
{
    me->index = 0;
    if(p_TMDQueue != NULL)
    {
        me->itsTMDQueue = p_TMDQueue;
        TMDQueue_subscribe(me->itsTMDQueue, LogPolicy_Terminal_update); /* subscribe LogPolicy_Terminal instance (an observer) to the queue shared with observed (the FaultEngine instance) */
    }   
    else
        me->itsTMDQueue = NULL;
}

void LogPolicy_Terminal_cleanup(LogPolicy_Terminal* const me)
{
    TMDQueue_unsubscribe(me->itsTMDQueue, LogPolicy_Terminal_update); /* unsubscribe from shared queue */
    cleanupRelations(me);
}

void LogPolicy_Terminal_setItsTMDQueue(LogPolicy_Terminal* const me, struct TMDQueue* p_TMDQueue)
{
    if(me->itsTMDQueue != NULL) /* unsubscribe from old queue */
        TMDQueue_unsubscribe(me->itsTMDQueue, LogPolicy_Terminal_update);
    me->itsTMDQueue = p_TMDQueue;
    TMDQueue_subscribe(me->itsTMDQueue, LogPolicy_Terminal_update); /* subscribe to new queue */
}

struct TMDQueue* LogPolicy_Terminal_getItsTMDQueue(LogPolicy_Terminal* const me)
{
    return((struct TMDQueue*)me->itsTMDQueue);
}

void LogPolicy_Terminal_update(LogPolicy_Terminal* const me, struct TimeMarkedData tmd)
{
    LogPolicy_Terminal_Write(tmd.desc);
}

HES_ErrorType LogPolicy_Terminal_Open()
{
    HES_ErrorType status = HES_E_OK;

    return status;
}

HES_ErrorType LogPolicy_Terminal_Close()
{
    HES_ErrorType status = HES_E_OK;

    return status;
}

HES_ErrorType LogPolicy_Terminal_Write(char* const data)
{
    HES_ErrorType status = HES_E_OK;

    printf(data);

    return status;
}

static void cleanupRelations(LogPolicy_Terminal* const me)
{
    if(me->itsTMDQueue != NULL)
        me->itsTMDQueue = NULL;
}
