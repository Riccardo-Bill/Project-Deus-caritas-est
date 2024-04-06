#ifndef MENU_HPP
#define MENU_HPP

#include "Scene.hpp"

class Menu : public Scene
{
private:
    /* data */
public:

    Menu(/* args */);
    ~Menu();

    void input(sf::Event event);
    
};

#endif //MENU_HPP