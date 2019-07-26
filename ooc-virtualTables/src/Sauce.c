#include <assert.h>
#include "Sauce.h"

void Sauce_constructor(struct Sauce* me)
{
    static SAUCE_VTABLE const vtbl = {
        &Sauce_addSauce
    };
    me->vtable = &vtbl;
}

int Sauce_getSauceQuantity(struct Sauce* me)
{
    return me->sauceQuantity;
}

void Sauce_addSauce(const struct Sauce* const me)
{
    //assert(0); //virtual function should never been called
    return (*me->vtable->addSauce)(me);
}