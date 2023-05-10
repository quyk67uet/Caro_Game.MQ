#ifndef CONSTANT_H_
#define CONSTANT_H_

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

const int BOX_EDGE_LENGTH = 30;
const int NUM_BOX_OF_EDGE = 12;

const int TOTAL = NUM_BOX_OF_EDGE * NUM_BOX_OF_EDGE;
enum LBox
{
    EMPTY_BOX,
    PRESSING_BOX,
    X_TICKED_BOX,
    O_TICKED_BOX,
    TOTAL_BOX
};

enum gameManger
{
    MENU,
    IN_GAME,
    OPTION,
    QUIT,
    HAVE_WINNER,
    END_GAME,
    RESET_GAME,
};

enum buttonStatus
{
    PRESSING,
    PRESSED,
    MOVED_IN,
    NORMAL,
};
#endif // CONSTANT_H_
