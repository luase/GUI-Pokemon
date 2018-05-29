#ifndef _ITEM_H_
#define _ITEM_H_

#include <string>
#include "pokemon.h"

struct Item
{
	std::string name;
	std::string description;
	int usos;

	Item();
	virtual ~Item();
	virtual void use();
	void add(int a);
	int usos_restantes();
};

#endif
