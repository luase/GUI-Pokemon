#include "revivepotion.h"

RevPot::RevPot()
{
    name = "Revive Potion";
    description = "A potion that will fully heal your pokemon";
    heal_amount = 0;
    id = 3;
}

RevPot::~RevPot() {}

void RevPot::use(Pokemon &poke)
{
    poke.heal();
}