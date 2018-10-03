/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "GameBoard.h"

GameBoard::GameBoard(int iSize) {
    // initialize the arrays
    miSize = iSize;
    for (int x = 0; x < MAX_BOARD_SIZE; x++) {
        for (int y = 0; y < MAX_BOARD_SIZE; y++) {
            mbaShips[x][y] = false;
            mbaAttacked[x][y] = false;
        }
    }
    
    // loop through all ships
    for (int ship = 0; ship < SHIP_AMNT; ship++) {
        // grab how long the ship we are adding is
        int iShipSize = ShipSizes[ship];
        
        // generate a vector to hold all the possible ship placements
        vector<Point> ovPoss;
        
        // add all possible horizontal ship placements
        for (int dx = 0; dx < iSize - iShipSize; dx++) {
            for (int dy = 0; dy < iSize; dy++) {
                bool worked = true;
                for (int i = 0; i < iShipSize; i++) {
                    if (mbaShips[dx + i][dy]) {
                        worked = false;
                        break;
                    }
                }
                if (worked) {
                    ovPoss.push_back(Point(dx, dy, Point::right));
                }
            }
        }
        
        // add all possible vertical ship placements
        for (int dx = 0; dx < iSize; dx++) {
            for (int dy = 0; dy < iSize - iShipSize; dy++) {
                bool worked = true;
                for (int i = 0; i < iShipSize; i++) {
                    if (mbaShips[dx][dy + i]) {
                        worked = false;
                        break;
                    }
                }
                if (worked) {
                    ovPoss.push_back(Point(dx, dy, Point::down));
                }
            }
        }
        
        // add the ship from a random placement
        srand(time(0));
        int iIndex = rand() % ovPoss.size();
        Point oShipPoint = ovPoss.at(iIndex);
        for (int i = 0; i < iShipSize; i++) {
            mbaShips[oShipPoint.x][oShipPoint.y] = true;
            if (oShipPoint.dir == Point::right) {
                oShipPoint.x++;
            } else {
                oShipPoint.y++;
            }
        }
    }
}

bool GameBoard::getHitAndMark(int iX, int iY) {
    mbaAttacked[iX][iY] = true;
    return mbaShips[iX][iY];
}

string GameBoard::getBoardToString() {
    stringstream sBoard;
    for (int x = 0; x < miSize; x++) {
        for (int y = 0; y < miSize; y++) {
            sBoard << ((mbaAttacked[x][y]) ? ((mbaShips[x][y]) ? SHIPS_CHAR : EMPTY_CHAR) : UNKNOWN_CHAR);
            sBoard << " ";
        }
        sBoard << "\n";
    }
    return sBoard.str();
}