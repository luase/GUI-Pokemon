#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <iostream>
#include <string>
using namespace std;

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
    
    // Ventana 1: Inicalizar elementos.
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
    
    //Venatana2
    sf::Texture back_window2;
    back_window2.loadFromFile(resourcePath() + "/Backgrounds/background2.jpg");
    sf::Sprite back2(back_window2);
    
    sf::Text name1, name2;
    string player1_name, player2_name;
    
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
            // Avanzar a segunda ventana
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
                    if((char)event.text.unicode!=' ' && event.text.unicode < 128 && player1_name.size() < 10)
                    {
                        player1_name.push_back((char)event.text.unicode);
                        name1.setFont(font);
                        name1.setCharacterSize(15);
                        name1.setString(player1_name);
                        name1.setFillColor(sf::Color::Black);
                        name1.setPosition(175, 140);
                    }
                }
                if(player1_name.size() == 10)
                {
                    if(event.type == sf::Event::TextEntered)
                    {
                        if(event.text.unicode < 128 && player2_name.size()!= 10)
                        {
                            player2_name.push_back((char)event.text.unicode);
                            name2.setFont(font);
                            name2.setCharacterSize(15);
                            name2.setString(player2_name);
                            name2.setFillColor(sf::Color::Black);
                            name2.setPosition(175, 230);
                        }
                    }
                }
                
                if(player1_name.size() == 10 && player2_name.size() == 10)
                {
                    window_controller = 3;
                }
            }
        }
        
        
        switch (window_controller)
        {
            case 1:
                window.clear();
                window.draw(back1);
                window.draw(title_window1);
                window.draw(team);
                window.draw(start);
                break;
            case 2:
                window.clear();
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
        }
        window.display();
    }
    
    return 0;
}

