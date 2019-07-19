/*
 * NotificationHandle.c
 *
 *  Created on: 16 lug 2019
 *      Author: Antonio De Meis
 */

#include <stdio.h>
#include <stdlib.h>
#include "NotificationHandle.h"

static void cleanupRelations(NotificationHandle* const me);

void NotificationHandle_init(NotificationHandle* const me)
{
    me->itsNotificationHandle = NULL;
}

void NotificationHandle_cleanup(NotificationHandle* const me)
{
    cleanupRelations(me);
}

struct NotificationHandle* NotificationHandle_getItsNotificationHandle(const NotificationHandle* const me)
{
    return (struct NotificationHandle*)me->itsNotificationHandle;
}

void NotificationHandle_setItsNotificationHandle(NotificationHandle* const me, struct NotificationHandle* p_NotificationHandle)
{
    me->itsNotificationHandle = p_NotificationHandle;
}

NotificationHandle* NotificationHandle_create()
{
    NotificationHandle* me = (NotificationHandle *)malloc(sizeof(NotificationHandle));
    if(me != NULL)
    {
        NotificationHandle_init(me);
    }
    return me;
}

void NotificationHandle_destroy(NotificationHandle* const me)
{
    if(me != NULL)
    {
        NotificationHandle_cleanup(me);
    }
    free(me);
}

static void cleanupRelations(NotificationHandle* const me)
{
    if(me->itsNotificationHandle != NULL)
        me->itsNotificationHandle = NULL;
}
