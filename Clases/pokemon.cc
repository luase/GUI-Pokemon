#include "pokemon.h"

Pokemon::Pokemon()
{
    setType(Type::Element::NORMAL);
    setLife(0);
}

Pokemon::Pokemon(NomPok name)
{
    setPokName(name);
}

Pokemon::Pokemon(Type type, int vida)
{
    setType(type);
    setLife(vida);
}

Pokemon::Pokemon(int type, int vida)
{
    setType(type);
    setLife(vida);
}

Pokemon::Pokemon(Type type, int vida, vector<Move> moves) : Pokemon(type, vida)
{
    setMoves(moves);
}

void Pokemon::setType(Type type)
{
    o_type = type;
}

void Pokemon::setLife(int vida)
{
    o_vidamax = vida;
}

void Pokemon::changeLife(int vida)
{
    o_vida = vida;
}

void Pokemon::setMoves(vector<Move> moves)
{
    o_moves = moves;
}

void Pokemon::setPokName(NomPok name)
{
    switch (name)
    {
    case NomPok::CHARMANDER:
        o_vida = 309;
        o_vidamax = 309;
        o_type = Type::Element::FIRE;
        o_name = "Charmander";
        o_moves.push_back(Move::NameMove::FIRE_SPIN);
        o_moves.push_back(Move::NameMove::FIRE_BLAST);
        o_moves.push_back(Move::NameMove::SCRATCH);
        o_moves.push_back(Move::NameMove::SKULL_BASH);
        break;
    case NomPok::CHARIZARD:
        o_vida = 534;
        o_vidamax = 534;
        o_type = Type::Element::FIRE;
        o_name = "Charizard";
        o_moves.push_back(Move::NameMove::FLAMETHROWER);
        o_moves.push_back(Move::NameMove::FIRE_BLAST);
        o_moves.push_back(Move::NameMove::THRASH);
        o_moves.push_back(Move::NameMove::SKULL_BASH);
        break;
    case NomPok::ARTICUNO:
        o_vida = 580;
        o_vidamax = 580;
        o_type = Type::Element::ICE;
        o_name = "Articuno";
        o_moves.push_back(Move::NameMove::AURORA_BEAM);
        o_moves.push_back(Move::NameMove::BLIZZARD);
        o_moves.push_back(Move::NameMove::ICE_BEAM);
        o_moves.push_back(Move::NameMove::SCRATCH);
        break;
    case NomPok::PIDGEY:
        o_vida = 251;
        o_vidamax = 251;
        o_type = Type::Element::WIND;
        o_name = "Pidgey";
        o_moves.push_back(Move::NameMove::WING_ATTACK);
        o_moves.push_back(Move::NameMove::PECK);
        o_moves.push_back(Move::NameMove::SCRATCH);
        o_moves.push_back(Move::NameMove::SKULL_BASH);
        break;
    case NomPok::PIDGEOT:
        o_vida = 469;
        o_vidamax = 469;
        o_type = Type::Element::WIND;
        o_name = "Pidgeot";
        o_moves.push_back(Move::NameMove::WING_ATTACK);
        o_moves.push_back(Move::NameMove::SKY_ATTACK);
        o_moves.push_back(Move::NameMove::SCRATCH);
        o_moves.push_back(Move::NameMove::THRASH);
        break;
    case NomPok::BULBASAUR:
        o_vida = 318;
        o_vidamax = 318;
        o_type = Type::Element::EARTH;
        o_name = "Bulbasaur";
        o_moves.push_back(Move::NameMove::RAZOR_LEAF);
        o_moves.push_back(Move::NameMove::SOLARBEAM);
        o_moves.push_back(Move::NameMove::SCRATCH);
        o_moves.push_back(Move::NameMove::SKULL_BASH);
        break;
    case NomPok::VENUSAUR:
        o_vida = 525;
        o_vidamax = 525;
        o_type = Type::Element::EARTH;
        o_name = "Venusaur";
        o_moves.push_back(Move::NameMove::RAZOR_LEAF);
        o_moves.push_back(Move::NameMove::SOLARBEAM);
        o_moves.push_back(Move::NameMove::ROCK_SLIDE);
        o_moves.push_back(Move::NameMove::SKULL_BASH);
        break;
    case NomPok::ZAPDOS:
        o_vida = 580;
        o_vidamax = 580;
        o_type = Type::Element::THUNDER;
        o_name = "Zapdos";
        o_moves.push_back(Move::NameMove::THUNDER);
        o_moves.push_back(Move::NameMove::THUNDERBOLT);
        o_moves.push_back(Move::NameMove::WING_ATTACK);
        o_moves.push_back(Move::NameMove::THRASH);
        break;
    case NomPok::PIKACHU:
        o_vida = 300;
        o_vidamax = 300;
        o_type = Type::Element::THUNDER;
        o_name = "Pikachu";
        o_moves.push_back(Move::NameMove::THUNDER);
        o_moves.push_back(Move::NameMove::THUNDERBOLT);
        o_moves.push_back(Move::NameMove::SCRATCH);
        o_moves.push_back(Move::NameMove::THRASH);
        break;
    case NomPok::SQUIRTLE:
        o_vida = 314;
        o_vidamax = 314;
        o_type = Type::Element::WATER;
        o_name = "Squirtle";
        o_moves.push_back(Move::NameMove::BUBBLE);
        o_moves.push_back(Move::NameMove::WATER_GUN);
        o_moves.push_back(Move::NameMove::SCRATCH);
        o_moves.push_back(Move::NameMove::THRASH);
        break;
    case NomPok::BLASTOISE:
        o_vida = 530;
        o_vidamax = 530;
        o_type = Type::Element::WATER;
        o_name = "Blastoise";
        o_moves.push_back(Move::NameMove::WATERFALL);
        o_moves.push_back(Move::NameMove::WATER_GUN);
        o_moves.push_back(Move::NameMove::BUBBLE);
        o_moves.push_back(Move::NameMove::SKULL_BASH);
        break;
    case NomPok::PORYGON:
        o_vida = 395;
        o_vidamax = 395;
        o_type = Type::Element::NORMAL;
        o_name = "Porygon";
        o_moves.push_back(Move::NameMove::SKULL_BASH);
        o_moves.push_back(Move::NameMove::SOLARBEAM);
        o_moves.push_back(Move::NameMove::SCRATCH);
        o_moves.push_back(Move::NameMove::THRASH);
        break;
    case NomPok::EEVEE:
        o_vida = 325;
        o_vidamax = 325;
        o_type = Type::Element::NORMAL;
        o_name = "Eevee";
        o_moves.push_back(Move::NameMove::BUBBLE);
        o_moves.push_back(Move::NameMove::FIRE_SPIN);
        o_moves.push_back(Move::NameMove::THUNDER);
        o_moves.push_back(Move::NameMove::AURORA_BEAM);
        break;
    }
}

Type Pokemon::tipo() const
{
    return o_type;
}

int Pokemon::vida() const
{
    return o_vida;
}

string Pokemon::name() const
{
    return o_name;
}

vector<Move> Pokemon::get_Moves() const
{
    return o_moves;
}

void Pokemon::heal()
{
    changeLife(o_vidamax);
}

void Pokemon::heal(int cac)
{
    int nvd = o_vida + cac;
    if (nvd > o_vidamax)
        heal();
    else
        changeLife(nvd);
}