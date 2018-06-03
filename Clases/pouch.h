#ifndef _Pou_h_
#define _Pou_h_

#include "pokemon.h"
#include "item.h"
#include "smallpotion.h"
#include "bigpotion.h"
#include "revivepotion.h"

class Pouch
{
public:
  Pouch();
  ~Pouch();
  void add(int itemID, int n = 1);
  bool use(int itemID, Pokemon &poke);
  int qtyleft(int itemID);
  int inv_size();
  string item_name(int itemID);
  string item_desc(int itemID);

private:
  int SmallPotions;
  int BigPotions;
  int RevPotions;
  SmPot sp;
  BPot bp;
  RevPot rp;
};

#endif