#ifndef _BPOT_H_
#define _BPOT_H_

#include "potion.h"

class BPot : public Potion
{
public:
  BPot();
  ~BPot();
  void use(Pokemon &poke);
};

#endif