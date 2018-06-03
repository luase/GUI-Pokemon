#ifndef _POKEMON_H_
#define _POKEMON_H_

#include "type.h"
#include "move.h"
#include <vector>
#include <string>

using namespace std;

class Pokemon
{
protected:
  int o_vida;
  int o_vidamax;
  Type o_type;
  vector<Move> o_moves;
  string o_name;

public:
  enum class NomPok
  {
    CHARMANDER, // FIRE       1
    CHARIZARD,
    ARTICUNO, // ICE        2
    PIDGEY,   // WIND       3
    PIDGEOT,
    BULBASAUR, // EARTH      4
    VENUSAUR,
    ZAPDOS, // THUNDER    5
    PIKACHU,
    SQUIRTLE, // WATER      6
    BLASTOISE,
    PORYGON, // NORMAL     7
    EEVEE
  };

  Pokemon();
  Pokemon(Type type, int vida);
  Pokemon(int type, int vida);
  Pokemon(Type type, int vida, vector<Move> moves);
  Pokemon(NomPok name);

  void setType(Type type);
  void setLife(int vida);
  void setMoves(vector<Move> moves);
  void setPokName(NomPok name);
  void heal();
  void heal(int cac);
  void changeLife(int vida);
  
  vector<Move> get_Moves()const;
  Type tipo() const; // retorna el tipo
  int vida() const;  // retorna la vida
  string name() const;
};

#endif
