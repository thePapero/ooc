#include <stdlib.h>
#include "Singleton.h"

static Singleton* singletonInstance = NULL;

Singleton* Singleton_create()
{
    if(singletonInstance == NULL)
    {
        Singleton* me = (Singleton*)malloc(sizeof(Singleton));
        if(me != NULL)
        {
            singletonInstance = me;
            Singleton_init(me);
        }
    }
    return singletonInstance;
}

void Singleton_init(Singleton* me)
{
    me->data0 = 0;
}