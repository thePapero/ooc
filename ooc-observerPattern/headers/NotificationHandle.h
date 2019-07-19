/*
 * NotificationHandle.h
 *
 *  Created on: 16 lug 2019
 *      Author: Antonio De Meis
 */

#ifndef HEADERS_NOTIFICATIONHANDLE_H_
#define HEADERS_NOTIFICATIONHANDLE_H_

#include "TMDQueue.h"

typedef struct NotificationHandle NotificationHandle;

struct NotificationHandle {
    UpdateFuncPtr updateAddr;
    struct NotificationHandle* itsNotificationHandle; /* is a linked list */
};

void NotificationHandle_init(NotificationHandle* const me);
void NotificationHandle_cleanup(NotificationHandle* const me);

struct NotificationHandle* NotificationHandle_getItsNotificationHandle(const NotificationHandle* const me);
void NotificationHandle_setItsNotificationHandle(NotificationHandle* const me, struct NotificationHandle* p_NotificationHandle);

NotificationHandle* NotificationHandle_create();
void NotificationHandle_destroy(NotificationHandle* const me);

#endif /* HEADERS_NOTIFICATIONHANDLE_H_ */
