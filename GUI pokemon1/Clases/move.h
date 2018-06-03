#ifndef _MOVE_H_
#define _MOVE_H_

#include "type.h"
#include <string>

using namespace std;

class Move
{
protected:
  Type m_type;
  string m_name;

public:

  int m_power;
  float m_acc;

  enum class NameMove
  {
    BUBBLE, // Water
    WATER_GUN,
    WATERFALL,
    THUNDERSHOCK, // Thunder
    THUNDERBOLT,
    THUNDER,
    FLAMETHROWER, //Fire
    FIRE_BLAST,
    FIRE_SPIN,
    AURORA_BEAM, // Ice
    BLIZZARD,
    ICE_BEAM,
    THRASH, // Normal
    SCRATCH,
    SKULL_BASH,
    ROCK_SLIDE, //Earth
    SOLARBEAM,
    RAZOR_LEAF,
    WING_ATTACK, //WInd
    SKY_ATTACK,
    PECK
  };

  Move();
  Move(Type type, int power, float acc);
  Move(int type, int power, float acc);
  Move(NameMove name);

  Type get_Type();
  void set(Type type, int power, float acc);
  void set(NameMove name);
  string name() const;

};

#endif
