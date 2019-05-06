//
// Created by c on 3/12/19.
//
#include <iostream>
#include "minesBoard.h"
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */

using namespace std;

void MinesweeperBoard::debug_display() const {

    for(int y=0; y<height; y++){
        for(int x=0; x<width; x++){
            cout << "[";
            if(board[x][y].hasMine){
                cout << "M";
            }
            else{
                cout << ".";
            }

            if(board[x][y].isRevealed){
                cout << "o";
            }
            else{
                cout << ".";
            }

            if(board[x][y].hasFlag){
                cout << "f";
            }
            else{
                cout << ".";
            }

            cout << countMines(x, y);

            cout << "]";
        }
        cout << endl;
    }
}

int MinesweeperBoard::drawField(bool dimension) const {

    int drawnField;

    if(dimension){
        //1 -- x

        drawnField = (rand() % width) + 0;
        //cout << drawnField << " ";
        return drawnField;

    } else{
        //0 -- y

        drawnField = (rand() % height) + 0;
        //cout << drawnField << endl;
        return drawnField;
    }

}

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode):width(width),height(height),mode(mode) {

    srand (time(nullptr));

    double minesCount;
    int area = width * height;

    switch (mode){
        case DEBUG: //debug

            for(int x=0; x<width; x++){
                for(int y=0; y<height; y++){
                    if(x==y){
                        board[x][y].hasMine = true;
                    }

                    if(y==0){
                        board[x][y].hasMine = true;
                    }

                    if(x==0 && y%2==0){
                        board[x][y].hasMine = true;
                    }
                }
            }

            break;

        case EASY: //easy

            minesCount = 0.1*area;

            //cout << minesCount << endl;

            do{
                board[drawField(1)][drawField(0)].hasMine = 1;
            }while (this->getMineCount() < minesCount);

            break;

        case NORMAL: //normal

            minesCount = 0.2*area;

            cout << minesCount << endl;

            do{
                board[drawField(1)][drawField(0)].hasMine = 1;
            }while (this->getMineCount() < minesCount);

            break;

        case HARD: //hard

            minesCount = 0.3*area;

            do{
                board[drawField(1)][drawField(0)].hasMine = 1;
            }while (this->getMineCount() < minesCount);

            break;
    }

    board[1][1].hasMine = true;
}

void MinesweeperBoard::setGameState(GameState gmSt) {
    gameState = gmSt;
}

GameState MinesweeperBoard::getGameState() const {
    return gameState;
}

int MinesweeperBoard::getBoardWidth() const{
    return width;
};

int MinesweeperBoard::getBoardHeight() const{
    return height;
};

bool MinesweeperBoard::isRevealed(int x, int y) const {
    if (board[x][y].isRevealed)
        return true;
    else
        return false;
}

int MinesweeperBoard::getMineCount() const{
    int counter = 0;

    for(int y=0; y<height; y++){
        for(int x=0; x<width; x++){
            if(board[x][y].hasMine){
                counter++;
            }
        }
    }

    return counter;
};

bool MinesweeperBoard::isOutside(int x, int y) const {

    if(x < 0 || x > width-1)
        return true;
    if(y < 0 || y > height-1)
        return true;

    return false;
}

int MinesweeperBoard::countMines(int x, int y) const {
    //if (!board[x][y].isRevealed)
    //    return -1;

    if (isOutside(x, y))
        return -1;

    int counter = 0;

    if (!isOutside(x - 1, y - 1))
        if (board[x - 1][y - 1].hasMine)
            counter++;

    if (!isOutside(x, y - 1))
        if (board[x][y - 1].hasMine)
            counter++;

    if (!isOutside(x + 1, y - 1))
        if (board[x + 1][y - 1].hasMine)
            counter++;

    if (!isOutside(x + 1, y))
        if (board[x + 1][y].hasMine)
            counter++;

    if (!isOutside(x + 1, y + 1))
        if (board[x + 1][y + 1].hasMine)
            counter++;

    if (!isOutside(x, y + 1))
        if (board[x][y + 1].hasMine)
            counter++;

    if (!isOutside(x - 1, y + 1))
        if (board[x - 1][y + 1].hasMine)
            counter++;

    if (!isOutside(x - 1, y))
        if (board[x - 1][y].hasMine)
            counter++;

    return counter;
}

bool MinesweeperBoard::hasFlag(int x, int y) const {
    if (! isOutside(x, y) && board[x][y].hasFlag && ! isRevealed(x, y))
        return true;
    else
        return false;

}

void MinesweeperBoard::toggleFlag(int x, int y) {
    if (! isOutside(x, y) && ! board[x][y].isRevealed && getGameState() == RUNNING)
        board[x][y].hasFlag = true;
}

bool MinesweeperBoard::isFirstPlayerAction() const {
    for(int y=0; y<height; y++){
        for(int x=0; x<width; x++){
            if ((isRevealed(x, y) || board[x][y].hasFlag) && getGameState() == RUNNING)
                return false;
        }
    }
    return true;
}

void MinesweeperBoard::revealField(int x, int y) {
    if (!isOutside(x, y) && !isRevealed(x, y) && getGameState() == RUNNING && !board[x][y].hasFlag) {
        if (board[x][y].hasMine) {
            if (isFirstPlayerAction() && !(mode == DEBUG)) {
                board[x][y].hasMine = false;

                int drawnX, drawnY;

                do {
                    drawnX = drawField(1);
                    drawnY = drawField(0);
                } while (drawnX == x && drawnY == y);

                board[drawnX][drawnY].hasMine = 1;
            } else
                gameState = FINISHED_LOSS;

        }
    }
    board[x][y].isRevealed = true;
}

char MinesweeperBoard::IntToChar(int in) const {
    switch ( in ) {
        case 0:
            return '0';
        case 1:
            return '1';
        case 2:
            return '2';
        case 3:
            return '3';
        case 4:
            return '4';
        case 5:
            return '5';
        case 6:
            return '6';
        case 7:
            return '7';
        case 8:
            return '9';
    }

}

char MinesweeperBoard::getFieldInfo(int x, int y) const {

    if (isOutside(x, y))
        return '#';

    if (! isRevealed(x, y) && hasFlag(x, y))
        return 'F';

    if (! isRevealed(x, y) && ! hasFlag(x, y))
        return '_';

    if (isRevealed(x, y) && board[x][y].hasMine)
        return 'x';

//    if (isRevealed(x, y) && countMines(x, y) == 0)
//        return  ' ';

    if (isRevealed(x, y))
        return IntToChar( countMines(x, y) );
}
