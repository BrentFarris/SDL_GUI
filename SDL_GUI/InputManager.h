#ifndef IMAGE_MANAGER_H
#define IMAGE_MANAGER_H
#endif

#pragma once

#include "SDL.h"

class InputManager
{
	private:
		int mouseX;
		int mouseY;

		bool mouseInitialClick;
		bool mouseInitialRelease;

		int screenWidth;
		int screenHeight;
		int screenBPP;

	public:
		SDL_Event event;

		InputManager(int screenSizeX, int screenSizeY, int bppScreen);

		void Update(SDL_Surface* screen, bool* quit);
		int GetMouseX() { return mouseX; }
		int GetMouseY() { return mouseY; }
		int GetScreenWidth() { return screenWidth; }
		int GetScreenHeight() { return screenHeight; }
		bool MouseDown() { return mouseInitialClick; }
		bool MouseUp() { return mouseInitialRelease; }

		~InputManager()
		{

		}
};