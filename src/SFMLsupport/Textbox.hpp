// (c) 2024 Riccardo Billiato
// This code is licensed under PolyForm Noncommercial License 1.0.0 (see LICENSE.md for details)

#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP

#include <SFML/Graphics.hpp>
#include <map>

/// @brief Class to handle text in SFML
class Textbox
{
private:
    
    sf::RectangleShape box_;

    sf::Text text_;

    sf::Font font_;

    bool writable;

    bool pressable;

    bool selected;
    
    int function;

    std::string extra;

public:

    Textbox(sf::Vector2f size = sf::Vector2f(450.f, 50.f), 
            sf::Color fillColor = sf::Color(0, 0, 0),
            sf::Color outColor = sf::Color(255, 255, 255),
            float outThick = 2.f,
            sf::Vector2f pos = sf::Vector2f(100.f, 100.f),
            std::string font = "fonts/arial.ttf",
            sf::Color textColor = sf::Color::White);

    ~Textbox();

    //simple getter and setters for box
    sf::RectangleShape const& getBox();
    void setBox(sf::Vector2f size);

    //simple getter and setters for text
    std::string const getText();
    void setText(std::string const& text);
    void setFont(std::string const& font);
    void setTextColor(sf::Color fillColor, sf::Color outlineColor);
    void setTextColor(sf::Color fillColor);
    void setFunctionButton(int fun);
    void setExtra(std::string const& extra);
    std::string const getExtra();

    void addText(std::string const& text);

    void checkSelect(sf::Event& event, sf::RenderWindow& window);

    /**
     * @brief Set the Proprieties object
     * 
     * @param write Is the box writable?
     * @param press Is the box pressable?
     * @param fun What does pressing the button does?
     */
    void setProprieties(bool write, bool press, int fun);

    void draw(sf::RenderWindow& window);

    void input(sf::Event& event, sf::RenderWindow& window);

    void button(sf::Event& event, sf::RenderWindow& window);

    /// @brief Update all values of box_
    void update(sf::Clock& clock, sf::RenderWindow& window);
};

#endif //TEXTBOX_HPP