#include <iostream>
#include "minesBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include <SFML/Graphics.hpp>
#include "MSSFMLView.h"
#include "MSSFMLMenu.h"


int main(){

    sf::RenderWindow windowMenu (sf::VideoMode(800, 700), "MinesweeperMenu", sf::Style::Titlebar);

    MSSFMLMenu menu;

    menu.draw(windowMenu);

    MinesweeperBoard new_board (menu.boardSize*5, menu.boardSize*5, menu.gameMode);


    sf::RenderWindow window (sf::VideoMode(800, 700), "Minesweeper", sf::Style::Titlebar);

    MSSFMLView view (new_board);

    while (window.isOpen())
    {
        // obsługa zdarzeń
        //
        window.clear();
        view.draw(window);   // wywołujemy funkcję draw i dostarczamy jej okno na którym ma odbyć sie rysowanie
        window.display();
    }

    //new_board.debug_display();

    return 0;
}
