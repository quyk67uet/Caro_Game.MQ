#include "UTIL.h"
#include "LButton.h"
#include "Constants.h"
#include "global.h"
#include "logicGame.h"
#include "LTexture.h"

int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//Sound effect

			Mix_Music* music = Mix_LoadMUS("music.mp3");
			Mix_PlayMusic(music, -1);
			Mix_Chunk* clickSound = Mix_LoadWAV("click.wav");

			//Menu
			gameManger mode = MENU;

			//While application is running
			while (!quit)
			{
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					//User requests quit
					if (e.type == SDL_QUIT || mode == QUIT)
					{
						quit = true;
					}

					if (e.type == SDL_MOUSEBUTTONDOWN)
					{
						Mix_PlayChannel(-1, clickSound, 0);
					}

					if (mode == RESET_GAME)
					{
						for (int i = 0; i < TOTAL; ++i)
						{
							gBox[i].reset();
						}
						for (int i = 0; i < TOTAL; ++i)
						{
							gBox[i].renderRect();
						}

						for (int i = 0; i < TOTAL; ++i)
						{
							gBox[i].renderTexture();
						}
						mode = IN_GAME;
					}

					else if (mode == IN_GAME)
					{
						//Handle button events
						for (int i = 0; i < TOTAL; ++i)
						{
							gBox[i].handleEvent(&e);
						}
					}

					else if (mode == HAVE_WINNER) {
						mode = END_GAME;
					}
					else if (mode == MENU)
					{
						gStartButton.handleEvent(&e);
						if (gStartButton.isPressted())
						{
							mode = IN_GAME;
							mode = RESET_GAME;
							gStartButton.reverse();

						}
						gExitButton.handleEvent(&e);
						if (gExitButton.isPressted())
						{
							mode = QUIT;
						}
					}
					else if (mode == END_GAME)
					{
						gPlayAgainButton.handleEvent(&e);
						if (gPlayAgainButton.isPressted())
						{
							mode = RESET_GAME;
							gPlayAgainButton.reverse();
						}
						gMenuButton.handleEvent(&e);
						if (gMenuButton.isPressted())
						{
							mode = MENU;
							gMenuButton.reverse();
						}
						gExitButton.handleEvent(&e);
						if (gExitButton.isPressted())
						{
							mode = QUIT;
						}
					}
				}

				//Clear screen
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);


				gBGTexture.render(0, 0);

				if ( mode == IN_GAME || mode == HAVE_WINNER)
				{
					textTexture.render((SCREEN_WIDTH - textTexture.getWidth()) / 2, 5);

					for (int i = 0; i < TOTAL; ++i)
					{
						gBox[i].renderRect();
					}

					for (int i = 0; i < TOTAL; ++i)
					{
						gBox[i].renderTexture();
					}

					if (getWin())
					{
						mode = HAVE_WINNER;
						if (gTick == 'X')
						{
							gPlayer2Win.render(0, 0);
						}
						else
						{
							gPlayer1Win.render(0, 0);
						}
					}

					bool GameEnd = true;
					for (int i = 0; i < TOTAL; ++i)
					{
						if (gBox[i].getTick() == 'N')
							GameEnd = false;
					}

					if (GameEnd)
					{
						std::cout << "Game draw" << std::endl;
						quit = true;
					}
				}

				else if (mode == MENU)
				{
					gBGMenu.render(0, 0);
					textTexture.render((SCREEN_WIDTH - textTexture.getWidth()) / 2, 200);
					gStartButton.render();
					gExitButton.render();
				}
				else if (mode == END_GAME)
				{
					gBGEndGame.render(0, 0);
					textTexture.render((SCREEN_WIDTH - textTexture.getWidth()) / 2, 100);
					gPlayAgainButton.render();
					gMenuButton.render();
					gExitButton.render();
				}

				SDL_RenderPresent(gRenderer);
			}
		}
	}
	//Free resources and close SDL
	close();
	return 0;
}
