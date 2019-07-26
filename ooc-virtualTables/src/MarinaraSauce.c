#include <stdio.h>
#include "MarinaraSauce.h"

void MarinaraSauce_constructor(struct MarinaraSauce* const me, int dGarlic)
{
    SAUCE_VTABLE vtbl = {
        &MarinaraSauce_addSauce
    };
    Sauce_constructor(&(me->base));
    me->base.vtable = &vtbl;
    me->hasDoubleGarlic = dGarlic;
}

void MarinaraSauce_addSauce(const struct Sauce* const me)
{
    const struct MarinaraSauce* const me_ = (struct MarinaraSauce*)me;
    if(me_->hasDoubleGarlic)
        printf("Added Marinara Sauce with double garlic\n");
    else
        printf("Added Marinara Sauce\n");
    
}