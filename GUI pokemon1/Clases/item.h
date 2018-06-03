#ifndef _ITEM_H_
#define _ITEM_H_

#include <string>
#include "pokemon.h"


class Item
{
  public:
	std::string name;
	std::string description;
	int usos;
	Item();
	virtual ~Item();
	virtual void use(Pokemon &poke);
	void add(int a);
	int usos_restantes();
};

#endif
