/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameBoard.h
 * Author: Tobias Fischer
 *
 * Created on October 3, 2018, 10:28 AM
 */

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

using namespace std;

class GameBoard {
public:
    GameBoard(int size);
    bool getHitAndMark(int x, int y);
    string getBoardToString();
    enum Difficulty { easy = 4, medium, hard };
private:
    int miSize;
    bool mbaShips[][];
    bool mbaAttacked[][];
};

#endif /* GAMEBOARD_H */

