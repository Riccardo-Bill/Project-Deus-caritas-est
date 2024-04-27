#include "Textbox.hpp"
#include "Fontbox.hpp"
#include <iostream>
#include <stdexcept>

Textbox::Textbox(sf::Vector2f size, sf::Color fillColor, sf::Color outColor,
                float outThick, sf::Vector2f pos, std::string font, sf::Color textColor)
                : box_(sf::RectangleShape(size))
{
    box_.setSize(size);
    box_.setFillColor(fillColor);
    box_.setOutlineThickness(outThick);                     
    box_.setOutlineColor(outColor);
    box_.move(pos);

    this->setFont(font);
    this->setTextColor(textColor, fillColor);
    this->text_.setString("Fix your god damm code!");   //default text
    this->text_.setCharacterSize(25);
    this->text_.setPosition(box_.getPosition());

    this->selected = false;
    this->writable = false;
    this->pressable = false;
}

Textbox::~Textbox() { }

sf::RectangleShape const& Textbox::getBox() { return box_; }

void Textbox::setBox(sf::Vector2f size) { this->box_.setSize(size); }

std::string const Textbox::getText() { return this->text_.getString(); }

void Textbox::setText(std::string const& text) { this->text_.setString(text); }

void Textbox::setFont(std::string const& font) {
    text_.setFont(globFonts.getFont(font));
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

void Textbox::checkSelect(sf::Event& event)
{
    switch (writable)
    {
    case true:
        if (box_.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && this->selected == false)
        {
            this->selected = true;
            this->addText("_");
        }
        else if (!(box_.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) && this->selected == true)
        {
            this->selected = false;
            std::string now = this->text_.getString();
            now.pop_back();
            this->text_.setString(now);
        }
        break;
    case false:
        if (box_.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && pressable){ //second condition should always be true (TODO: should remove after making sure of assumption)
            std::cout << "Return pressed!" << std::endl;
        }
        break;
    }
}

void Textbox::input(sf::Event& event) {
    switch (writable || pressable) //does nothing if it is not writable or pressable (the box is set as only output)
    {
    case true:
        switch (event.type)
        {
        case sf::Event::MouseButtonPressed: //mouse pressed, check for selecting of this box
            this->checkSelect(event);
            break;
        case sf::Event::TextEntered: //text is entered, check if this box is selected and writable then add text to it
            if (this->selected && writable) this->addText(sf::String(event.text.unicode));
            break;
        default:
            break;
        }
        break;
    }
}

void Textbox::setProprieties(bool write, bool press) {
    this->writable = write;
    this->pressable = press;
}

void Textbox::setTextColor(sf::Color fillColor) {
    this->text_.setFillColor(fillColor);
}

void Textbox::draw(sf::RenderWindow& window) {
    window.draw(this->box_);
    this->text_.setPosition(box_.getPosition());
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

    //TODO: Implement resizing?

}