#ifndef MENU_HPP
#define MENU_HPP

#include "Scene.hpp"

/**
 * @brief Class for menu, i.e. scenes with only Textbox as interactive objects in them.
 * 
 * @details All menus objects start with an return button by default
 */
class Menu : public Scene
{
private:
    /* data */
public:

    Menu(/* args */);
    ~Menu();

    void input(sf::Event& event, sf::RenderWindow& window);
    
};

#endif //MENU_HPP