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

std::unordered_map<std::string, std::shared_ptr<Menu>> scenes_;

public:

    Game();
    ~Game();

    std::shared_ptr<Menu> getScene(std::string const& string);

};

#endif //GAME_HPP