#include "Game.hpp"

Game::Game(){

    auto& tmp = this->scenes_["mainMenu"]; //creates the empty mainMenu scene

    currentScene_ = "mainMenu"; //sets current at mainMenu

    loadSceneFromFile("data/mainMenu.txt", "mainMenu"); //load pre-made main menu from file

}

Game::~Game() {}

void Game::setCurrentScene(std::string const& string) {
    currentScene_ = string;
    //TODO set stuff for new scene (load from file?)
}

Menu Game::getScene(std::string const& string) {

    //TODO: fix
    /*if (auto it = scenes_.find(string); it == scenes_.cend()){ //scene yet to be made
    
        auto& tmp = this->scenes_[string]; //TODO: set better creation for scenes

    }*/

    return this->scenes_[string];
}

void Game::loadSceneFromFile(std::string const& file, std::string const& scene) {

    float size1, size2;

    unsigned int fillColor, outColor;

    float outThick;

    float pos1, pos2;

    std::string font;

    unsigned int textColor;

    std::string text;

    bool writable;

    bool pressable;

    int function;

    std::string extra;

    std::ifstream fin(file);

    while (fin >> size1 >> size2 >> fillColor >> outColor >> outThick >> pos1 >> pos2 >> font >> textColor >> text >> writable >> pressable >> function >> extra)
    {
        
        auto box = Textbox(sf::Vector2f(size1, size2), sf::Color(fillColor),
                            sf::Color(outColor), outThick, sf::Vector2f(pos1, pos2),
                            font, sf::Color(textColor));
        std::replace(text.begin(), text.end(), '_', ' ');
        box.setText(text);
        box.setProprieties(writable, pressable, function);
        box.setExtra(extra);
        this->scenes_[scene].addBox(box);
    }
    
    fin.close();

}

void Game::input(sf::Event& event, sf::RenderWindow& window) {
  this->scenes_[currentScene_].input(event, window);
}
