#include <iostream>
#include "minesBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"

using namespace std;

int main(){
    MinesweeperBoard new_board(10, 10, EASY);

//    new_board.toggleFlag(2, 3);
//    cout << new_board.hasFlag(2, 3) << endl;
//    new_board.revealField(2, 6);
//
    //new_board.revealField(3, 3);


//    new_board.debug_display();
//
    MSBoardTextView view ( new_board );
//
//    view.display();

    MSTextController ctrl ( new_board, view );

    ctrl.play();

    //new_board.toggleFlag(2, 3);

    //ctrl.play();

    new_board.debug_display();

    return 0;
}
