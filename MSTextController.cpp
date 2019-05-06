//
// Created by kajetan on 04.05.2019.
//

#include "MSTextController.h"
#include "iostream"

using namespace std;

MSTextController::MSTextController(MinesweeperBoard &board, MSBoardTextView &view):boardInContr(boardInContr), viewInContr(viewInContr) {
    boardInContr = board;
    viewInContr = view;
}

void MSTextController::display(){

    for(int y=0; y<boardInContr.getBoardHeight(); y++){
        for(int x=0; x<boardInContr.getBoardWidth(); x++){
            cout << "[";
            cout << boardInContr.getFieldInfo(x, y);
            cout << "]";
        }
        cout << endl;
    }
}

void MSTextController::pickAction(char chr, int x, int y) {
    switch( chr ){
        case 'r' :
        case 'R' :

            boardInContr.revealField(x, y);
//            cout << "revealed " << x << y;
//            cout << boardInContr.isRevealed(x, y) << endl;
//            cout << boardInContr.isRevealed(2, 2) << endl;
            break;

        case 't':
        case 'T' :
            boardInContr.toggleFlag(x, y);
            break;
    }
}



void MSTextController::play(){
    boardInContr.setGameState(RUNNING);

    string cinBuff;
    int x, y;
    char actChr;

    display();

    while (boardInContr.getGameState() == RUNNING){


        cout << "Pick position: \n x: ";
        cin >> x;
        cout << "\n y: ";
        cin >> y;

        cout << "Pick action: [R]eveal field or [T]oggleFlag: ";
        cin >> actChr;

        if (actChr == 'x')
        break;

        pickAction(actChr, x, y);

        display();
    }


}