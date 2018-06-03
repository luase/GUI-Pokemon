#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include "move.h"
#include "pokemon.h"
#include "type.h"
#include "player.h"
#include "pouch.h"
#include "item.h"
#include "smallpotion.h"
#include "bigpotion.h"
#include "revivepotion.h"

using namespace std;

void list_items(Player &j)
{
    Pouch itms = j.get_Items();
    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << ". usos(" << itms.qtyleft(i + 1) << ") " << itms.item_name(i + 1) << "\t\"" << itms.item_desc(i + 1) << "\"" << endl;
    }
}

void list_pokemons(Player &j)
{
    vector<Pokemon> pkms = j.get_Pokemones();
    int i = 0;
    for (auto it : pkms)
    {
        cout << ++i << ". " << it.name() << "\t - " << it.vida() << "hp\n";
    }
}

void choose_item(Player &j, bool *ver)
{
    int opc = 0;
    int trgtpkm = 0;
    Pokemon pok;
    Pouch itms = j.get_Items();
    vector<Pokemon> pkms = j.get_Pokemones();

    while (opc < 1 || opc > 3)
    {
        cin >> opc;
    }

    if (!itms.qtyleft(opc))
    {
        cout << "Ya no te quedan más " << itms.item_name(opc) << "s. Escoge otra opción.\n";
        list_items(j);
        choose_item(j, ver);
        return;
    }

    cout << "Seleccione un objetivo\n";
    list_pokemons(j);
    while (trgtpkm < 1 || trgtpkm > 5)
    {
        cin >> trgtpkm;
    }
    trgtpkm--;

    pok = pkms[trgtpkm];
    cout << pkms[trgtpkm].name() << " curado!\n";
    itms.use(opc, pok);
    cout << pok.name() << " - " << pok.vida() << "hp\n";
    pkms[trgtpkm] = pok;
    j.set_Items(itms);
    j.set_Pokemon(pkms);

    if (opc == 3)
    {
        if (ver[trgtpkm])
        {
            ver[trgtpkm] = 0;
            int v = j.get_Alive();
            v++;
            j.set_Alive(v);
        }
    }
}

int atack(Pokemon &a, Pokemon &b, Move atac)
{
    int estado = 0;
    int ta = atac.get_Type().tipo;
    float por = 1;
    Type typeb = b.tipo();

    if (ta == typeb.stronger)
    {
        por = 0.5;
        estado = 1;
    }
    if (ta == typeb.weakness)
    {
        por = 1.5;
        estado = 2;
    }

    int acurracy = atac.m_acc * 100;
    srand(time(NULL));
    if ((rand() % 100 + 1) > acurracy)
    {
        estado = 3;
        return estado;
    }

    int at = atac.m_power;
    at *= por;

    int vida = b.vida();
    vida -= at;
    b.changeLife(vida);

    return estado;
}

void change_Pokemon(int n, vector<Pokemon> pok, bool *ver, Pokemon &act, int *posact)
{
    int opc;

    cout << "Jugador " << n << ": Escoge un nuevo Pokemon.\n";

    do
    {
        for (int i = 0; i < 5; i++)
        {
            if (!ver[i])
            {
                cout << i + 1 << ". " << pok[i].name() << ". Vida: " << pok[i].vida() << "." << endl;
            }
        }
        cin >> opc;
        if (opc <= 0 || opc > 5 || ver[opc - 1] == 1)
        {
            cout << "Pokemon no disponible. Elige otro." << endl;
            continue;
        }
    } while (opc <= 0 || opc > 5 || ver[opc - 1] == 1);

    act = pok[opc - 1];
    posact[0] = opc - 1;
}

void moves_Pokemon(int n, vector<Move> mov, Pokemon &a, Pokemon &b, Player &j, bool *ver, int *posact)
{
    cout << "¿Qué deberia hacer " << a.name() << "?" << endl;

    int i = 0;
    for (auto it : mov)
    {
        cout << ++i << ". " << it.name() << "." << endl;
    }

    int opca;
    cin >> opca;

    Move ataque = mov[opca - 1];
    int z = atack(a, b, ataque);

    switch (z)
    {
    case 0:
        cout << "Fue un ataque normal." << endl;
        break;
    case 1:
        cout << "El ataque no hizo mucho daño." << endl;
        break;
    case 2:
        cout << "El ataque fue super efectivo." << endl;
        break;
    case 3:
        cout << "El ataque no hizo ningun daño." << endl;
        break;
    }

    vector<Pokemon> pok = j.get_Pokemones();
    pok[*posact] = b;
    j.set_Pokemon(pok);

    if (b.vida() <= 0)
    {
        ver[posact[0]] = 1;
        cout << "Murió " << b.name() << "." << endl;

        int v = j.get_Alive();
        v--;
        j.set_Alive(v);

        if (v > 0)
        {
            if (n == 1)
                change_Pokemon(2, j.get_Pokemones(), ver, b, posact);
            if (n == 2)
                change_Pokemon(1, j.get_Pokemones(), ver, b, posact);
        }
        else
        {
            if (n == 1)
                cout << "¡Ganó el jugador 1!" << endl;
            if (n == 2)
                cout << "¡Ganó el jugador 2!" << endl;
            return;
        }
    }
    else
    {
        cout << "A " << b.name() << " le queda " << b.vida() << " puntos de vida.\n"
             << endl;
        return;
    }
}

void chose_Pokemon(int n, Player &j)
{
    cout << "Elige los Pokemons del jugador " << n << endl;

    vector<Pokemon> pok;

    for (int i = 0; i < 5; i++)
    {
        cout << "¿Qué Pokemon quieres?" << endl;
        cout << "1. Charmander\t2. Charizard\t3. Articuno\t4. Pidgey\n5. Pidgeot\t6. Bulbasaur\t7. Venusaur\t8. Zapdos\n9. Pikachu\t10. Squirtle\t11. Blastoise\t12. Porygon\n13. Eevee" << endl;
        int num;
        cin >> num;

        switch (num)
        {
        case 1:
            pok.push_back(Pokemon(Pokemon::NomPok::CHARMANDER));
            break;
        case 2:
            pok.push_back(Pokemon(Pokemon::NomPok::CHARIZARD));
            break;
        case 3:
            pok.push_back(Pokemon(Pokemon::NomPok::ARTICUNO));
            break;
        case 4:
            pok.push_back(Pokemon(Pokemon::NomPok::PIDGEY));
            break;
        case 5:
            pok.push_back(Pokemon(Pokemon::NomPok::PIDGEOT));
            break;
        case 6:
            pok.push_back(Pokemon(Pokemon::NomPok::BULBASAUR));
            break;
        case 7:
            pok.push_back(Pokemon(Pokemon::NomPok::VENUSAUR));
            break;
        case 8:
            pok.push_back(Pokemon(Pokemon::NomPok::ZAPDOS));
            break;
        case 9:
            pok.push_back(Pokemon(Pokemon::NomPok::PIKACHU));
            break;
        case 10:
            pok.push_back(Pokemon(Pokemon::NomPok::SQUIRTLE));
            break;
        case 11:
            pok.push_back(Pokemon(Pokemon::NomPok::BLASTOISE));
            break;
        case 12:
            pok.push_back(Pokemon(Pokemon::NomPok::PORYGON));
            break;
        case 13:
            pok.push_back(Pokemon(Pokemon::NomPok::EEVEE));
            break;
        }
    }

    j.set_Pokemon(pok);
    pok.clear();

    return;
}

void chose_Item(int n, Player &j)
{
    cout << "Elige los Items del jugador " << n << endl;

    Pouch items;

    for (int i = 0; i < 5; i++)
    {
        cout << "¿Qué Items quieres?" << endl;
        cout << "1. Small Potion\t2. Big Potion\t3. Revive Potion" << endl;
        int num;
        cin >> num;

        switch (num)
        {
        case 1:
            items.add(1);
            break;
        case 2:
            items.add(2);
            break;
        case 3:
            items.add(3);
            break;
        }
    }

    j.set_Items(items);

    return;
}

int main()
{
    cout << "\n\n\n:::::::::  :::::::: :::    :::::::::::::::::    ::::  :::::::: ::::    :::\n:+:    :+::+:    :+::+:   :+: :+:       +:+:+: :+:+:+:+:    :+::+:+:   :+:\n+:+    +:++:+    +:++:+  +:+  +:+       +:+ +:+:+ +:++:+    +:+:+:+:+  +:+\n+#++:++#+ +#+    +:++#++:++   +#++:++#  +#+  +:+  +#++#+    +:++#+ +:+ +#+\n+#+       +#+    +#++#+  +#+  +#+       +#+       +#++#+    +#++#+  +#+#+#\n#+#       #+#    #+##+#   #+# #+#       #+#       #+##+#    #+##+#   #+#+#\n###        ######## ###    ################       ### ######## ###    ####\n"
         << endl;
    // jugador 1, jugador 2
    Player j1, j2;
    // turno 0 - jugador 1. turno 1 - jugador 2
    int turno = 0, jugada;

    chose_Pokemon(1, j1);
    chose_Pokemon(2, j2);
    chose_Item(1, j1);
    chose_Item(2, j2);
    // tiene 5 pokemons vivos
    j1.set_Alive(5);
    j2.set_Alive(5);
    // pokemon actual 1 (jugador 1). pokemon actual 2 (jugador 2)
    Pokemon act1, act2;
    // si es 0, lo imprime si es 1, no.
    // posact es el indice del VER.
    int posact1, posact2;
    bool ver1[] = {0, 0, 0, 0, 0}, ver2[] = {0, 0, 0, 0, 0};

    for (int i = 0; i < 2; i++)
    {
        if (!i)
            change_Pokemon(1, j1.get_Pokemones(), ver1, act1, &posact1);
        else
            change_Pokemon(2, j2.get_Pokemones(), ver2, act2, &posact2);
    }

    while (j1.get_Alive() && j2.get_Alive())
    {
        cout << "¿Que quieres hacer jugador " << turno + 1 << "?\n1. Atacar\t2. Usar item\t3. Cambiar Pokemon" << endl;
        cin >> jugada;
        vector<Move> mov;
        if (!turno)
        {
            if (jugada == 1)
            {
                moves_Pokemon(1, act1.get_Moves(), act1, act2, j2, ver2, &posact2);
            }
            if (jugada == 2)
            {
                if (!j1.num_Items())
                {
                    cout << "No te quedan items!\n";
                    turno = 0;
                    list_items(j1);
                    continue;
                }
                list_items(j1);
                choose_item(j1, ver1);
            }
            if (jugada == 3)
            {
                change_Pokemon(1, j1.get_Pokemones(), ver1, act1, &posact1);
            }

            turno++;
        }
        else
        {
            if (jugada == 1)
            {
                moves_Pokemon(2, act2.get_Moves(), act2, act1, j1, ver1, &posact1);
            }
            if (jugada == 2)
            {
                if (!j2.num_Items())
                {
                    cout << "No te quedan items!\n";
                    list_items(j2);
                    turno = 1;
                    continue;
                }
                list_items(j2);
                choose_item(j2, ver2);
            }
            if (jugada == 3)
            {
                change_Pokemon(2, j2.get_Pokemones(), ver2, act2, &posact2);
            }

            turno = 0;
        }
    }

    return 0;
}
