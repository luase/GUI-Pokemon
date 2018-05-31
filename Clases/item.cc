#include "item.h"

Item::Item() {}
Item::~Item() {}

void Item::use(Pokemon &poke) {}

void Item::add(int a)
{
    usos += a;
}

int Item::usos_restantes()
{
    return usos;
}