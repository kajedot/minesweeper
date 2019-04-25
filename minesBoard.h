//
// Created by c on 3/12/19.
//
#ifndef INC_249297_MINESBOARD_H
#define INC_249297_MINESBOARD_H

enum GameMode { DEBUG, EASY, NORMAL, HARD}; //EASY 10%, NORMAL 20%, HARD 30%
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS};

struct Field{
    bool hasMine = false;
    bool isRevealed = false;
    bool hasFlag = false;
};

class MinesweeperBoard{
    GameState gameState;
    Field board[100][100];
    int width;
    int height;
    GameMode mode;

public:
    void debug_display() const;
    MinesweeperBoard(int width, int height, GameMode mode);

    GameState getGameState() const;
    int getBoardWidth() const;
    int getBoardHeight() const;
    bool isRevealed(int x, int y) const;
    int getMineCount() const;
    bool isOutside(int x, int y) const;
    int countMines(int x, int y) const;
    int drawField(bool dimension) const;
    bool hasFlag(int x, int y) const;
    void toggleFlag(int x, int y);
    bool isFirstPlayerAction() const;
    void revealField(int x, int y);
    char getFieldInfo(int x, int y) const;




};

#endif //INC_249297_MINESBOARD_H

