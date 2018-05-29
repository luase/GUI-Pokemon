#include "revivepotion.h"

RevPot::RevPot()
{
    name = "Revive Potion";
    description = "A potion that will fully heal your pokemon";
    usos = 0;
    heal_amount = 0;
}

RevPot::RevPot(int n) : RevPot()
{
    usos = n;
}

void RevPot::use(Pokemon &poke)
{
    if (usos)
    {
        poke.heal();
        usos--;
    }
}