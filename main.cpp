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

enum Players { player1, player2 };

/*
 * 
 */
int main(int argc, char** argv) {

    
    bool gameIsRunning = true;
    
    while (true) {
        // setup before game starts
        
        // set the current player to player1
        int currPlayer = player1;
        
        // create the new game boards
        int diff = GameBoard::easy;
        GameBoard boards[2] = { GameBoard(diff), GameBoard(diff) };
        
        while (gameIsRunning) {
            
            // kill for now to not get infinite loop
            break;
            
            // toggle the current player
            if (currPlayer == player1) {
                currPlayer = player2;
            } else {
                currPlayer = player1;
            }
        }
        
        // ask the user if he wants to play again
        
    }
    
    
    GameBoard board(GameBoard::easy);
    
    cout << board.getBoardToString();
    
    for (int x = 0; x < board.getSize(); x++) {
        for (int y = 0; y < board.getSize(); y++) {
            cout << boolToString(board.getHitAndMark(x, y)) << endl;
            if (board.getIsGameOver()) {
                cout << board.getBoardToString();
                return 1;
            }
        }
    }
    
    cout << board.getBoardToString();
    
    return 0;
}

