#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Char.hpp"

class Player : public Char
{
private:

public:

    Player(std::string name = "Player");
    ~Player();

};

#endif //PLAYER_HPP