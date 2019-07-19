#include <stdio.h>
#include <stdlib.h>
#include "log.h"
#include "FaultEngine.h"

int main()
{
    printf("Starting...\n");
    TMDQueue itsTMDQueue;
    FaultEngine itsFaultEngine;
    LogPolicy_Terminal itsLogPolicyTerminal;

    TMDQueue_init(&itsTMDQueue);
    FaultEngine_init(&itsFaultEngine);
    LogPolicy_Terminal_init(&itsLogPolicyTerminal, &itsTMDQueue); /* also register log observer to queue */

    FaultEngine_setItsTDMSQueue(&itsFaultEngine, &itsTMDQueue); /* register log observed to queue */

    FaultEngine_log(&itsFaultEngine, 0, "This is a test log\n"); /* call TMDQueue_insert */

    LogPolicy_Terminal_cleanup(&itsLogPolicyTerminal);
    FaultEngine_cleanup(&itsFaultEngine);
    TMDQueue_cleanup(&itsTMDQueue);

    printf("Closing...\n");
}