/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Tobias Fischer
 *
 * Created on October 3, 2018, 10:27 AM
 */

#include <cstdlib>
#include <iostream>

#include "GameBoard.h"

using namespace std;

string boolToString(bool b) {
    return (b ? "True" : "False");
}

/*
 * 
 */
int main(int argc, char** argv) {

    GameBoard oBoard(GameBoard::easy);
    
    cout << oBoard.getBoardToString();
    
    cout << boolToString(oBoard.getHitAndMark(0, 0)) << endl;
    cout << boolToString(oBoard.getHitAndMark(1, 1)) << endl;
    cout << boolToString(oBoard.getHitAndMark(2, 2)) << endl;
    cout << boolToString(oBoard.getHitAndMark(3, 3)) << endl;
    cout << boolToString(oBoard.getHitAndMark(4, 4)) << endl;
    
    cout << oBoard.getBoardToString();
    
    return 0;
}

