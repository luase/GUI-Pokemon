#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "pokemon.h"
#include "item.h"
#include <string>

using namespace std;

class Player
{
protected:
	vector<Item> items;
	string name;
	vector<Pokemon> pokemones;
	int vivos;

public:
	Player();
	Player(vector<Pokemon>, vector<Item>, string name);
	void set_Pokemon(vector<Pokemon>);
	void set_Items(vector<Item>);
	void set_name(string name);
	void set_Alive(int);
	int get_Alive();
	int num_Pokemon();
	int num_Items();
	vector<Pokemon> get_Pokemones();
	string name_poke(int n);
	string name_item(int n);
	string ver_name(Player p);
};

#endif
