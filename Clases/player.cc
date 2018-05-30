#include "player.h"

#include <iostream>

Player::Player()
{
}

Player::Player(vector<Pokemon> pok, vector<Item> it, string name)
{
	set_Pokemon(pok);
	set_Items(it);
	set_name(name);
}

void Player::set_Pokemon(vector<Pokemon> pok)
{
	pokemones = pok;
	return;
}

void Player::set_Items(vector<Item> it)
{
	items = it;
}

void Player::set_name(string name)
{
	(*this).name = name;
}

int Player::num_Pokemon()
{
	return (int)pokemones.size();
}

int Player::num_Items()
{
	return (int)items.size();
}

string Player::name_poke(int n)
{
	if (n > pokemones.size() || n < 0)
		return "No pokemon data.";
	return pokemones[n].name();
}

string Player::name_item(int n)
{
	if (n > items.size() || n < 0)
		return "No item data.";
	return items[n].name;
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
