#ifndef _REVPOT_H_
#define _REVPOT_H_

#include "potion.h"
class RevPot : public Potion
{
public:
  RevPot();
  ~RevPot();
  void use(Pokemon &poke);
};

#endif