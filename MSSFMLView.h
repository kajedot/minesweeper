//
// Created by kajetan on 05.05.2019.
//

#ifndef MINESWEEPER_MSSFMLVIEW_H
#define MINESWEEPER_MSSFMLVIEW_H

#include <SFML/Graphics.hpp>
#include "minesBoard.h"

class MSSFMLView {

    bool isOnBoard(int x, int y) const;

    int mouseToBoard(int cord, bool dim) const;

    void drawLines(sf::RenderWindow &window);

    void drawFieldsInfo(sf::RenderWindow &window);

    void drawGameOver(sf::RenderWindow &window);


public:
    MSSFMLView(MinesweeperBoard &board);

    void draw(sf::RenderWindow &window);

    MinesweeperBoard boardInSFML;

};


#endif //MINESWEEPER_MSSFMLVIEW_H
