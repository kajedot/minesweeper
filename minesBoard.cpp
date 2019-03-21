//
// Created by c on 3/12/19.
//
#include <iostream>
#include "minesBoard.h"

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
            cout << "]";
        }
        cout << endl;
    }
}

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode):width(width),height(height) {}

