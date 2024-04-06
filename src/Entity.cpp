#include "Entity.hpp"

Entity::Entity(std::string name)
        	    : name_(name) { }

Entity::~Entity() { }

std::string const& Entity::getName() const { return name_; }

void Entity::setName(std::string name) { name_ = name; }

