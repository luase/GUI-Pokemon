#ifndef _MENU_HPP_
#define _MENU_HPP_

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "ResourcePath.hpp"

using namespace sf;

class Menu {
   public:
      Menu();
      Menu( float width, float height, int number_of_titles,  std::vector< std::string > titles, float width_position, float height_position);
      virtual ~Menu();

      virtual bool set( float width, float height, int number_of_titles,  std::vector< std::string > titles, float width_position, float height_position);
      void draw( sf::RenderWindow &window );
      void MoveUp();
      void MoveDown();
      void Restar_menu();
      int GetPressedItem();

   protected:
      int max_number_of_items;
      int selectedItemIndex;
      sf::Font font;
      std::vector < sf::Text > menu;
};

#endif
