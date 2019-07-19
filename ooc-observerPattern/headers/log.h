/*
 * log_policy.h
 *
 *  Created on: 15 lug 2019
 *      Author: Antonio De Meis
 */

#ifndef HEADERS_LOG_H_
#define HEADERS_LOG_H_

#include "errors.h"
#include "TMDQueue.h"

typedef struct LogPolicy_Terminal LogPolicy_Terminal;

struct LogPolicy_Terminal {
    int index;
    TMDQueue* itsTMDQueue;
};

LogPolicy_Terminal* LogPolicy_Terminal_Create(struct TMDQueue* p_TMDQueue);
void LogPolicy_Terminal_Destroy(LogPolicy_Terminal* me);
void LogPolicy_Terminal_init(LogPolicy_Terminal* me, struct TMDQueue* p_TMDQueue);
void LogPolicy_Terminal_cleanup(LogPolicy_Terminal* const me);

void LogPolicy_Terminal_setItsTMDQueue(LogPolicy_Terminal* const me, struct TMDQueue* p_TMDQueue);
struct TMDQueue* LogPolicy_Terminal_getItsTMDQueue(LogPolicy_Terminal* const me);

/**
 * @brief The callback function that shall be called from TMDQueue_notify. Pass it to TMDQueue_subscribe and TMDQueue_unsubscribe
 */
void LogPolicy_Terminal_update(LogPolicy_Terminal* const me, struct TimeMarkedData tmd);

/**
 * @brief Configura la seriale per l'uso come debug. Dalla chiamata a questa funzione le printf vengono redirezionate verso la seriale.
 */
HES_ErrorType LogPolicy_Terminal_Open();

/**
 * @brief Chiude la seriale
 */
HES_ErrorType LogPolicy_Terminal_Close();

/**
 * @brief Scrive sulla seriale
 */
HES_ErrorType LogPolicy_Terminal_Write(char* const data);

/*************************************************************************************/

/**
 * @brief LogPolicy_nvMem write DEBUG data (fault and errors) to non volatile memory.
 * Fault Data shall be of type FaultLog and debug data shall be of type DebugLog.
 */
typedef struct LogPolicy_nvMem LogPolicy_nvMem;

struct LogPolicy_nvMem {
    int index;
    TMDQueue* itsTMDQueue;
};

LogPolicy_nvMem* LogPolicy_nvMem_Create();
void LogPolicy_nvMem_Destroy(LogPolicy_nvMem* const me);
void LogPolicy_nvMem_init(LogPolicy_nvMem* me);

void LogPolicy_nvMem_setItsTMDQueue(LogPolicy_nvMem* const me, struct TMDQueue* p_TMDQueue);
struct TMDQueue* LogPolicy_nvMem_getItsTMDQueue(LogPolicy_nvMem* const me);

HES_ErrorType LogPolicy_nvMem_Open();
HES_ErrorType LogPolicy_nvMem_Close();
HES_ErrorType LogPolicy_nvMem_Write(char* const data);

#endif /* HEADERS_LOG_H_ */
