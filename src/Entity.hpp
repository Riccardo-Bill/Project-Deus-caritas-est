#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <vector>
#include <string>

/**
 * @brief Base abstract virtual class for all entities 
 * 
 */
class Entity
{
protected:
    
    std::string name_;

public:

    Entity(std::string name);

    virtual ~Entity();

    //simple getter and setters
    std::string const & getName() const;
    void setName(std::string name);

};

#endif //ENTITY_HPP