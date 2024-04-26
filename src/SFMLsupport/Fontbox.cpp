#include "Fontbox.hpp"
#include <iostream>
#include <stdexcept>

Fontbox::Fontbox()
{
    auto& tmp = fonts_["GRAVE ERROR JUST HAPPENED"]; //this creates an empty SFML font to pass in case of errors
}

Fontbox::~Fontbox()
{
    //fonts_.clear();
}

void Fontbox::loadFont(std::string const& font)
{
    try
    {
        if (auto it = fonts_.find(font); it == fonts_.cend()) { // Font was not created before.
            auto& tmp = fonts_[font]; // this access will create a Font object and automatically store it in the map
            if(!tmp.loadFromFile(font)){
                throw(std::runtime_error("Failed to load font"));
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

const sf::Font& Fontbox::getFont(std::string const& font)
{
    try
    {
        if (auto it = fonts_.find(font); it == fonts_.cend()) { // Font was not created before.
            auto& tmp = fonts_[font]; // this access will create a Font object and automatically store it in the map
            if(!tmp.loadFromFile(font)){
                throw(std::runtime_error("Failed to load font"));
            }
        }
        return fonts_[font];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return fonts_["GRAVE ERROR JUST HAPPENED"];
    }
}
