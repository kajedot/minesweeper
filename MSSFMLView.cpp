//
// Created by kajetan on 05.05.2019.
//

#include <SFML/Graphics.hpp>
#include "MSSFMLView.h"
#include <iostream>

MSSFMLView::MSSFMLView(MinesweeperBoard &board):boardInSFML(boardInSFML) {

    boardInSFML = board;

}

bool MSSFMLView::isOnBoard(int x, int y) const {
    if(x>30 && x<30*(boardInSFML.getBoardWidth()+1) && y>30 && y<30*(boardInSFML.getBoardHeight()+1)) //1 for yes, 0 for no
        return 1;
    return 0;
}

int MSSFMLView::mouseToBoard(int cord, bool dim) const{
    if (dim) //0 for x, 1 for y
        return cord/30-1; //minus unvisible fields
    else
        return cord/30-1;
}

void MSSFMLView::drawLines(sf::RenderWindow &window){
    for(int i =0; i<boardInSFML.getBoardWidth()+1; i++){
        sf::Vertex verticalLine[] =
                {
                        sf::Vertex(sf::Vector2f(30+i*30, 30)),
                        sf::Vertex(sf::Vector2f(30+i*30, 30*(boardInSFML.getBoardWidth()+1)))
                };

        window.draw(verticalLine, 2, sf::Lines);
    }

    for(int i =0; i<boardInSFML.getBoardHeight()+1; i++){
        sf::Vertex horizontalLine[] =
                {
                        sf::Vertex(sf::Vector2f(30, 30+i*30)),
                        sf::Vertex(sf::Vector2f(30*(boardInSFML.getBoardHeight()+1), 30+i*30))
                };

        window.draw(horizontalLine, 2, sf::Lines);
    }
}

void MSSFMLView::drawFieldsInfo(sf::RenderWindow &window) {

    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/TTF/DejaVuSans.ttf"))
    {
        std::cout << "Error while loading font" << std::endl;
    }

    for(int y=0; y<boardInSFML.getBoardHeight(); y++){
        for(int x=0; x<boardInSFML.getBoardWidth(); x++){
            if(boardInSFML.hasFlag(x,y)){
                sf::Text text;
                text.setFont(font);
                text.setCharacterSize(24);
                text.setString("F");
                text.setPosition(x*30+30, y*30+30);
                window.draw(text);
            }

            if(boardInSFML.isRevealed(x,y)){
                sf::Text text;
                text.setFont(font);
                text.setCharacterSize(24);
                text.setString(boardInSFML.getFieldInfo(x, y));
                text.setPosition(x*30+30, y*30+30);
                window.draw(text);
            }
        }
    }
}

void MSSFMLView::drawGameOver(sf::RenderWindow &window) {
    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/TTF/DejaVuSans.ttf"))
    {
        std::cout << "Error while loading font" << std::endl;
    }

    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Magenta);

        sf::Text textWelcome;
        textWelcome.setFont(font);
        textWelcome.setFillColor(sf::Color::Yellow);
        textWelcome.setCharacterSize(35);
        textWelcome.setString("You Looooose!1 =(((");
        textWelcome.setPosition(300, 100);
        window.draw(textWelcome);

        window.display();
    }
}


void MSSFMLView::draw(sf::RenderWindow &window){

    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (event.type == sf::Event::MouseButtonPressed) {

            if (event.mouseButton.button == sf::Mouse::Right) {
//                std::cout << "the right button was pressed" << std::endl;
//
//                std::cout << "mouse x: " << event.mouseButton.x;
//                std::cout << " field x: " << mouseToBoard(event.mouseButton.x, 0) << std::endl;
//
//
//                std::cout << "mouse y: " << event.mouseButton.y;
//                std::cout << " field y: " << mouseToBoard(event.mouseButton.y, 0) << std::endl;

                if (isOnBoard(event.mouseButton.x, event.mouseButton.y)) {
                    boardInSFML.toggleFlag(mouseToBoard(event.mouseButton.x, 0), mouseToBoard(event.mouseButton.y, 1));
                }

            }

            if (event.mouseButton.button == sf::Mouse::Left) {
//                std::cout << "the left button was pressed" << std::endl;
//
//                std::cout << "mouse x: " << event.mouseButton.x;
//                std::cout << " field x: " << mouseToBoard(event.mouseButton.x, 0) << std::endl;
//
//
//                std::cout << "mouse y: " << event.mouseButton.y;
//                std::cout << " field y: " << mouseToBoard(event.mouseButton.y, 0) << std::endl;

                if (isOnBoard(event.mouseButton.x, event.mouseButton.y)) {
                    boardInSFML.revealField(mouseToBoard(event.mouseButton.x, 0), mouseToBoard(event.mouseButton.y, 1));
                }

            }
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        drawLines(window);
        drawFieldsInfo(window);



        // end the current frame
        window.display();

        while (boardInSFML.getGameState() == FINISHED_LOSS){
            drawGameOver(window);
        }
    }
}
