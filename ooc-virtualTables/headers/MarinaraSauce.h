/**
 * MarinaraSauce.h
 */

#ifndef _MARINARA_SAUCE_H_
#define _MARINARA_SAUCE_H_

#include "Sauce.h"

/**
 * Concrete class MarinaraSauce
 */
struct MarinaraSauce
{
    struct Sauce base;
    int hasDoubleGarlic;
};

void MarinaraSauce_constructor(struct MarinaraSauce* const me, int dGarlic);
void MarinaraSauce_addSauce(const struct Sauce* const me);

static inline int MarinaraSauce_getSauceQuantity(struct MarinaraSauce* me)
{
    return Sauce_getSauceQuantity(&(me->base)); /* we don't need to override this function. Call base function */
}

#endif
