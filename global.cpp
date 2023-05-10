#include "global.h"

SDL_Window* gWindow = NULL;

SDL_Renderer* gRenderer = NULL;

TTF_Font* gFont;

LButton gBox[NUM_BOX_OF_EDGE * NUM_BOX_OF_EDGE];

LTexture gSpriteClip[TOTAL_BOX];

LTexture gPlayer1Win;
LTexture gPlayer2Win;
LTexture gDrawTexture;

char gTick = 'X';

LTexture textTexture;
LTexture gBGEndGame ;
LTexture gBGTexture;
LTexture gBGMenu;
menuButton gStartButton;
menuButton gExitButton;
menuButton gMenuButton;
menuButton gPlayAgainButton;
