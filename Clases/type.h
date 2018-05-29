#ifndef _TYPE_H_
#define _TYPE_H_

struct Type
{
    enum class Element
    {
        FIRE,    // tipo 1
        ICE,     // tipo 2
        WIND,    // tipo 3
        EARTH,   // tipo 4
        THUNDER, // tipo 5
        WATER,   // tipo 6
        NORMAL   // tipo 7
    };

    Type();
    Type(Element name);
    Type(int tipo);

    int tipo;
    int weakness; // la debilidad
    int stronger; // sobre el que tiene ventaja
};

#endif