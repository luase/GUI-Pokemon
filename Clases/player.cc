#include "player.h"

#include <iostream>

Player::Player()
{
}

Player::Player(vector<Pokemon> pok, Pouch inv, string name)
{
    set_Pokemon(pok);
    set_Items(inv);
    set_name(name);
}

void Player::set_Pokemon(vector<Pokemon> pok)
{
	pokemones = pok;
	return;
}

void Player::set_Items(Pouch inv)
{
    invent = inv;
}

void Player::set_name(string name)
{
	(*this).name = name;
}

int Player::num_Pokemon()
{
	return (int)pokemones.size();
}


string Player::name_poke(int n)
{
	if (n > pokemones.size() || n < 0)
		return "No pokemon data.";
	return pokemones[n].name();
}

int Player::num_Items(){
    return invent.inv_size();
}

string Player::ver_name()
{
	return name;
}

void Player::set_Alive(int a)
{
	vivos = a;
	return;
}

int Player::get_Alive()
{
	return vivos;
}

Pouch Player::get_Items()
{
    return invent;
}

unsigned int Player::size_name()
{
    return (int)name.length();
}

void Player::push(char c)
{
    name += c;
    return;
}

vector<Pokemon> Player::get_Pokemones()
{
	return pokemones;
}

void Player::pop()
{
    string b;
    for(int i=0;i<name.length()-1;i++)
        b+=name[i];
    name=b;
    return;
}
void Player::pop_pok()
{
    pokemones.pop_back();
    return;
}

void Player::new_Pokemon(Pokemon a)
{
    pokemones.push_back(a);
    return;
}

Pokemon Player::get_Pokemon(int a)
{
    return pokemones[a];
}
