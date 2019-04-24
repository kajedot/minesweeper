#include <iostream>
#include "minesBoard.h"

using namespace std;

int main(){
    MinesweeperBoard new_board(10, 10, HARD);
    new_board.debug_display();
    cout << new_board.getMineCount() << endl;

    cout << new_board.isOutside(2,2);

    return 0;
}
