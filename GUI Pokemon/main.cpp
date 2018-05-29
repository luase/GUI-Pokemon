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
    if (!icon.loadFromFile(resourcePath() + "/Others/icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    //backgrounds
    sf::Texture texture;
    sf::Texture backgrund2;
    if (!texture.loadFromFile(resourcePath() + "/Backgrounds/background.jpg")) {
        return EXIT_FAILURE;
    }
    if (!backgrund2.loadFromFile(resourcePath() + "/Backgrounds/background2.jpg")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);
    sf::Sprite back2(backgrund2);
    
    //Titulo ventana1
    sf::Texture titulo;
    if (!titulo.loadFromFile(resourcePath() + "/Others/ZBattle/Title.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite titulo1(titulo);
    titulo1.setPosition(sf::Vector2f(30, 125));
    
    //Fuente
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "Pokemon GB.ttf")) {
        return EXIT_FAILURE;
    }
    //Ventana 1
    sf::Text text("\t\t\t\tAlan Antonio \tJaime Saul \tUlises ", font, 10);
    text.setFillColor(sf::Color::Black);
    sf::Text start("Press Space", font, 30);
    start.setFillColor(sf::Color::Black);
    start.setPosition(175, 375);
    sf::Music music;
    if (!music.openFromFile(resourcePath() + "PokeSong.ogg")) {
        return EXIT_FAILURE;
    }
    music.play();
    
    //Venatana2
    sf::Text name1, name2;
    string player1, player2;
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
    
    sf::Texture charmander, squirtle, bulbasaur, trainer;
    charmander.loadFromFile(resourcePath() + "charizard.png");
    squirtle.loadFromFile(resourcePath() + "squirtle.png");
    bulbasaur.loadFromFile(resourcePath() + "bulbasaur.png");
    trainer.loadFromFile(resourcePath() + "trainer.png");
    sf::Sprite charma(charmander);
    sf::Sprite squir(squirtle);
    sf::Sprite bulba(bulbasaur);
    sf::Sprite train(trainer);
    
    charma.scale(.5, .5);
    squir.scale(.5, .5);
    bulba.scale(.5,.5);
    train.scale(0.5, 0.5);
    train.setPosition(0, 150);
    charma.setPosition(150, 320);
    squir.setPosition(300, 320);
    bulba.setPosition(450, 320);
    
    bool gotoventana2 =  false;
    bool player1setname = false;
    bool player2setname = false;
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Space){
                    music.stop();
                    gotoventana2  = true;
                }
                if(event.key.code == sf::Keyboard::Escape){
                    window.close();
                }
            }
            if (gotoventana2){
                if(event.type == sf::Event::TextEntered){
                    if(event.text.unicode < 128 && player1.size()!= 10 &&  player1setname == false){
                        player1.push_back((char)event.text.unicode);
                        if(player2[player2.size()] == '\n'){
                            player1setname = true;
                        }
                        name1.setFont(font);
                        name1.setCharacterSize(15);
                        name1.setString(player1);
                        name1.setFillColor(sf::Color::Black);
                        name1.setPosition(175, 140);
                    }
                    if(player1.size() == 10){
                        player1setname = true;
                    }
                }
                if(player1setname){
                    if(event.type == sf::Event::TextEntered){
                        if(event.text.unicode < 128 && player2.size()!= 10 && !player2setname){
                            player2.push_back((char)event.text.unicode);
                            if(player2[player2.size()] == '\n'){
                                player2setname = true;
                            }
                            name2.setFont(font);
                            name2.setCharacterSize(15);
                            name2.setString(player2);
                            name2.setFillColor(sf::Color::Black);
                            name2.setPosition(175, 230);
                            
                        }
                        if(player2.size()==10)
                            player2setname = true;
                    }
                }
                
            }
            
        }
        
        window.clear();
        if(!gotoventana2){
            window.draw(sprite);
            window.draw(text);
            window.draw(start);
            window.draw(titulo1);
        }
        if(gotoventana2){
            window.draw(back2);
            window.draw(train);
            window.draw(charma);
            window.draw(bulba);
            window.draw(squir);
            window.draw(setplayer1);
            window.draw(setplayer2);
            window.draw(rectangle1);
            window.draw(rectangle2);
            window.draw(name1);
            window.draw(name2);
            
            
            
        }
        
        
        // Update the window
        window.display();
    }
    
    std::cout << player1 << std::endl;
    std::cout << player2 << std::endl;
    
    return EXIT_SUCCESS;
}

