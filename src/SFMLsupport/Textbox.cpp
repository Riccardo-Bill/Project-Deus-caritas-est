#include "Textbox.hpp"
#include "Fontbox.hpp"
#include <iostream>
#include <stdexcept>
#include <fstream>

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
    this->function = 0;
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

void Textbox::setExtra(std::string const& extra) {
    this->extra = extra;
}

std::string const Textbox::getExtra() {
  return this->extra;
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

void Textbox::checkSelect(sf::Event& event, sf::RenderWindow& window)
{
    switch (writable)
    {
    case true: //it is a writable text box
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
    case false: //it is a button text box
        if (box_.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && pressable){ //second condition should always be true (TODO: should remove after making sure of assumption)
            this->button(event, window);
        }
        break;
    }
}

void Textbox::input(sf::Event& event, sf::RenderWindow& window) {
    switch (writable || pressable) //does nothing if it is not writable or pressable (the box is set as only output)
    {
    case true:
        switch (event.type)
        {
        case sf::Event::MouseButtonPressed: //mouse pressed, check for selecting of this box
            this->checkSelect(event, window);
            break;
        case sf::Event::TextEntered: //text is entered, check if this box is selected and writable then add text to it
            if (this->selected && writable) this->addText(sf::String(event.text.unicode));
            break;
        }
        break;
    }
}

void Textbox::setProprieties(bool write, bool press, int fun) {
    this->writable = write;
    this->pressable = press;
    this->function = fun;
}

void Textbox::setTextColor(sf::Color fillColor) {
    this->text_.setFillColor(fillColor);
}

void Textbox::setFunctionButton(int fun) { function = fun; }

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

void Textbox::button(sf::Event& event, sf::RenderWindow& window) {
    switch (function)
    {
    case 0: //Default functionalities
        /* TODO: Add default functionalities */
        break;
    case 1: //Terminate process
        window.close();
        break;
    case 2: //Open link
    {
        #if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined(_WIN64)

            const std::string url = "start " + this->getExtra();

        #elif __APPLE__

            const std::string url = "open " + this->getExtra();

        #elif __linux__

            const std::string url = "xdg-open " + this->getExtra();

        #else

        #   error "Unknown system"

        #endif

        system(url.c_str());

        break;
    }
    //case n: TODO: add other functionalities as needed
    default: //Should never happen
        std::cerr << "Out of bounds button function selected!" << std::endl;
        break;
    }
}
