#include "move.h"

Move::Move()
{
    m_type = Type::Element::NORMAL;
    m_power = 0;
    m_acc = 0;
    m_name = "Retard pokemon";
}

Move::Move(Type type, int power, float acc)
{
    set(type, power, acc);
    m_name = "new";
}

Move::Move(int type, int power, float acc)
{
    m_type = type;
    m_power = power;
    m_acc = acc;
    m_name = "New";
}

Move::Move(NameMove name)
{
    set(name);
}

void Move::set(Type type, int power, float acc)
{
    m_type = type;
    m_power = power;
    m_acc = acc;
    m_name = "New";
}

void Move::set(NameMove name)
{
    switch (name)
    {
    case NameMove::BUBBLE:
        m_type = Type::Element::WATER;
        m_power = 40;
        m_acc = 1;
        m_name = "Bubble";
        break;
    case NameMove::WATER_GUN:
        m_type = Type::Element::WATER;
        m_power = 75;
        m_acc = 1;
        m_name = "Water Gun";
        break;
    case NameMove::WATERFALL:
        m_type = Type::Element::WATER;
        m_power = 110;
        m_acc = 1;
        m_name = "Waterfall";
        break;
    case NameMove::THUNDERSHOCK:
        m_type = Type::Element::THUNDER;
        m_power = 40;
        m_acc = 1;
        m_name = "Thundershock";
        break;
    case NameMove::THUNDERBOLT:
        m_type = Type::Element::THUNDER;
        m_power = 90;
        m_acc = 1;
        m_name = "Thunderbolt";
        break;
    case NameMove::THUNDER:
        m_type = Type::Element::THUNDER;
        m_power = 110;
        m_acc = 0.70;
        m_name = "Thunder";
        break;
    case NameMove::FLAMETHROWER:
        m_type = Type::Element::FIRE;
        m_power = 90;
        m_acc = 1;
        m_name = "Flamethrower";
        break;
    case NameMove::FIRE_BLAST:
        m_type = Type::Element::FIRE;
        m_power = 110;
        m_acc = 0.85;
        m_name = "Fire blast";
        break;
    case NameMove::FIRE_SPIN:
        m_type = Type::Element::FIRE;
        m_power = 35;
        m_acc = 0.85;
        m_name = "Fire spin";
        break;
    case NameMove::AURORA_BEAM:
        m_type = Type::Element::ICE;
        m_power = 65;
        m_acc = 1;
        m_name = "Aurora beam";
        break;
    case NameMove::BLIZZARD:
        m_type = Type::Element::ICE;
        m_power = 110;
        m_acc = 0.70;
        m_name = "Blizzard";
        break;
    case NameMove::ICE_BEAM:
        m_type = Type::Element::ICE;
        m_power = 90;
        m_acc = 1;
        m_name = "Ice beam";
        break;
    case NameMove::THRASH:
        m_type = Type::Element::NORMAL;
        m_power = 120;
        m_acc = 1;
        m_name = "Thrash";
        break;
    case NameMove::SCRATCH:
        m_type = Type::Element::NORMAL;
        m_power = 40;
        m_acc = 1;
        m_name = "Scratch";
        break;
    case NameMove::SKULL_BASH:
        m_type = Type::Element::NORMAL;
        m_power = 130;
        m_acc = 1;
        m_name = "Skull bash";
        break;
    case NameMove::ROCK_SLIDE:
        m_type = Type::Element::EARTH;
        m_power = 75;
        m_acc = 0.9;
        m_name = "Rock slide";
        break;
    case NameMove::SOLARBEAM:
        m_type = Type::Element::EARTH;
        m_power = 120;
        m_acc = 1;
        m_name = "Solarbeam";
        break;
    case NameMove::RAZOR_LEAF:
        m_type = Type::Element::EARTH;
        m_power = 55;
        m_acc = 0.95;
        m_name = "Razor leaf";
        break;
    case NameMove::WING_ATTACK:
        m_type = Type::Element::WIND;
        m_power = 60;
        m_acc = 1;
        m_name = "Wing attack";
        break;
    case NameMove::SKY_ATTACK:
        m_type = Type::Element::WIND;
        m_power = 140;
        m_acc = 0.9;
        m_name = "Sky attck";
        break;
    case NameMove::PECK:
        m_type = Type::Element::WIND;
        m_power = 35;
        m_acc = 1;
        m_name = "Peck";
        break;
    }
}

string Move::name() const
{
    return m_name;
}

Type Move::get_Type()
{
    return m_type;
}