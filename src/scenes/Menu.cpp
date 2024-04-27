#include "Menu.hpp"

Menu::Menu()
    : Scene()
{
/*
    std::shared_ptr<Textbox> tmp = std::make_shared<Textbox>(Textbox(sf::Vector2f(75.f, 30.f), sf::Color(0, 0, 0),
                                                                    sf::Color(255, 255, 255), 2.f, sf::Vector2f(250.f, 500.f),
                                                                    "fonts/arial.ttf", sf::Color::White));

    tmp->setText("Return");
    tmp->getBox();

    this->boxes_.push_back(tmp);*/
}

Menu::~Menu()
{
    
}

/**
 * @brief Passes the input to all boxes of this scene
 * 
 * @param event sfml event from main loop 
 */
void Menu::input(sf::Event& event) {
    for (size_t i = 0; i < this->boxes_.size(); i++)
    {
        this->boxes_[i].input(event);
    }
}
