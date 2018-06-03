#include "Menu.hpp"

Menu::Menu()
{
    max_number_of_items = 1;
    selectedItemIndex = 0;
}

Menu::Menu(float width, float height, int number_of_titles, std::vector<std::string> titles, float width_position, float height_position) : Menu()
{
    set(width, height, number_of_titles, titles, width_position, height_position);
}

Menu::~Menu()
{
    max_number_of_items = 0;
    selectedItemIndex = 0;
}

bool Menu::set(float width, float height, int number_of_titles, std::vector<std::string> titles, float width_position, float height_position)
{
    if (number_of_titles < 1)
        return false;
    font.loadFromFile( resourcePath() + "/Fonts/Pokemon GB.ttf");
    max_number_of_items = number_of_titles;

    sf::Text temp;

    temp.setFont(font);
    temp.setFillColor(sf::Color::Red);
    temp.setCharacterSize(10);
    temp.setString(titles[0]);
    temp.setPosition(sf::Vector2f(width / 2.5 + width_position, height / (number_of_titles + 1) * 1 + height_position));
    menu.push_back(temp);

    for (int i = 1; i < number_of_titles; i++)
    {
        temp.setFont(font);
        temp.setCharacterSize(10);
        temp.setFillColor(sf::Color::Black);
        temp.setString(titles[i]);
        temp.setPosition(sf::Vector2f(width / 2.5 + width_position, height / (number_of_titles + 1) * (i + 1) + height_position));
        menu.push_back(temp);
    }

    selectedItemIndex = 0;

    return true;
}

void Menu::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < max_number_of_items; i++)
    {
        window.draw(menu[i]);
    }
}

void Menu::MoveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::Black);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::MoveDown()
{
    if (selectedItemIndex + 1 < max_number_of_items)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::Black);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::Restar_menu()
{
    selectedItemIndex = 0;
    menu[selectedItemIndex].setFillColor(sf::Color::Red);
    menu[max_number_of_items - 1].setFillColor(sf::Color::Black);
}

int Menu::GetPressedItem() { return selectedItemIndex; }
