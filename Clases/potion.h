#ifndef _POTION_H_
#define _POTION_H_

#include "item.h"

class Potion : public Item
{
public:
  Potion();
  ~Potion();
  int heal_amount;
  virtual void use(Pokemon &poke) = 0;
};

#endif