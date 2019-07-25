#include <stdio.h>
#include "Singleton.h"

int main()
{
    Singleton* object1 = Singleton_create();
    Singleton* object2 = Singleton_create();
    printf("I am object1 instance: %d\n", (int)object1);
    printf("I am object2 instance: %d\n", (int)object2);

    return 0;
}