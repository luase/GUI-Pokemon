#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include "move.h"
#include "pokemon.h"
#include "type.h"
#include "player.h"
#include "item.h"
#include "smallpotion.h"
#include "bigpotion.h"
#include "revivepotion.h"

using namespace std;

void list_items(Player *j)
{
    vector<Item> itms = j[0].get_Items();
    int i = 0;
    for (auto it : itms)
    {
        cout << ++i << ". usos(" << it.usos_restantes() << ") " << it.name << "\t\"" << it.description << "\"" << endl;
    }
}

void list_pokemons(Player *j)
{
    vector<Pokemon> pkms = j[0].get_Pokemones();
    int i = 0;
    for (auto it : pkms)
    {
        cout << ++i << ". " << it.name() << "\t - " << it.vida() << "hp\n";
    }
}

void choose(Player *j)
{
    int opc = 0;
    int trgtpkm = 0;
    vector<Item> itms = j[0].get_Items();
    vector<Pokemon> pkms = j[0].get_Pokemones();

    while (opc < 1 || opc > 3)
    {
        cin >> opc;
    }

    opc--;

    if (!itms[opc].usos_restantes())
    {
        cout << "Ya no te quedan más " << itms[opc].name << "s. Escoge otra opción.\n";
        list_items(&j[0]);
        choose(&j[0]);
        return;
    }
    cout << "Seleccione un objetivo\n";
    list_pokemons(&j[0]);
    while (trgtpkm < 1 || trgtpkm > 5)
    {
        cin >> trgtpkm;
    }
    trgtpkm--;

    cout << pkms[trgtpkm].name() << " curado!\n";
    itms[opc].use(pkms[trgtpkm]);
    cout << pkms[trgtpkm].name() << " - " << pkms[trgtpkm].vida() << "hp\n";
    j[0].set_Items(itms);
    j[0].set_Pokemon(pkms);
}

int atack(Pokemon *a, Pokemon *b, Move atac)
{
    int estado = 0;
    int ta = atac.get_Type().tipo;
    float por = 1;
    Type typeb = b->tipo();

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

    int vida = b->vida();
    vida -= at;
    b->setLife(vida);

    return estado;
}

void change_Pokemon(int n, vector<Pokemon> pok, bool *ver, Pokemon *act, int *posact)
{
    int opc;

    if (n == 1)
        cout << "Jugador 1: Escoge un nuevo Pokemon.\n"
             << endl;
    if (n == 2)
        cout << "Jugador 2: Escoge un nuevo Pokemon.\n"
             << endl;

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

    act[0] = pok[opc - 1];
    posact[0] = opc - 1;

    return;
}

void moves_Pokemon(int n, vector<Move> mov, Pokemon *a, Pokemon *b, Player *j, bool *ver, int *posact)
{
    cout << "¿Qué deberia hacer " << a->name() << "?" << endl;

    for (int i = 0; i < 4; i++)
    {
        cout << i + 1 << ". " << mov[i].name() << "." << endl;
    }

    int opca;
    cin >> opca;

    Move ataque = mov[opca - 1];
    int z = atack(&a[0], &b[0], ataque);

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

    vector<Pokemon> pok = j[0].get_Pokemones();
    pok[posact[0]] = a[0];
    j[0].set_Pokemon(pok);

    if (b[0].vida() <= 0)
    {
        ver[posact[0]] = 1;
        cout << "Murió " << b[0].name() << "." << endl;

        int v = j[0].get_Alive();
        v--;
        j[0].set_Alive(v);

        if (v > 0)
        {
            if (n == 1)
                change_Pokemon(2, j[0].get_Pokemones(), ver, &b[0], &posact[0]);
            if (n == 2)
                change_Pokemon(1, j[0].get_Pokemones(), ver, &b[0], &posact[0]);
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
        cout << "A " << b[0].name() << " le queda " << b[0].vida() << " puntos de vida.\n"
             << endl;
        return;
    }
}

void chose_Pokemon(int n, Player *j)
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

    j[0].set_Pokemon(pok);
    pok.clear();

    return;
}

void chose_Item(int n, Player *j)
{
    cout << "Elige los Items del jugador " << n << endl;

    int smpot = 0, bpot = 0, revpot = 0;

    for (int i = 0; i < 5; i++)
    {
        cout << "¿Qué Items quieres?" << endl;
        cout << "1. Small Potion\t2. Big Potion\t3. Revive Potion" << endl;
        int num;
        cin >> num;

        switch (num)
        {
        case 1:
            smpot++;
            break;
        case 2:
            bpot++;
            break;
        case 3:
            revpot++;
            break;
        }
    }
    vector<Item> itms;

    itms.push_back(SmPot(smpot));
    itms.push_back(BPot(bpot));
    itms.push_back(RevPot(revpot));

    j[0].set_Items(itms);
    itms.clear();

    return;
}

int main()
{
    cout << "\n\n\n:::::::::  :::::::: :::    :::::::::::::::::    ::::  :::::::: ::::    :::\n:+:    :+::+:    :+::+:   :+: :+:       +:+:+: :+:+:+:+:    :+::+:+:   :+:\n+:+    +:++:+    +:++:+  +:+  +:+       +:+ +:+:+ +:++:+    +:+:+:+:+  +:+\n+#++:++#+ +#+    +:++#++:++   +#++:++#  +#+  +:+  +#++#+    +:++#+ +:+ +#+\n+#+       +#+    +#++#+  +#+  +#+       +#+       +#++#+    +#++#+  +#+#+#\n#+#       #+#    #+##+#   #+# #+#       #+#       #+##+#    #+##+#   #+#+#\n###        ######## ###    ################       ### ######## ###    ####\n"
         << endl;

    Player j1, j2;
    int turno = 0, jugada;

    chose_Pokemon(1, &j1);
    chose_Pokemon(2, &j2);

    chose_Item(1, &j1);
    chose_Item(2, &j2);

    j1.set_Alive(5);
    j2.set_Alive(5);

    Pokemon act1, act2;
    int posact1, posact2;
    bool ver1[] = {0, 0, 0, 0, 0}, ver2[] = {0, 0, 0, 0, 0};

    for (int i = 0; i < 2; i++)
    {
        if (!i)
            change_Pokemon(1, j1.get_Pokemones(), ver1, &act1, &posact1);
        else
            change_Pokemon(2, j2.get_Pokemones(), ver2, &act2, &posact2);
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
                moves_Pokemon(1, act1.get_Moves(), &act1, &act2, &j2, ver2, &posact2);
            }
            if (jugada == 2)
            {
                if (!j1.num_Items())
                {
                    cout << "No te quedan items!\n";
                    turno = 0;
                    list_items(&j1);
                    continue;
                }
                list_items(&j1);
                choose(&j1);
            }
            if (jugada == 3)
            {
                change_Pokemon(1, j1.get_Pokemones(), ver1, &act1, &posact1);
            }

            turno++;
        }
        else
        {
            if (jugada == 1)
            {
                moves_Pokemon(2, act2.get_Moves(), &act2, &act1, &j1, ver1, &posact1);
            }
            if (jugada == 2)
            {
                if (!j2.num_Items())
                {
                    cout << "No te quedan items!\n";
                    list_items(&j2);
                    turno = 1;
                    continue;
                }
                list_items(&j2);
                choose(&j2);
            }
            if (jugada == 3)
            {
                change_Pokemon(2, j2.get_Pokemones(), ver2, &act2, &posact2);
            }

            turno = 0;
        }
    }

    return 0;
}
