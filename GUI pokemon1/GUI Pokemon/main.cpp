#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "Menu.hpp"
#include <time.h>
#include <stdlib.h>
#include <vector>
#include "move.h"
#include "pokemon.h"
#include "type.h"
#include "player.h"
#include "item.h"


using namespace std;

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
    srand(static_cast<unsigned int>(time(NULL)));
    if ( (rand() % 100 + 1) > acurracy)
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
        cout << "A " << b[0].name() << " le queda " << b[0].vida() << " puntos de vida.\n" << endl;
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

int main(int argc, char const** argv)
{
    sf::RenderWindow window(sf::VideoMode(700, 500), "Pokemon OOP");
    
    //Icono de aplicación
    sf::Image icon;
    icon.loadFromFile(resourcePath() + "/Others/icon.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    //Elementos Globales
    sf::Font font;
    font.loadFromFile(resourcePath() + "/Fonts/Pokemon GB.ttf");
    
    // Ventana 1 ///////////////////////////////////////////////////////////////////////////////////////////////////
    sf::Texture back_window1;
    back_window1.loadFromFile(resourcePath() + "/Backgrounds/background.jpg");
    sf::Sprite back1(back_window1);
    
    sf::Texture title_pokemon;
    title_pokemon.loadFromFile(resourcePath() + "/Others/Title.png");
    sf::Sprite title_window1(title_pokemon);
    title_window1.setPosition(sf::Vector2f(20, 100));
    title_window1.scale(0.25, 0.25);
    
    sf::Text team("\t\t\tAlan Alvarez \tJaime Alonso \tUlises Campos", font, 10);
    team.setFillColor(sf::Color::Black);
    sf::Text start("Press Space", font, 30);
    start.setFillColor(sf::Color::Black);
    start.setPosition(185, 375);
    
    sf::Music music;
    music.openFromFile(resourcePath() + "/Sounds/PokeSong.ogg");
    music.play();
    
    //Venatana2 ///////////////////////////////////////////////////////////////////////////////////////////////////
    
    sf::Texture back_window2;
    back_window2.loadFromFile(resourcePath() + "/Backgrounds/background2.jpg");
    sf::Sprite back2(back_window2);
    int b = 1;
    
    sf::Text name1, name2;
    Player player1, player2;
    //string player1_name, player2_name;
    
    sf::Text setplayer1("Set Player 1 name: ", font, 15);
    setplayer1.setFillColor(sf::Color::Red);
    setplayer1.setPosition(175, 110);
    sf::Text setplayer2("Set Player 2 name: ", font, 15);
    setplayer2.setFillColor(sf::Color::Red);
    setplayer2.setPosition(175, 200);
    
    sf::RectangleShape rectangle1, rectangle2;
    rectangle1.setSize(sf::Vector2f(300, 30));
    rectangle1.setOutlineColor(sf::Color::Black);
    rectangle1.setOutlineThickness(2);
    rectangle1.setPosition(175, 133);
    
    rectangle2.setSize(sf::Vector2f(300, 30));
    rectangle2.setOutlineColor(sf::Color::Black);
    rectangle2.setOutlineThickness(2);
    rectangle2.setPosition(175, 223);
    
    sf::Texture back_charmander, back_squirtle, back_bulbasaur, back_trainer;
    back_charmander.loadFromFile(resourcePath() + "/Others/charmander.png");
    back_squirtle.loadFromFile(resourcePath() + "/Others/squirtle.png");
    back_bulbasaur.loadFromFile(resourcePath() + "/Others/bulbasaur.png");
    back_trainer.loadFromFile(resourcePath() + "/Others/trainer.png");
    sf::Sprite back2_1(back_charmander);
    sf::Sprite back2_2(back_squirtle);
    sf::Sprite back2_3(back_bulbasaur);
    sf::Sprite back2_4(back_trainer);
    
    back2_1.scale(.5, .5);
    back2_2.scale(.5, .5);
    back2_3.scale(.5,.5);
    back2_4.scale(0.5, 0.5);
    
    back2_1.setPosition(160, 320);
    back2_2.setPosition(300, 320);
    back2_3.setPosition(450, 320);
    back2_4.setPosition(-20, 150);
    
    // Ventana 3 ///////////////////////////////////////////////////////////////////////////////////////////////////
    
    sf::Sprite back3;
    back3.setTexture(back_window2);
    sf::Text choose_pokemon;
    vector<string> poke_names;
    poke_names.push_back("Articuno");
    poke_names.push_back("Blastoise");
    poke_names.push_back("Bulbasaur");
    poke_names.push_back("Charizard");
    poke_names.push_back("Charmander");
    poke_names.push_back("Eevee");
    poke_names.push_back("Pidgeot");
    poke_names.push_back("Pidgey");
    poke_names.push_back("Pikachu");
    poke_names.push_back("Porygon");
    poke_names.push_back("Squirtle");
    poke_names.push_back("Venusaur");
    poke_names.push_back("Zapdos");
    
    Menu menu(700, 500, 13, poke_names, 0, 0);
    int a = 1;
    
    sf::Texture poke_temp_window3;
    sf::Sprite poke_back3;
    poke_back3.scale(2, 2);
    poke_back3.setPosition(100, 200);
    
    // Ventana 4 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    int turno = 1;
    sf::Sprite back4;
    back4.setTexture(back_window2);
    sf::RectangleShape text_quad, text_turn;
    text_quad.setSize(sf::Vector2f(690, 140));
    text_quad.setOutlineColor(sf::Color::Black);
    text_quad.setOutlineThickness(5);
    text_quad.setPosition(5, 348);
    sf::Text player_turn;
    player_turn.setFont(font);
    player_turn.setFillColor(sf::Color::Black);
    player_turn.setCharacterSize(10);
    player_turn.setPosition(597, 325);
    text_turn.setSize(sf::Vector2f(100, 20));
    text_turn.setOutlineColor(sf::Color::Black);
    text_turn.setOutlineThickness(5);
    text_turn.setPosition(595, 323);
    vector<string> player1_namepoks;
    bool player1_selected_pok = false;
    Menu select_pokemon;

    
    
    

    
    
    
    // Draw  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //Controlador de venatanas
    int window_controller = 1;
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            // ventana 2
            
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
            {
                    music.stop();
                    window_controller = 2;
            }
                if(event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }
            if (window_controller == 2)
            {
                if(event.type == sf::Event::TextEntered)
                {
                    if((char)event.text.unicode != ' ' && event.text.unicode < 128 && player1.size_name() != 10)
                    {
                        player1.push((char)event.text.unicode);
                        name1.setFont(font);
                        name1.setCharacterSize(15);
                        name1.setString(player1.ver_name());
                        name1.setFillColor(sf::Color::Black);
                        name1.setPosition(175, 140);
                    }
                }
                if(player1.size_name() == 10)
                {
                    if(event.type == sf::Event::TextEntered)
                    {
                        if(event.text.unicode < 256 )
                        {
                            player2.push((char)event.text.unicode);
                            if(player2.size_name() == 1 && b){
                                player2.pop();
                                b = 0;
                            }
                            name2.setFont(font);
                            name2.setCharacterSize(15);
                            name2.setString(player2.ver_name());
                            name2.setFillColor(sf::Color::Black);
                            name2.setPosition(175, 230);
                        }
                    }
                }
                
                if(player1.size_name() == 10 && player2.size_name() == 10)
                {
                    window_controller = 3;
                }
            }
            // Ventana 3
            if(window_controller == 3)
            {
                if(player1.num_Pokemon() < 5 ){
                    choose_pokemon.setString(player1.ver_name() + ": Escoge tus Pokemons.");
                }
                if(player2.num_Pokemon() < 5 && player1.num_Pokemon() == 5){
                    choose_pokemon.setString(player2.ver_name() + ": Escoge tus Pokemons.");
                }
                choose_pokemon.setFont(font);
                choose_pokemon.setCharacterSize(15);
                choose_pokemon.setPosition(100, 10);
                choose_pokemon.setFillColor(sf::Color::Red);
                
                //Moverse en el menú
                if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
                {
                    menu.MoveUp();
                }
                if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
                {
                    menu.MoveDown();
                }
                switch (menu.GetPressedItem()) {
                    case 0:
                        poke_temp_window3.loadFromFile(resourcePath() + "/Pokemons/Articuno/articuno-color.png");
                        break;
                    case 1:
                        poke_temp_window3.loadFromFile(resourcePath() + "/Pokemons/Blastoise/blastoise-color.png");
                        break;
                    case 2:
                        poke_temp_window3.loadFromFile(resourcePath() + "/Pokemons/Bulbasaur/bulbasaur-color.png");
                        break;
                    case 3:
                        poke_temp_window3.loadFromFile(resourcePath() + "/Pokemons/Charizard/charizard-color.png");
                        break;
                    case 4:
                        poke_temp_window3.loadFromFile(resourcePath() + "/Pokemons/Charmander/charmander-color.png");
                        break;
                    case 5:
                        poke_temp_window3.loadFromFile(resourcePath() + "/Pokemons/Eevee/eevee-color.png");
                        break;
                    case 6:
                        poke_temp_window3.loadFromFile(resourcePath() + "/Pokemons/Pidgeot/pidgeot-color.png");
                        break;
                    case 7:
                        poke_temp_window3.loadFromFile(resourcePath() + "/Pokemons/Pidgey/pidgey-color.png");
                        break;
                    case 8:
                        poke_temp_window3.loadFromFile(resourcePath() + "/Pokemons/Pikachu/pikachu-color.png");
                        break;
                    case 9:
                        poke_temp_window3.loadFromFile(resourcePath() + "/Pokemons/Porygon/porygon-color.png");
                        break;
                    case 10:
                        poke_temp_window3.loadFromFile(resourcePath() + "/Pokemons/Squirtle/squirtle-color.png");
                        break;
                    case 11:
                        poke_temp_window3.loadFromFile(resourcePath() + "/Pokemons/Venusaur/venusaur-color.png");
                        break;
                    case 12:
                        poke_temp_window3.loadFromFile(resourcePath() + "/Pokemons/Zapdos/zapdos-color.png");
                        break;
                }
                
                poke_back3.setTexture(poke_temp_window3);
                
                
                //Seleccionar los pokemons
                if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return && player1.num_Pokemon() < 5)
                {
                        
                            switch (menu.GetPressedItem())
                            {
                                case 0:
                                    player1.new_Pokemon(Pokemon(Pokemon::NomPok::ARTICUNO));
                                    break;
                                case 1:
                                    player1.new_Pokemon(Pokemon(Pokemon::NomPok::BLASTOISE));
                                    break;
                                case 2:
                                    player1.new_Pokemon(Pokemon(Pokemon::NomPok::BULBASAUR));
                                    break;
                                case 3:
                                    player1.new_Pokemon(Pokemon(Pokemon::NomPok::CHARIZARD));
                                    break;
                                case 4:
                                    player1.new_Pokemon(Pokemon(Pokemon::NomPok::CHARMANDER));
                                    break;
                                case 5:
                                    player1.new_Pokemon(Pokemon(Pokemon::NomPok::PIDGEOT));
                                    break;
                                case 6:
                                    player1.new_Pokemon(Pokemon(Pokemon::NomPok::EEVEE));
                                    break;
                                case 7:
                                    player1.new_Pokemon(Pokemon(Pokemon::NomPok::PIDGEY));
                                    break;
                                case 8:
                                    player1.new_Pokemon(Pokemon(Pokemon::NomPok::PIKACHU));
                                    break;
                                case 9:
                                    player1.new_Pokemon(Pokemon(Pokemon::NomPok::PORYGON));
                                    break;
                                case 10:
                                    player1.new_Pokemon(Pokemon(Pokemon::NomPok::SQUIRTLE));
                                    break;
                                case 11:
                                    player1.new_Pokemon(Pokemon(Pokemon::NomPok::VENUSAUR));
                                    break;
                                case 12:
                                    player1.new_Pokemon(Pokemon(Pokemon::NomPok::ZAPDOS));
                                    break;
                            }
                }
                if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return && player2.num_Pokemon()< 5 && player1.num_Pokemon() == 5)
                {
                            switch (menu.GetPressedItem())
                            {
                                case 0:
                                    player2.new_Pokemon(Pokemon(Pokemon::NomPok::ARTICUNO));
                                    break;
                                case 1:
                                    player2.new_Pokemon(Pokemon(Pokemon::NomPok::BLASTOISE));
                                    break;
                                case 2:
                                    player2.new_Pokemon(Pokemon(Pokemon::NomPok::BULBASAUR));
                                    break;
                                case 3:
                                    player2.new_Pokemon(Pokemon(Pokemon::NomPok::CHARIZARD));
                                    break;
                                case 4:
                                    player2.new_Pokemon(Pokemon(Pokemon::NomPok::CHARMANDER));
                                    break;
                                case 5:
                                    player2.new_Pokemon(Pokemon(Pokemon::NomPok::PIDGEOT));
                                    break;
                                case 6:
                                    player2.new_Pokemon(Pokemon(Pokemon::NomPok::EEVEE));
                                    break;
                                case 7:
                                    player2.new_Pokemon(Pokemon(Pokemon::NomPok::PIDGEY));
                                    break;
                                case 8:
                                    player2.new_Pokemon(Pokemon(Pokemon::NomPok::PIKACHU));
                                    break;
                                case 9:
                                    player2.new_Pokemon(Pokemon(Pokemon::NomPok::PORYGON));
                                    break;
                                case 10:
                                    player2.new_Pokemon(Pokemon(Pokemon::NomPok::SQUIRTLE));
                                    break;
                                case 11:
                                    player2.new_Pokemon(Pokemon(Pokemon::NomPok::VENUSAUR));
                                    break;
                                case 12:
                                    player2.new_Pokemon(Pokemon(Pokemon::NomPok::ZAPDOS));
                                    break;
                            }
                        
                        if(player2.num_Pokemon() == 1 && a){
                            player2.pop_pok();
                            a = 0;
                        }
                }
            }
            if(player1.num_Pokemon() == 5 && player2.num_Pokemon() == 5 ){
                window_controller = 4;
            }
            if(window_controller ==  4)
            {
                switch (turno) {
                    case 1:
                        player_turn.setString("Player 1");
                        if(player1_selected_pok)
                            turno = 2;
                        break;
                    case 2:
                        player_turn.setString("Player 2");
                        break;
                }
                
                if(player1_namepoks.size() < 5)
                {
                    for(int i = 0; i < 5 ; i++)
                    {
                        player1_namepoks.push_back(player1.name_poke(i));
                    }
                }
                select_pokemon.set(700, 150, 5, player1_namepoks, 0, 350);
                
            }
        }
        
        window.clear();
        
        switch (window_controller)
        {
            case 1:
                window.draw(back1);
                window.draw(title_window1);
                window.draw(team);
                window.draw(start);
                break;
            case 2:
                window.draw(back2);
                window.draw(back2_1);
                window.draw(back2_2);
                window.draw(back2_3);
                window.draw(back2_4);
                window.draw(setplayer1);
                window.draw(setplayer2);
                window.draw(rectangle1);
                window.draw(rectangle2);
                window.draw(name1);
                window.draw(name2);
                break;
            case 3:
                window.draw(back3);
                window.draw(choose_pokemon);
                menu.draw(window);
                window.draw(poke_back3);
                break;
            case 4:
                window.draw(back4);
                window.draw(text_quad);
                window.draw(text_turn);
                window.draw(player_turn);
                select_pokemon.draw(window);
                
                
                break;
        }
        window.display();
    }
    
    return 0;
}

