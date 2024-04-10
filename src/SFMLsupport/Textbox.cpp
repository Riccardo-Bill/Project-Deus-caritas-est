#include "Textbox.hpp"
#include <iostream>
#include <stdexcept>

Textbox::Textbox(sf::Vector2f size, sf::Color fillColor, sf::Color outColor,
                float outThick, sf::Vector2f pos, std::string font, sf::Color textColor)
                : box_(sf::RectangleShape(size))
{
    box_.setFillColor(fillColor);
    box_.setOutlineThickness(outThick);                     
    box_.setOutlineColor(outColor);
    box_.move(pos);

    this->setFont(font);
    this->setTextColor(textColor, fillColor);
    this->text_.setString("Fix your god damm code!");   //default text
    this->text_.setPosition(box_.getPosition());

    this->selected = false;
}

Textbox::~Textbox() { }

sf::RectangleShape const& Textbox::getBox() { return box_; }

void Textbox::setBox(sf::Vector2f size) { this->box_.setSize(size); }

std::string const Textbox::getText() { return this->text_.getString(); }

void Textbox::setText(std::string const& text) { this->text_.setString(text); }

void Textbox::setFont(std::string const& font) {
    try
    {
        if (auto it = font_.find(font); it == font_.cend()) { // Font was not created before.
            auto& tmp = font_[font]; // this access will create a Font object and automatically store it in the map
            if(!tmp.loadFromFile(font)){
                throw(std::runtime_error("Failed to load font"));
            }
        }
        text_.setFont(font_[font]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void Textbox::setTextColor(sf::Color fillColor, sf::Color outlineColor) {
    this->text_.setFillColor(fillColor);
    this->text_.setOutlineColor(outlineColor);
}

void Textbox::addText(std::string const& text) { 
    std::string now = this->text_.getString();
    if (now.back() == '_')
    {
        now.pop_back();
        this->text_.setString(now + text + "_");
    }
    else
    {
        this->text_.setString(now + text);
    }
}

void Textbox::checkSelect(sf::Event event)
{
    if (box_.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
    {
        this->selected = true;
        this->addText("_");
    }
    else
    {
        this->selected = false;
        std::string now = this->text_.getString();
        now.pop_back();
        this->text_.setString(now);
    }
}

void Textbox::input(sf::Event event) {
    if (event.type == sf::Event::MouseLeft){ //if mouse press check for selecting of this box
        this->checkSelect(event);
    }
    else if (this->selected && event.type == sf::Event::TextEntered){ //if this box is selected AND text is entered add it to this box
        this->addText(sf::String(event.text.unicode));
    }
}

void Textbox::setTextColor(sf::Color fillColor) {
    this->text_.setFillColor(fillColor);
}

void Textbox::draw(sf::RenderWindow& window) {
    window.draw(this->box_);
    window.draw(this->text_);
}

void Textbox::update(sf::Clock& clock) {
    
    //TODO: Make text underscore blink
    /*if(this->selected){
        std::string now = this->text_.getString();
        if (now.back() == '_' && clock.getElapsedTime().asSeconds() == 0.5f)
        {
            now.pop_back();
        }
        else if (clock.getElapsedTime().asSeconds() == 1.0f)
        {
            clock.restart();
            this->text_.setString(now + "_");
        }
    } */

}