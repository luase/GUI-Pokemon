#ifndef _REVPOT_H_
#define _REVPOT_H_

#include "potion.h"

class RevPot : public Potion
{
public:
  RevPot();
  ~RevPot();
  RevPot(int a);
  void use(Pokemon &poke);
};

#endif