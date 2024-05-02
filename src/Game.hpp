#ifndef GAME_HPP
#define GAME_HPP

#include <unordered_map>
#include <memory>
#include <iostream>
#include <fstream>
#include "scenes/Menu.hpp"
#include "SFMLsupport/Textbox.hpp"

/**
 * @brief 
 * 
 */
class Game
{
private:

std::unordered_map<std::string, Menu> scenes_;

std::string currentScene_;

public:

    Game();
    ~Game();

    void setCurrentScene(std::string const& string);

    Menu getScene(std::string const& string);

    /**
     * @brief Load a scene from file
     * 
     * @param file File path
     * @param scene Scene name for hashing (allows for overwrite of previous scene)
     */
    void loadSceneFromFile(std::string const& file, std::string const& scene);

    /**
     * @brief Pass event to scenes_[currentScene_] input function
     * 
     * @param event 
     */
    void input(sf::Event& event, sf::RenderWindow& window);

};

#endif //GAME_HPP