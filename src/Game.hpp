#ifndef GAME_HPP
#define GAME_HPP

#include <unordered_map>
#include <memory>
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

public:

    Game();
    ~Game();

    Menu getScene(std::string const& string);

};

#endif //GAME_HPP