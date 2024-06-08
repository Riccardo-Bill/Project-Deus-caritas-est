// (c) 2024 Riccardo Billiato
// This code is licensed under PolyForm Noncommercial License 1.0.0 (see LICENSE.md for details)

#ifndef FONTBOX_HPP
#define FONTBOX_HPP

#include <SFML/Graphics.hpp>
#include <unordered_map>

/**
 * @brief Class to handle all SFML fonts
 * 
 */
class Fontbox
{
private:
    
    std::unordered_map<std::string, sf::Font> fonts_;

public:

    Fontbox();
    ~Fontbox();

    /**
     * @brief Creates font at string directory, only if it is not loaded already, contains
     *        error handling in case of failed load.
     * 
     * @param font Location of font to be loaded
     */
    void loadFont(std::string const& font); //TODO: Remove if not used

    /**
     * @brief Returns SFML font at string directory, it creates it if needed, contains
     *        error handling in case of failed load.
     * 
     * @param font Location of font to be loaded
     * @return const sf::Font& of font
     */
    const sf::Font& getFont(std::string const& font);
};

extern Fontbox globFonts;

#endif //FONTBOX_HPP