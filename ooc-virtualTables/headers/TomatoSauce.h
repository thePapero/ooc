/**
 * TomatoSauce.h
 */
#ifndef _TOMATO_SAUCE_H_
#define _TOMATO_SAUCE_H_

#include "Sauce.h"

struct TomatoSauce
{
    struct Sauce base;
    int isCooked;
};

void TomatoSauce_constructor(struct TomatoSauce* me, int isCooked);
void TomatoSauce_addSauce(const struct Sauce* const me);

static inline int TomatoSauce_getSauceQuantity(struct TomatoSauce* me)
{
    return Sauce_getSauceQuantity(&(me->base)); /* we don't need to override this function. Call base function */
}

/* when introducing new virtual functions we can introduce TOMATO_SAUCE_VTABLE that inherit SAUCE_VTABLE */

#endif
