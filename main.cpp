#include <iostream>
#include "minesBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include <SFML/Graphics.hpp>
#include "MSSFMLView.h"

int main(){

    MinesweeperBoard new_board(10, 10, DEBUG);

    new_board.toggleFlag(1, 1);

    // create the window
    sf::RenderWindow window (sf::VideoMode(800, 600), "Minesweeper");

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
