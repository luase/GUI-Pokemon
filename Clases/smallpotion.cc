#include "smallpotion.h"

SmPot::SmPot()
{
    name = "Small Potion";
    description = "A small potion that heals 40hp";
    heal_amount = 40;
    id = 1;
}

SmPot::~SmPot() {}

void SmPot::use(Pokemon &poke)
{
    poke.heal(heal_amount);
}