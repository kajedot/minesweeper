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
        cout << drawnField << " ";
        return drawnField;

    } else{
        //1 -- y

        drawnField = (rand() % height) + 0;
        cout << drawnField << endl;
        return drawnField;
    }

}

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode):width(width),height(height),mode(mode) {

    srand (time(nullptr));

    double minesCount;
    int area = width * height;

    switch (mode){
        case 0: //debug

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

        case 1: //easy

            minesCount = 0.1*area;

            cout << minesCount << endl;

            do{
                board[drawField(1)][drawField(0)].hasMine = 1;
            }while (this->getMineCount() < minesCount);

            break;

        case 2: //normal

            minesCount = 0.2*area;

            cout << minesCount << endl;

            do{
                board[drawField(1)][drawField(0)].hasMine = 1;
            }while (this->getMineCount() < minesCount);

            break;

        case 3: //hard

            minesCount = 0.3*area;

            do{
                board[drawField(1)][drawField(0)].hasMine = 1;
            }while (this->getMineCount() < minesCount);

            break;
    }


}

int MinesweeperBoard::getBoardWidth() const{
    return width;
};

int MinesweeperBoard::getBoardHeight() const{
    return height;
};

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

int MinesweeperBoard::isOutside(int x, int y) const {

    if(x < 0 || x > width-1)
        return 1;
    if(y < 0 || y > height-1)
        return 1;

    return 0;
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