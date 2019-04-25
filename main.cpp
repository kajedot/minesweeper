#include <iostream>
#include "minesBoard.h"

using namespace std;

int main(){
    MinesweeperBoard new_board(10, 10, DEBUG);


    new_board.revealField(2, 3);

    new_board.debug_display();
    cout << new_board.getMineCount() << endl;
    return 0;
}
