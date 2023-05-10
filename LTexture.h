#ifndef LTEXTURE_H_
#define LTEXTURE_H_

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>
#include <string>
#include <fstream>

class LTexture
{
public:
    LTexture();
    ~LTexture();

    int getWidth();
    int getHeight();

    bool loadFromFile(std::string path);
    bool loadFromRenderedText(std::string textureText, SDL_Color textColor);
    void render(int x, int y, SDL_Rect* clip = NULL);
    void free();
    void setColor(Uint8 r, Uint8 g, Uint8 b);
    void setBlendMode(SDL_BlendMode blending);
    void setAlpha(Uint8 alpha);

private:
    SDL_Texture* mTexture;

    int mWidth, mHeight;
};


#endif // !LTEXTURE_H_

