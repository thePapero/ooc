/*
 * TMDQueue.h
 *
 *  Created on: 16 lug 2019
 *      Author: Antonio De Meis
 */

#ifndef HEADERS_TMDQUEUE_H_
#define HEADERS_TMDQUEUE_H_

#include "common.h"

typedef void (*UpdateFuncPtr)(); /* A pointer to any function */

#pragma pack(push,1)
typedef struct TimeMarkedData{
    ubyte1 seconds;
    ubyte1 minutes;
    ubyte1 hours;
    ubyte1 days;
    ubyte1 months;
    ubyte1 years;
    ubyte2 code;
    char desc[TIME_MARKED_DATA_DESC_SIZE];
} TimeMarkedData;
#pragma pack(pop)

void TimeMarkedData_Init(TimeMarkedData* const data);

struct NotificationHandle;

typedef struct TMDQueue TMDQueue;

struct TMDQueue {
    int head;
    int nSubscribers;
    int size;
    struct TimeMarkedData buffer[QUEUE_SIZE];
    struct NotificationHandle* itsNotificationHandle;
};

void TMDQueue_init(TMDQueue* const me);
void TMDQueue_cleanup(TMDQueue* const me);

int TMDQueue_getNextIndex(TMDQueue* const me, int index);
void TMDQueue_insert(TMDQueue* const me, const struct TimeMarkedData tmd);
bool TMDQueue_isEmpty(TMDQueue* const me);
/**
 * Notify all subscribed observer calling for everyone their own update function (passed with subscribe).
 * This function is called by TMDQueue_insert.
 */
void TMDQueue_notify(TMDQueue* const me, const struct TimeMarkedData tmd);
struct TimeMarkedData TMDQueue_remove(TMDQueue* const me, int index);

/*The NotificationHandle is managede as a linked list, with insertion coming at the end. */
void TMDQueue_subscribe(TMDQueue* const me, const UpdateFuncPtr updateFuncAddr);

int TMDQueue_unsubscribe(TMDQueue* const me, const UpdateFuncPtr updateFuncAddr);

int TMDQueue_getBuffer(const TMDQueue* const me);

struct NotificationHandle* TMDQueue_getItsNotificationHandle(const TMDQueue* const me);

void TMDQueue_setItsNotificationHandle(TMDQueue* const me, struct NotificationHandle* p_NotificationHandle);

TMDQueue* TMDQueue_create();

void TMDQueue_destroy(TMDQueue* const me);

#endif /* HEADERS_TMDQUEUE_H_ */
