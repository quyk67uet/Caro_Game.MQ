#ifndef LOGICGAME_H_
#define LOGICGAME_H_

bool isWinner( int row, int col,int dRow, int dCol );

bool isWinnerOnRows();

bool isWinnerOnCols();

bool isWinnerOnMainDiagonals();

bool isWinnerOnAntiDiagonals();

bool getWin();

#endif // LOGICGAME_H_
