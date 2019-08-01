#include <stdlib.h>
#include <windows.h>
#include "DigitalWatch.h"

int main()
{
    DigitalWatch digWatch;
    digWatch_constructor(&digWatch);
    printf("Starting digital watch\n");
    startWatch(&digWatch);
    printf("sleep 5 secs\n");
    Sleep(5000);
    printf("Stopping digital watch\n");
    stopWatch(&digWatch);

    printElapsedTime(&digWatch);

    return 0;
}