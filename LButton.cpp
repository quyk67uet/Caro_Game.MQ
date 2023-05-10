#include "LButton.h"
#include "global.h"


LButton::LButton()
{
    mPosition.x = 0;
    mPosition.y = 0;
    mPosition.w = BOX_EDGE_LENGTH;
    mPosition.h = BOX_EDGE_LENGTH;

    mCurrentSpite = EMPTY_BOX;

    tick = 'N';

    gTicked = false;
}

void LButton::setPosition(int x, int y)
{
    mPosition.x = x;
    mPosition.y = y;
}

void LButton::handleEvent(SDL_Event* e)
{
    //If mouse event happened
    if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
    {
        //Get mouse position
        int x, y;
        SDL_GetMouseState(&x, &y);

        bool inside = true;

        if (x < mPosition.x ||
            x > mPosition.x + BOX_EDGE_LENGTH ||
            y < mPosition.y ||
            y > mPosition.y + BOX_EDGE_LENGTH)
            inside = false;
        if (!inside)
        {
            mCurrentSpite = EMPTY_BOX;
        }
        else
        {
            switch (e->type)
            {
            case SDL_MOUSEBUTTONDOWN:
                mCurrentSpite = PRESSING_BOX;
                break;

            case SDL_MOUSEBUTTONUP:
                if (tick == 'N')
                {
                    tick = gTick;

                    if (gTick == 'O')
                        gTick = 'X';
                    else
                        gTick = 'O';
                }
                break;

            }
        }
    }
}

SDL_Rect LButton::getRect()
{
    return mPosition;
}

char LButton::getTick()
{
    return tick;
}

void LButton::renderTexture()
{
    if (tick == 'O')
    {
        gSpriteClip[O_TICKED_BOX].render(mPosition.x, mPosition.y);
        return;
    }
    if (tick == 'X')
    {
        gSpriteClip[X_TICKED_BOX].render(mPosition.x, mPosition.y);
        return;
    }
    if (mCurrentSpite != EMPTY_BOX)
        gSpriteClip[mCurrentSpite].render(mPosition.x, mPosition.y);
}

void LButton::renderRect()
{
    SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderDrawRect(gRenderer, &mPosition);
}

void LButton::reset()
{
    tick = 'N';
}

