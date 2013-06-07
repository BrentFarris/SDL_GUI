/////////////////////////////////////////////////
//                                             //
// Brent Farris, Bearded Man Studios, Inc.     //
// https://www.beardedmangames.com/            //
//                                             //
/////////////////////////////////////////////////
//                                             //
// This is a simple button class mainly using  //
// a rectangle to keep track of all events.    //
//                                             //
/////////////////////////////////////////////////

#ifndef SDL_GUI_BUTTON_H
#define SDL_GUI_BUTTON_H
#endif

#pragma once

#include "SDL_GUI_Element.h"
#include <string>

using namespace std;

namespace SDL_GUI
{
	class SDL_GUI_Button : public SDL_GUI_Element
	{
		protected:
			string text;			// Will be used to  have text on button

		public:
			SDL_GUI_Button(SDL_Surface* screen, InputManager* passedInputManager);					// Initializes button with text as "button"
			SDL_GUI_Button(SDL_Surface* screen, InputManager* passedInputManager, string txt);		// Initialize the button with text

			// If needed to overridee
			// void Update();

			~SDL_GUI_Button() { }
	};
}