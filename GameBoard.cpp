/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "GameBoard.h"

GameBoard::GameBoard(int aSize) {
    // initialize the arrays
    size = aSize;
    for (int x = 0; x < MAX_BOARD_SIZE; x++) {
        for (int y = 0; y < MAX_BOARD_SIZE; y++) {
            ships[x][y] = false;
            attacked[x][y] = false;
        }
    }
    
    // loop through all ships
    for (int ship = 0; ship < SHIP_AMNT; ship++) {
        // grab how long the ship we are adding is
        int shipSize = ShipSizes[ship];
        
        // generate a vector to hold all the possible ship placements
        vector<Point> poss;
        
        // add all possible horizontal ship placements
        for (int dx = 0; dx < size - shipSize; dx++) {
            for (int dy = 0; dy < size; dy++) {
                bool worked = true;
                for (int i = 0; i < shipSize; i++) {
                    if (ships[dx + i][dy]) {
                        worked = false;
                        break;
                    }
                }
                if (worked) {
                    poss.push_back(Point(dx, dy, Point::right));
                }
            }
        }
        
        // add all possible vertical ship placements
        for (int dx = 0; dx < size; dx++) {
            for (int dy = 0; dy < size - shipSize; dy++) {
                bool worked = true;
                for (int i = 0; i < shipSize; i++) {
                    if (ships[dx][dy + i]) {
                        worked = false;
                        break;
                    }
                }
                if (worked) {
                    poss.push_back(Point(dx, dy, Point::down));
                }
            }
        }
        
        // add the ship from a random placement
        srand(time(0));
        int index = rand() % poss.size();
        Point shipPoint = poss.at(index);
        for (int i = 0; i < shipSize; i++) {
            ships[shipPoint.x][shipPoint.y] = true;
            if (shipPoint.dir == Point::right) {
                shipPoint.x++;
            } else {
                shipPoint.y++;
            }
        }
    }
}

bool GameBoard::getHitAndMark(int aX, int aY) {
    attacked[aX][aY] = true;
    return ships[aX][aY];
}

string GameBoard::getBoardToString() {
    stringstream boardString;
    boardString << " ";
    for (int y = 0; y < size; y++) {
        boardString << " ";
        boardString << ((char)(65 + y));
    }
    boardString << "\n";
    for (int x = 0; x < size; x++) {
        boardString << (x + 1);
        for (int y = 0; y < size; y++) {
            boardString << " ";
            boardString << ((attacked[x][y]) ? ((ships[x][y]) ? SHIPS_CHAR : EMPTY_CHAR) : UNKNOWN_CHAR);
        }
        boardString << "\n";
    }
    return boardString.str();
}

bool GameBoard::getIsGameOver() {
    bool gameOver = true;
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            if (ships[x][y] && !attacked[x][y]) {
                gameOver = false;
            }
        }
    }
    return gameOver;
}