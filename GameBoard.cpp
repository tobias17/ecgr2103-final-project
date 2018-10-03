/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "GameBoard.h"

using namespace std;

GameBoard::GameBoard(int iSize) {
    // initialize the arrays
    miSize = iSize;
    mbaShips[iSize][iSize];
    mbaAttacked[iSize][iSize];
    for (int x = 0; x < iSize; x++) {
        for (int y = 0; y < iSize; y++) {
            mbaShips[x][y] = false;
            mbaAttacked[x][y] = false;
        }
    }
}

bool GameBoard::getHitAndMark(int iX, int iY) {
    
}

string GameBoard::getBoardToString() {
    
}