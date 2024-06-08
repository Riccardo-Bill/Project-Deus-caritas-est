// (c) 2024 Riccardo Billiato
// This code is licensed under PolyForm Noncommercial License 1.0.0 (see LICENSE.md for details)

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "SFMLsupport/Fontbox.hpp"

Fontbox globFonts;

int main(){

    printf("Testing at the start!\n");

    //crate clock
    sf::Clock clock;

    //create window
    float windowWight = 800.f;
    float windowHeight = 600.f;
    sf::RenderWindow window(sf::VideoMode(windowWight, windowHeight), "Loading", sf::Style::Close);

    //center window
    window.setPosition(sf::Vector2i(0, 0));

    /*Test*/

    /*End of test*/
    
    //creates game object (should only be one)
    Game game = Game();

    sf::VideoMode::getDesktopMode();

    window.create(sf::VideoMode(windowWight, windowHeight), "Project Deus caritas est", sf::Style::Default);

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
                /* TODO: Resizing is very bugged
                if (window.getSize().x < windowWight || window.getSize().y < windowHeight)
                {
                    window.setSize(sf::Vector2u(windowWight, windowHeight));
                }
                if (window.getSize().x * (windowHeight / windowWight) <= window.getSize().y)
                {
                    window.setSize(sf::Vector2u(window.getSize().x, window.getSize().x * (windowHeight / windowWight)));
                }
                else if (window.getSize().y * (windowWight / windowHeight) <= window.getSize().x)
                {
                    window.setSize(sf::Vector2u(window.getSize().y * (windowWight / windowHeight), window.getSize().y));
                }
                */
            }

            // passing events to game
            if (event.type == sf::Event::TextEntered || event.type == sf::Event::MouseButtonPressed){
                game.input(event, window);
            }
        }

        //run update every cycle
        game.update(clock, window);

        window.clear(sf::Color(150, 150, 150));

        game.getScene("mainMenu").draw(window);

        window.display();
    }

    std::cout << "Testing at the end!" << std::endl;

    return EXIT_SUCCESS;
}