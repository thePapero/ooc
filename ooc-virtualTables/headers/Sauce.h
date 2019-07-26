/**
 * Sauce.h
 */

#ifndef _SAUCE_H_
#define _SAUCE_H_

typedef struct SAUCE_VTABLE SAUCE_VTABLE;

/**
 * Base class Sauce
 */
struct Sauce
{
    const SAUCE_VTABLE *vtable;

    int sauceQuantity;
};

void Sauce_constructor(struct Sauce* me);
int Sauce_getSauceQuantity(struct Sauce* me);

void Sauce_addSauce(const struct Sauce* const me);

struct SAUCE_VTABLE
{
    void (*addSauce)(const struct Sauce* const me);
};

#endif
