//
// Created by kajetan on 04.05.2019.
//

#ifndef MINESWEEPER_MSTEXTCONTROLLER_H
#define MINESWEEPER_MSTEXTCONTROLLER_H

#include "minesBoard.h"
#include "MSBoardTextView.h"

class MSTextController {

    void pickAction(char chr, int x, int y);


public:
    MSTextController(MinesweeperBoard &board, MSBoardTextView &view);

    MinesweeperBoard boardInContr;
    MSBoardTextView viewInContr;

    void play();


};


#endif //MINESWEEPER_MSTEXTCONTROLLER_H
