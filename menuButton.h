
#ifndef MENU_BUTTON_H_
#define MENU_BUTTON_H_

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "LTexture.h"
#include "Constants.h"

class menuButton
{
public:
	menuButton();
	menuButton(int posX, int posY, int width, int height);
	~menuButton();

	void setPosition(int posX, int posY, int width = 0, int height = 0);
	void handleEvent(SDL_Event* e);
	void render();

	void loadButtonTexture(std::string path);
	bool loadButtonTextureFromText(std::string path, std::string str, int size, SDL_Color textColor = { 51, 153, 255 });

	int getWidth();
	int getHeight();

	SDL_Rect getBox();
	bool isPressted();
	void reverse();

private:
	SDL_Rect buttonBox;

	LTexture buttonTexture;
	LTexture touchedButtonTexture;
	LTexture pressingButtonTexture;

	bool pressed;

	buttonStatus button;
};


#endif // !MENU_BUTTON_H_
