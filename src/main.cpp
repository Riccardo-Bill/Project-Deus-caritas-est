#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "SFMLsupport/Fontbox.hpp"

Fontbox globFonts;

int main(){

    printf("Testing at the start!\n");

    //create window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Loading", sf::Style::Close);

    //center window
    window.setPosition(sf::Vector2i(0, 0));

    /*Test*/

    Game game = Game();

    /*End of test*/

    sf::VideoMode::getDesktopMode();

    window.create(sf::VideoMode(800, 600), "Project Deus caritas est", sf::Style::Default);

    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

            // resize the window if user resizes it own window
            if (event.type == sf::Event::Resized) {
                window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
            }

            // passing events to mainMenu
            /*if (event.type == sf::Event::TextEntered || event.type == sf::Event::MouseButtonPressed){
                mainMenu.input(event);
            }*/
/*
            if (event.type == sf::Event::TextEntered){
                for (size_t i = 0; i < boxes.size(); i++)
                {
                    boxes[i]->input(event);
                }
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {

                    for (size_t i = 0; i < boxes.size(); i++)
                    {
                        boxes[i]->checkSelect(event);
                    }
                }
            
            }            
*/
        }

        window.clear(sf::Color(150, 150, 150));

        game.getScene("mainMenu")->draw(window);

        window.display();
    }

    std::cout << "Testing at the end!" << std::endl;

    return EXIT_SUCCESS;
}