#ifndef GLOBAL_H_
#define GLOBAL_H_

#include "UTIL.h"
#include "LButton.h"
#include "Constants.h"
#include "LTexture.h"
#include "menuButton.h"

extern SDL_Window* gWindow;

extern SDL_Renderer* gRenderer;

extern TTF_Font* gFont;

extern LButton gBox[NUM_BOX_OF_EDGE * NUM_BOX_OF_EDGE];

extern LTexture gSpriteClip[TOTAL_BOX];

extern LTexture gPlayer1Win;
extern LTexture gPlayer2Win;
extern LTexture gDrawTexture;

extern char gTick;

extern LTexture textTexture;

extern LTexture gBGTexture;
extern LTexture gBGMenu;
extern menuButton gStartButton;
extern menuButton gExitButton;
extern menuButton gPlayAgainButton;
extern LTexture gBGEndGame;

extern menuButton gMenuButton;
#endif // GLOBAL_H_
