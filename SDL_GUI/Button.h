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

#include "GUI_Element.h"
#include "TextBlock.h"
#include <string>

namespace SDL_GUI
{
	class Button : public GUI_Element
	{
		protected:
			TextBlock textBlock;
			string text;			// Will be used to  have text on button
			Rectangle lastRect;

		public:
			Button(SDL_Surface* screen, InputManager* passedInputManager, TTF_Font* pfont);					// Initializes button with text as "button"
			Button(SDL_Surface* screen, InputManager* passedInputManager, TTF_Font* pfont, string txt);		// Initialize the button with text

			void Update();
			void Draw(SDL_Surface* screen);

			~Button() { }
	};
}