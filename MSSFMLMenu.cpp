//
// Created by kajetan on 07.05.2019.
//

#include <iostream>
#include "MSSFMLMenu.h"

MSSFMLMenu::MSSFMLMenu() {}

void MSSFMLMenu::draw(sf::RenderWindow &window){

    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/TTF/DejaVuSans.ttf"))
    {
        std::cout << "Error while loading font" << std::endl;
    }

    while (window.isOpen())

    {
        //std::cout << "hello";
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (event.type == sf::Event::MouseButtonPressed) {

            if (event.mouseButton.button == sf::Mouse::Left) {
                std::cout << "the left button was pressed" << std::endl;

                std::cout << "mouse x: " << event.mouseButton.x << " y: " << event.mouseButton.y << std::endl;

                if(event.mouseButton.x > 260 && event.mouseButton.x < 360 && event.mouseButton.y > 304 && event.mouseButton.y < 324){
                    gameMode = EASY;
                }

                if(event.mouseButton.x > 360 && event.mouseButton.x < 460 && event.mouseButton.y > 304 && event.mouseButton.y < 324){
                    gameMode = NORMAL;
                }

                if(event.mouseButton.x > 460 && event.mouseButton.x < 560 && event.mouseButton.y > 304 && event.mouseButton.y < 324){
                    gameMode = HARD;
                }

                if(event.mouseButton.x > 260 && event.mouseButton.x < 360 && event.mouseButton.y > 400 && event.mouseButton.y < 420){
                    boardSize = 1;
                }

                if(event.mouseButton.x > 360 && event.mouseButton.x < 460 && event.mouseButton.y > 400 && event.mouseButton.y < 420){
                    boardSize = 2;
                    std::cout << "10x10" << std::endl;
                }

                if(event.mouseButton.x > 460 && event.mouseButton.x < 560 && event.mouseButton.y > 400 && event.mouseButton.y < 420){
                    boardSize = 4;
                    std::cout << "20x20" << std::endl;
                }

                if(event.mouseButton.x > 345 && event.mouseButton.x < 480 && event.mouseButton.y > 500 && event.mouseButton.y < 540){
                    window.close();
                }

                //window.close();
            }
        }


        window.clear(sf::Color::Green);

        sf::Text textWelcome;
        textWelcome.setFont(font);
        textWelcome.setFillColor(sf::Color::Yellow);
        textWelcome.setCharacterSize(35);
        textWelcome.setString("Welcome to Minesweeper!1");
        textWelcome.setPosition(300, 100);
        window.draw(textWelcome);

        sf::Text textHardness;
        textHardness.setFont(font);
        textHardness.setCharacterSize(24);
        textHardness.setString("Please, pick your hardness level:");
        textHardness.setPosition(300, 250);
        window.draw(textHardness);

        sf::Text textHardnessLevels;
        textHardnessLevels.setFont(font);
        textHardnessLevels.setFillColor(sf::Color::Blue);
        textHardnessLevels.setCharacterSize(20);
        textHardnessLevels.setString("IZZZI   NORML   HAARD");
        textHardnessLevels.setPosition(300, 300);
        window.draw(textHardnessLevels);

        sf::Text textSize;
        textHardness.setFont(font);
        textHardness.setCharacterSize(24);
        textHardness.setString("And Your board size:");
        textHardness.setPosition(300, 350);
        window.draw(textHardness);

        sf::Text textSizeLevels;
        textSizeLevels.setFont(font);
        textSizeLevels.setFillColor(sf::Color::Blue);
        textSizeLevels.setCharacterSize(20);
        textSizeLevels.setString("05x05   10x10   20x20");
        textSizeLevels.setPosition(300, 400);
        window.draw(textSizeLevels);

        sf::Text textStart;
        textStart.setFont(font);
        textStart.setCharacterSize(40);
        textStart.setString("START");
        textStart.setPosition(350, 500);
        window.draw(textStart);

        window.display();
    }
};
