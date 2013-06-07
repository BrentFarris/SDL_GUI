/////////////////////////////////////////////////
//                                             //
// Brent Farris, Bearded Man Studios, Inc.     //
// https://www.beardedmangames.com/            //
//                                             //
/////////////////////////////////////////////////
//                                             //
// This is just a simple image manager to      //
// prototype out general functionality for     //
// the library.                                //
//                                             //
/////////////////////////////////////////////////

#ifndef IMAGE_MANAGER_H
#define IMAGE_MANAGER_H
#endif

#pragma once

#include "SDL.h"
#include "Vector2.h"

class InputManager
{
	private:
		Vector2 mousePosition;											// The current mouse position

		bool mouseInitialClick;											// The initial click of the mouse (reset next update)
		bool mouseInitialRelease;										// The initial release of the mouse (reset next update)

		int screenWidth;												// The width of the window (adjustable)
		int screenHeight;												// The height of the window (adjustable)
		int screenBPP;													// Usually set to 32 (bit)

	public:
		SDL_Event event;												// The main SDL event

		InputManager(int screenSizeX, int screenSizeY, int bppScreen);	// These inputs are used for refreshing the SDL_SetVideoMode

		void Update(SDL_Surface* screen, bool* quit);					// Up the event loop
		Vector2 GetMousePosition() { return mousePosition; }
		int GetScreenWidth() { return screenWidth; }
		int GetScreenHeight() { return screenHeight; }
		bool MouseDown() { return mouseInitialClick; }
		bool MouseUp() { return mouseInitialRelease; }

		~InputManager()
		{

		}
};