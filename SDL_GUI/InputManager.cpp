#include "InputManager.h"

InputManager::InputManager(int screenSizeX, int screenSizeY, int bppScreen)
{
	mouseX					= 0;
	mouseY					= 0;

	mouseInitialClick		= false;
	mouseInitialRelease		= false;

	screenWidth				= screenSizeX;
	screenHeight			= screenSizeY;
	screenBPP				= bppScreen;
}

void InputManager::Update(SDL_Surface* screen, bool* quit)
{
	mouseInitialClick = false;
	mouseInitialRelease = false;

	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			//If a key was pressed
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
					case SDLK_UP:
						break;
					case SDLK_DOWN:
						break;
					case SDLK_LEFT:
						break;
					case SDLK_RIGHT:
						break;
				}
				break;
			case SDL_MOUSEMOTION:								// If the mouse was moved
				// Get the mouse offsets
				mouseX = event.motion.x;
				mouseY = event.motion.y;
				break;
			case SDL_MOUSEBUTTONDOWN:							// If the mouse button was clicked
				// If it was the left mouse button
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					mouseInitialClick = true;

					mouseX = event.button.x;
					mouseY = event.button.y;
				}
				break;
			case SDL_MOUSEBUTTONUP:								// If the mouse button was released
				// If it was the left mouse button
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					mouseInitialRelease = true;

					mouseX = event.button.x;
					mouseY = event.button.y;
				}
				break;
			case SDL_VIDEORESIZE:
				screenWidth = event.resize.w;
				screenHeight = event.resize.h;
				screen = SDL_SetVideoMode(screenWidth, screenHeight, screenBPP, SDL_SWSURFACE | SDL_RESIZABLE); // Create new window
				break;
			case SDL_QUIT:
				*quit = true;
				break;
		}
	}
}