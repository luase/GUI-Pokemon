#include "pouch.h"

Pouch::Pouch()
{
    SmallPotions = 0;
    BigPotions = 0;
    RevPotions = 0;
}

Pouch::~Pouch() {}

int Pouch::qtyleft(int itemID)
{
    switch (itemID)
    {
    case 1:
        return SmallPotions;
    case 2:
        return BigPotions;
    case 3:
        return RevPotions;
    default:
        return 0;
    }
}

int Pouch::inv_size()
{
    return SmallPotions + BigPotions + RevPotions;
}

void Pouch::add(int itemID, int n)
{
    switch (itemID)
    {
    case 1:
        SmallPotions += n;
        break;
    case 2:
        BigPotions += n;
        break;
    case 3:
        RevPotions += n;
        break;

    default:
        break;
    }
}

bool Pouch::use(int itemID, Pokemon &poke)
{
    int usos = qtyleft(itemID);
    if (!usos)
    {
        return false;
    }

    switch (itemID)
    {
    case 1:
        sp.use(poke);
        SmallPotions--;
        break;
    case 2:
        bp.use(poke);
        BigPotions--;
        break;
    case 3:
        rp.use(poke);
        RevPotions--;
        break;

    default:
        break;
    }

    return true;
}

string Pouch::item_name(int itemID)
{

    switch (itemID)
    {
    case 1:
        return sp.name;
    case 2:
        return bp.name;
    case 3:
        return rp.name;

    default:
        return "";
    }
}

string Pouch::item_desc(int itemID)
{

    switch (itemID)
    {
    case 1:
        return sp.description;
    case 2:
        return bp.description;
    case 3:
        return rp.description;

    default:
        return "";
    }
}