#include <iostream>
#include "minesBoard.h"

using namespace std;

int main(){
    MinesweeperBoard new_board(10, 10, NORMAL);
    new_board.debug_display();

    cout << new_board.getMineCount();

    return 0;
}
