#ifndef _ITEM_H_
#define _ITEM_H_

#include <string>
#include "pokemon.h"

class Item
{
  public:
	std::string name;
	std::string description;
	int id;

	Item();
	virtual ~Item();

	virtual void use(Pokemon &poke) = 0;
};

#endif
