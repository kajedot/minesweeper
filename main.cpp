#include <iostream>
#include "minesBoard.h"

using namespace std;

int main(){
    MinesweeperBoard new_board(10, 10, EASY);

    new_board.toggleFlag(2, 3);
    cout << new_board.hasFlag(2, 3) << endl;
    new_board.revealField(2, 6);
    new_board.revealField(1, 1);


    new_board.debug_display();

    cout << new_board.getGameState();

    return 0;
}