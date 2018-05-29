#include "smallpotion.h"

SmPot::SmPot()
{
    name = "Small Potion";
    description = "A small potion that heals 40hp";
    usos = 0;
    heal_amount = 40;
}

SmPot::SmPot(int n) : SmPot()
{
    usos = n;
}

void SmPot::use(Pokemon &poke)
{
    if (usos)
    {
        poke.heal(heal_amount);
        usos--;
    }
}