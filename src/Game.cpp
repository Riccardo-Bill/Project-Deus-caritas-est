#include "Game.hpp"

Game::Game(){

    auto& tmp = this->scenes_["mainMenu"]; //creates the empty mainMenu scene

    //TODO: set menu to be something
    auto box = std::make_shared<Textbox>(Textbox(sf::Vector2f(75.f, 30.f), sf::Color(0, 0, 0),
                                            sf::Color(255, 255, 255), 2.f, sf::Vector2f(250.f, 500.f),
                                            "fonts/arial.ttf", sf::Color::White));

    tmp->addBox(box);

}

Game::~Game() {}

std::shared_ptr<Menu> Game::getScene(std::string const& string) {

    //TODO: fix
    /*if (auto it = scenes_.find(string); it == scenes_.cend()){ //scene yet to be made
    
        auto& tmp = this->scenes_[string]; //TODO: set better creation for scenes

    }*/

    return this->scenes_[string];
}
