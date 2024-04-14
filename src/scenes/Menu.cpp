#include "Menu.hpp"

Menu::Menu(/* args */)
    : Scene()
{

    std::shared_ptr<Textbox> tmp = std::make_shared<Textbox>(Textbox());

    this->boxes_.push_back(tmp);
}

Menu::~Menu()
{
    
}

/**
 * @brief Passes the input to all boxes of this scene
 * 
 * @param event sfml event from main loop 
 */
void Menu::input(sf::Event event) {
    for (size_t i = 0; i < this->boxes_.size(); i++)
    {
        this->boxes_[i]->input(event);
    }
}
