#include "logicGame.h"
#include "global.h"
#include "Constants.h"
#include "LButton.h"

bool isWinner(int row, int col, int dRow, int dCol)
{
    if (gBox[row * NUM_BOX_OF_EDGE + col].getTick() == 'N')
    {
        return false;
    }
    for (int i = 0; i < 5; i++) {
        int r = row + i * dRow;
        int c = col + i * dCol;
        if (r < 0 || r >= NUM_BOX_OF_EDGE || c < 0 || c >= NUM_BOX_OF_EDGE || gBox[r * NUM_BOX_OF_EDGE + c].getTick() != gBox[row * NUM_BOX_OF_EDGE + col].getTick())
        {
            return false;
        }
    }
    return true;
}

bool isWinnerOnRows()
{
    for (int row = 0; row < NUM_BOX_OF_EDGE; row++) {
        for (int col = 0; col <= NUM_BOX_OF_EDGE - 5; col++) {
            if (isWinner(row, col, 0, 1)) {
                return true;
            }
        }
    }
    return false;
}

bool isWinnerOnCols()
{
    for (int row = 0; row <= NUM_BOX_OF_EDGE - 5; row++) {
        for (int col = 0; col < NUM_BOX_OF_EDGE; col++) {
            if (isWinner(row, col, 1, 0)) {
                return true;
            }
        }
    }
    return false;
}

bool isWinnerOnMainDiagonals()
{
    for (int row = 0; row <= NUM_BOX_OF_EDGE - 5; row++) {
        for (int col = 0; col <= NUM_BOX_OF_EDGE - 5; col++) {
            if (isWinner(row, col, 1, 1)) {
                return true;
            }
        }
    }
    return false;
}

bool isWinnerOnAntiDiagonals()
{
    for (int row = 0; row <= NUM_BOX_OF_EDGE - 5; row++) {
        for (int col = 0; col <= NUM_BOX_OF_EDGE - 5; col++) {
            if (isWinner(row, col, 1, -1)) {
                return true;
            }
        }
    }
    return false;
}

bool getWin()
{
    for (int i = 0; i < NUM_BOX_OF_EDGE; i++) {
        if (isWinnerOnRows()) {
            return true;
        }
        if (isWinnerOnCols()) {
            return true;
        }
    }

    if (isWinnerOnMainDiagonals()) {
        return true;
    }
    if (isWinnerOnAntiDiagonals()) {
        return true;
    }

    return false;
}
