//
// Created by kajetan on 26.04.2019.
//

#include <iostream>
#include "MSBoardTextView.h"

using namespace std;

MSBoardTextView::MSBoardTextView(MinesweeperBoard &board):boardInView(boardInView){
    boardInView = board;
}

void MSBoardTextView::display() const {

    for(int y=0; y<boardInView.getBoardHeight(); y++){
        for(int x=0; x<boardInView.getBoardWidth(); x++){
            cout << "[";
            cout << boardInView.getFieldInfo(x, y);
            cout << "]";
        }
        cout << endl;
    }

}