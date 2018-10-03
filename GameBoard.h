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

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <random>

#define SHIPS_CHAR      "X"
#define EMPTY_CHAR      "O"
#define UNKNOWN_CHAR    "*"
#define MAX_BOARD_SIZE  7
#define SHIP_AMNT       3

using namespace std;

const int ShipSizes[SHIP_AMNT] = { 4, 3, 2 };

class Point {
public:
    Point(int iX, int iY, int iDir) { x = iX; y = iY; dir = iDir; };
    int x;
    int y;
    int dir;
    enum Directions { right, down };
};

class GameBoard {
public:
    GameBoard(int iSize);
    bool getHitAndMark(int iX, int iY);
    string getBoardToString();
    int getSize() { return miSize; };
    enum Difficulty { easy = 5, medium, hard };
private:
    int miSize;
    bool mbaShips[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
    bool mbaAttacked[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
};

#endif /* GAMEBOARD_H */

