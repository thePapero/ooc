/*
 * FaultEngine.h
 *
 *  Created on: 16 lug 2019
 *      Author: Antonio De Meis
 *
 *  @brief FaultEngine Class is implemented as an observed in observer pattern.
 */

#ifndef HEADERS_FAULTENGINE_H_
#define HEADERS_FAULTENGINE_H_

#include "errors.h"
#include "TMDQueue.h"

typedef struct FaultEngine FaultEngine;

struct FaultEngine {
    TMDQueue* itsTMDQueue;
};

FaultEngine* FaultEngine_create();
void FaultEngine_destroy(FaultEngine* const me);

void FaultEngine_init(FaultEngine* const me);
void FaultEngine_cleanup(FaultEngine* const me);

struct TMDQueue* FaultEngine_getItsTDMSQueue(const FaultEngine* const me);
void FaultEngine_setItsTDMSQueue(FaultEngine* const me, struct TMDQueue* p_TMDQueue);

HES_ErrorType FaultEngine_log(FaultEngine* const me, ubyte2 code, char* desc);

#endif /* HEADERS_FAULTENGINE_H_ */
