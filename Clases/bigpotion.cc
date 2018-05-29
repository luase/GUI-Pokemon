#include "bigpotion.h"

BPot::BPot()
{
    name = "Big Potion";
    description = "A big potion that heals 100hp";
    usos = 0;
    heal_amount = 100;
}

BPot::BPot(int n) : BPot()
{
    usos = n;
}

void BPot::use(Pokemon &poke)
{
    if (usos)
    {
        poke.heal(heal_amount);
        usos--;
    }
}