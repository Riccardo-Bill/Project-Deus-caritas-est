#ifndef CHAR_HPP
#define CHAR_HPP

#include "Entity.hpp"

/**
 * @brief Base abstract virtual class for all acting entities 
 * 
 */
class Char : public Entity
{
private:

public:

    Char(std::string name);

    virtual ~Char();

};

#endif //CHAR_HPP