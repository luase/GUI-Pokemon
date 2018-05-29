#ifndef _SMPOT_H_
#define _SMPOT_H_

#include "potion.h"

class SmPot : public Potion
{
public:
  SmPot();
  ~SmPot();
  SmPot(int a);
  void use(Pokemon &poke);
};

#endif