#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP

#include <SFML/Graphics.hpp>

/// @brief Class to handle text in SFML
class Textbox
{
private:
    
    sf::RectangleShape box_;

    sf::Text text_;

    sf::Font font_;

    bool selected;

public:

    Textbox(sf::Vector2f size = sf::Vector2f(450.f, 50.f), 
            sf::Color fillColor = sf::Color(0, 0, 0),
            sf::Color outColor = sf::Color(255, 255, 255),
            float outThick = 2.f,
            sf::Vector2f pos = sf::Vector2f(100.f, 100.f),
            std::string font = "arial.ttf",
            sf::Color textColor = sf::Color(255, 255, 255));

    ~Textbox();

    //simple getter and setters for box
    sf::RectangleShape const& getBox();
    void setBox(sf::Vector2f size);

    //simple getter and setters for text
    std::string const getText();
    void setText(std::string const& text);
    void setFont(std::string const& text);
    void setTextColor(sf::Color fillColor, sf::Color outlineColor);
    void setTextColor(sf::Color fillColor);

    void addText(std::string const& text);

    void checkSelect(sf::Event event);


    void draw(sf::RenderWindow& window);

    void input(sf::Event event);

    /// @brief Update all values of box_
    void update(sf::Clock& clock);
};

#endif //TEXTBOX_HPP