//
// Created by kajetan on 26.04.2019.
//

#ifndef MINESWEEPER_MSBOARDTEXTVIEW_H
#define MINESWEEPER_MSBOARDTEXTVIEW_H


#include "minesBoard.h"

class MSBoardTextView{

public:
    MSBoardTextView(MinesweeperBoard &board);

    MinesweeperBoard boardInView;

    void display() const;

};


#endif //MINESWEEPER_MSBOARDTEXTVIEW_H

