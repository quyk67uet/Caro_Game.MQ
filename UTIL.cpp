#include "UTIL.h"
#include "global.h"
#include "Constants.h"

bool init()
{
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Failed to initializes\n";
        success = false;
    }
    else
    {
        //Set texture filltering to linear
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");


        gWindow = SDL_CreateWindow("Caro Game MQ", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            std::cout << "Failed to create window\n";
            success = false;
        }
        else
        {
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (gRenderer == NULL)
            {
                std::cout << "Renderer could not be create! SDL Error: " << SDL_GetError() << std::endl;
                success = false;
            }
            else
            {
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags))
                {
                    std::cout << "SDL image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
                    success = false;
                }
                if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
                {
                    printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
                    success = false;
                }

                if (TTF_Init() == -1)
                {
                    std::cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << std::endl;
                    success = false;
                }
            }
        }
    }
    return success;
}

bool loadMedia()
{
    bool success = true;
    if (!gSpriteClip[PRESSING_BOX].loadFromFile("empty.png"))
    {
        std::cout << "Failed to load empty box texture!\n";
        success = false;
    }
    if (!gSpriteClip[X_TICKED_BOX].loadFromFile("Red-X.png"))
    {
        std::cout << "Failed to load X ticked box texture!\n";
        success = false;
    }
    if (!gSpriteClip[O_TICKED_BOX].loadFromFile("Blue-O.png"))
    {
        std::cout << "Failed to load O ticked box texture!\n";
        success = false;
    }
    if (!gPlayer1Win.loadFromFile("Player1Win.png"))
    {
        std::cout << "Failed to load player 1 win texture!\n";
        success = false;
    }
    if (!gPlayer2Win.loadFromFile("Player2Win.png"))
    {
        std::cout << "Failed to load player 2 win texture!\n";
        success = false;
    }
    if (!gBGTexture.loadFromFile("back_ground.jpg"))
    {
        std::cout << "Failed to load back ground texture\n";
        success = false;
    }

    if (!gBGMenu.loadFromFile("menu.jpg"))
    {
        std::cout << "Failed to load back ground texture\n";
        success = false;
    }
     if (!gBGEndGame.loadFromFile("BGEndGame.jpg"))
    {
        std::cout << "Failed to load back ground texture\n";
        success = false;
    }

    gFont = TTF_OpenFont("NiceSugar.ttf", 50);
    if (gFont == NULL)
    {
        std::cout << "Failed to load lazy font! SDL_ttf Error: " << TTF_GetError() << std::endl;
        success = false;
    }
    else
    {
        SDL_Color textColor = { 95, 158, 160 };
        if (!textTexture.loadFromRenderedText("Caro Game MQ", textColor))
        {
            std::cout << "Failed to render text texture! \n";
            success = false;
        }
    }

    if (!gStartButton.loadButtonTextureFromText("NiceSugar.ttf", "Start", 50))
    {
        std::cout << "Failed to load 'Start' button\n";
        success = false;
    }
    gStartButton.setPosition((SCREEN_WIDTH - gStartButton.getWidth()) / 2, 300);
    if (!gExitButton.loadButtonTextureFromText("NiceSugar.ttf", "Exit", 50))
    {
        std::cout << "Failed to load 'Exit' button\n";
        success = false;
    }
    gExitButton.setPosition((SCREEN_WIDTH - gExitButton.getWidth()) / 2, 400);
    if (!gMenuButton.loadButtonTextureFromText("NiceSugar.ttf", "Menu", 50))
    {
        std::cout << "Failed to load 'Menu' button\n";
        success = false;
    }
    gMenuButton.setPosition((SCREEN_WIDTH - gMenuButton.getWidth()) / 2, 300);
    if (!gPlayAgainButton.loadButtonTextureFromText("NiceSugar.ttf", "Play Again", 50))
    {
        std::cout << "Failed to load 'Play Again' button\n";
        success = false;
    }
    gPlayAgainButton.setPosition((SCREEN_WIDTH - gPlayAgainButton.getWidth()) / 2, 200);

    int PosX = (SCREEN_WIDTH - BOX_EDGE_LENGTH * NUM_BOX_OF_EDGE) / 2, PosY = (SCREEN_HEIGHT - NUM_BOX_OF_EDGE * BOX_EDGE_LENGTH) / 2;
    for (int i = 0; i < NUM_BOX_OF_EDGE; ++i)
    {
        for (int j = 0; j < NUM_BOX_OF_EDGE; ++j)
        {
            gBox[i * NUM_BOX_OF_EDGE + j].setPosition(PosX + j * BOX_EDGE_LENGTH, PosY + i * BOX_EDGE_LENGTH);
        }
    }
    return success;
}

void close()
{
    SDL_DestroyWindow(gWindow);
    SDL_DestroyRenderer(gRenderer);
    gWindow = NULL;
    gRenderer = NULL;

    for (int i = 0; i < TOTAL_BOX; ++i)
    {
        gSpriteClip[i].free();
    }
}
