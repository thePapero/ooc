#include "Sauce.h"
#include "TomatoSauce.h"
#include "MarinaraSauce.h"

int main()
{
    struct TomatoSauce tomato;
    struct MarinaraSauce marinara;

    TomatoSauce_constructor(&(tomato), 1);
    MarinaraSauce_constructor(&(marinara), 1);

    Sauce_addSauce((struct Sauce *)&tomato.base);
    Sauce_addSauce((struct Sauce *)&marinara.base);

    return 0;
}