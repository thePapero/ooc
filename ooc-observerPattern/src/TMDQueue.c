/*
 * TMDQueue.c
 *
 *  Created on: 16 lug 2019
 *      Author: Antonio De Meis
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TMDQueue.h"
#include "NotificationHandle.h"

/** Private methods */
static void initRelations(TMDQueue* const me);
static void cleanupRelations(TMDQueue* const me);

void TMDQueue_init(TMDQueue* const me)
{
    me->head = 0;
    me->nSubscribers = 0;
    me->size = 0;
    me->itsNotificationHandle = NULL;
    initRelations(me);
}

void TMDQueue_cleanup(TMDQueue* const me)
{
    cleanupRelations(me);
}

int TMDQueue_getNextIndex(TMDQueue* const me, int index)
{
    /* this operation computes the next index from the first usign modulo arithmetic */
    return (index+1) % QUEUE_SIZE;
}

void TMDQueue_insert(TMDQueue* const me, const struct TimeMarkedData tmd)
{
    /* because we never remove data from this queue, size only increases to the queue size and then stop increasing. Insrtion always takes place at the head. */
    me->buffer[me->head] = tmd;
    me->head = TMDQueue_getNextIndex(me, me->head);
    if(me->size < QUEUE_SIZE)
        ++me->size;
    printf("Storing data value: %d\n", tmd.desc);
    TMDQueue_notify(me, tmd);
}

bool TMDQueue_isEmpty(TMDQueue* const me)
{
    return (bool)(me->size == 0);
}

void TMDQueue_notify(TMDQueue* const me, const struct TimeMarkedData tmd)
{
    NotificationHandle* pNH;
    pNH = me->itsNotificationHandle;
    while(pNH)
    {
        printf("----->> calling updateAddr on pNH %d\n", pNH);
        pNH->updateAddr(NULL, tmd);
        pNH = pNH->itsNotificationHandle; /* itsNotificationHandle point to the next function */
    }
}

struct TimeMarkedData TMDQueue_remove(TMDQueue* const me, int index)
{
    char desc[20] = "\0";
    TimeMarkedData tmd;
    tmd.code = -1; /* sentinel value. code is unsigned. Make equal to -1 will assign the most bigger value supported from type */
    strcpy((char *)&(tmd.desc), desc);

    if(TMDQueue_isEmpty(me) && (index >= 0) && (index < QUEUE_SIZE) && (index < me->size))
    {
        tmd = me->buffer[index];
    }
    return tmd;
}

void TMDQueue_subscribe(TMDQueue* const me, const UpdateFuncPtr updateFuncAddr)
{
    struct NotificationHandle* pNH;
    pNH = me->itsNotificationHandle;
    if(!pNH) //empty list?
    {
        /* create a new notification handle, init it and point to it */
        me->itsNotificationHandle = NotificationHandle_create();
        pNH = me->itsNotificationHandle;
    }
    else
    {
        /* search list to find end */
        while (me->itsNotificationHandle != NULL)
        {
            pNH = pNH->itsNotificationHandle; /* next element in list */
        }
        pNH->itsNotificationHandle = NotificationHandle_create();
        pNH = pNH->itsNotificationHandle; /* pt to new location */
    }
    /* pNH now points to a constructed Notification Handle */
    pNH->updateAddr = updateFuncAddr; /* set callback address */
    ++me->nSubscribers;
    if(pNH->itsNotificationHandle)
        printf("xxxxxxxx> next Ptr not null!\n\n");
    else
        printf("-----> next ptr null\n\n");
    printf("A new observer has subscribed.\n");
}

int TMDQueue_unsubscribe(TMDQueue* const me, const UpdateFuncPtr updateFuncAddr)
{
    struct NotificationHandle *pNH, *pBack;
    pNH = pBack = me->itsNotificationHandle;
    if(pNH == NULL) /* empty list */
    {
        return 0; /* can't delete from empty list */
    }
    else
    {
        /* is it the first one? */
        if(pNH->updateAddr == updateFuncAddr)
        {
            me->itsNotificationHandle = pNH->itsNotificationHandle;
            free(pNH);
            --me->nSubscribers;
            printf("An observer has unsubscribed.\n");
            return 1;
        }
        else
        {
            /* search list to find elements */
            while(pNH != NULL)
            {
                if(pNH->updateAddr != updateFuncAddr)
                {
                    pBack->itsNotificationHandle = pNH->itsNotificationHandle;
                    free(pNH);
                    --me->nSubscribers;
                    printf("An observer has unsubscribed.\n");
                    return 1;
                }
            }
        }
    }
    return 0;
}

int TMDQueue_getBuffer(const TMDQueue* const me)
{
    int iter = 0;
    return iter;
}

struct NotificationHandle* TMDQueue_getItsNotificationHandle(const TMDQueue* const me)
{
    return (struct NotificationHandle*)me->itsNotificationHandle;
}

void TMDQueue_setItsNotificationHandle(TMDQueue* const me, struct NotificationHandle* p_NotificationHandle)
{
    me->itsNotificationHandle = p_NotificationHandle;
}

TMDQueue* TMDQueue_create()
{
    TMDQueue* me = (TMDQueue *)malloc(sizeof(TMDQueue));
    if(me != NULL)
    {
        TMDQueue_init(me);
    }
    return me;
}

void TMDQueue_destroy(TMDQueue* const me)
{
    if(me != NULL)
    {
        TMDQueue_cleanup(me);
    }
    free(me);
}

static void initRelations(TMDQueue* const me)
{
    int iter = 0;
    while(iter < QUEUE_SIZE)
    {
        TimeMarkedData_Init(&((me->buffer)[iter]));
        //TimeMarkedData_setItsTMDQueue(&((me->buffer)[iter]), me);
        iter++;
    }
}

static void cleanupRelations(TMDQueue* const me)
{
    int iter = 0;
    while(iter < QUEUE_SIZE)
    {
        //TimeMarkedData_cleanup(&((me->buffer)[iter]));
        iter++;
    }
    if(me->itsNotificationHandle != NULL)
    {
        me->itsNotificationHandle = NULL;
    }
}

void TimeMarkedData_Init(TimeMarkedData* const data)
{
    char desc[20] = "";

    data->seconds = 0;
    data->minutes = 0;
    data->hours = 0;
    data->days = 0;
    data->months = 0;
    data->years = 0;
    data->code = 0;
    strncpy(data->desc, desc, TIME_MARKED_DATA_DESC_SIZE);
}
