#ifndef LBUTTON_H_
#define LBUTTON_H_

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <cstring>
#include "Constants.h"

class LButton
{
public:
    LButton();

    void setPosition(int x, int y);

    void handleEvent(SDL_Event* e);

    void renderTexture();
    void reset();

    void renderRect();

    SDL_Rect getRect();

    char getTick();
private:
    SDL_Rect mPosition;

    LBox mCurrentSpite;

    char tick;

    bool gTicked;
};

#endif // LBUTTON__H_
