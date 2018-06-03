#include "type.h"

Type::Type() {}

Type::Type(Element name)
{
    switch (name)
    {
    case Element::FIRE:
        tipo = 1;
        weakness = 6;
        stronger = 2;
        break;
    case Element::ICE:
        tipo = 2;
        weakness = 1;
        stronger = 3;
        break;
    case Element::WIND:
        tipo = 3;
        weakness = 2;
        stronger = 4;
        break;
    case Element::EARTH:
        tipo = 4;
        weakness = 3;
        stronger = 5;
        break;
    case Element::THUNDER:
        tipo = 5;
        weakness = 4;
        stronger = 6;
        break;
    case Element::WATER:
        tipo = 6;
        weakness = 5;
        stronger = 1;
        break;
    case Element::NORMAL:
        tipo = 7;
        weakness = 0;
        stronger = 0;
    }
}

Type::Type(int tipo)
{
    (*this).tipo = tipo;
}