#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "pokemon.h"
#include "item.h"
#include "pouch.h"
#include <string>

using namespace std;

class Player
{
protected:
	Pouch invent;
	string name;
	vector<Pokemon> pokemones;
	int vivos;

public:
	Player();
	Player(vector<Pokemon>, Pouch, string name);
	void set_Pokemon(vector<Pokemon>);
	void set_Items(Pouch);
	void set_name(string name);
	void set_Alive(int);
	int get_Alive();
    void new_Pokemon(Pokemon);
	int num_Pokemon();
	int num_Items();
    unsigned int size_name();
	vector<Pokemon> get_Pokemones();
    Pouch get_Items();
	string name_poke(int n);
	string ver_name();
    void push(char);
    void pop();
    void pop_pok();
    Pokemon get_Pokemon(int);
};

#endif