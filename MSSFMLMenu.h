//
// Created by kajetan on 07.05.2019.
//

#ifndef MINESWEEPER_MSSFMLMENU_H
#define MINESWEEPER_MSSFMLMENU_H

#include <SFML/Graphics.hpp>
#include "minesBoard.h"


class MSSFMLMenu {
public:
    MSSFMLMenu();
    GameMode gameMode=DEBUG;
    int boardSize=1;
    void draw(sf::RenderWindow &window);
};


#endif //MINESWEEPER_MSSFMLMENU_H
