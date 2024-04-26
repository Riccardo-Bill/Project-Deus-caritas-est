#include "Game.hpp"

Game::Game(){

    auto& tmp = this->scenes_["mainMenu"]; //creates the empty mainMenu scene

    //TODO: set menu to be something

}

Game::~Game() {}

std::shared_ptr<Menu> Game::getScene(std::string const& string) {

    //TODO: fix
    /*if (auto it = scenes_.find(string); it == scenes_.cend()){ //scene yet to be made
    
        auto& tmp = this->scenes_[string]; //TODO: set better creation for scenes

    }*/

    return this->scenes_[string];
}
