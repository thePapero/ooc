#include <stdio.h>
#include "TomatoSauce.h"

void TomatoSauce_constructor(struct TomatoSauce* me, int isCooked)
{
    static struct SAUCE_VTABLE const vtbl = {
        &TomatoSauce_addSauce,
    };
    Sauce_constructor(&(me->base)); /* call base class constructor */
    me->base.vtable = &vtbl; /* override vtable */
    me->isCooked = isCooked;
}

void TomatoSauce_addSauce(const struct Sauce* const me)
{
    struct TomatoSauce const * const me_ = (struct TomatoSauce const *)me; /* downcast */
    if(me_->isCooked)
        printf("Added Cooked Tomato Sauce\n");
    else
        printf("Added Tomato Sauce\n");
}
