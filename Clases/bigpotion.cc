#include "bigpotion.h"

BPot::BPot()
{
    name = "Big Potion";
    description = "A big potion that heals 100hp";
    heal_amount = 100;
    id = 2;
}

BPot::~BPot() {}

void BPot::use(Pokemon &poke)
{
    poke.heal(heal_amount);
}