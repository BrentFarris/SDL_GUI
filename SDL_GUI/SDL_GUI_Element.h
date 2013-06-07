/////////////////////////////////////////////////
//                                             //
// Brent Farris, Bearded Man Studios, Inc.     //
// https://www.beardedmangames.com/            //
//                                             //
/////////////////////////////////////////////////
//                                             //
// This is the mian parent class for all of    //
// GUI elements to be made.                    //
//                                             //
/////////////////////////////////////////////////

#ifndef SDL_GUI_ELEMENT_H
#define SDL_GUI_ELEMENT_H
#endif

#pragma once

#include "SDL.h"
#include "Rectangle.h"
#include "InputManager.h"

namespace SDL_GUI
{
	class SDL_GUI_Element
	{
		private:
			bool mouseIsOver;
			bool performingClick;
			Uint32 backgroundColor;

		protected:
			void (*onMouseUp)(void);		// The mouse up callback
			void (*onMouseDown)(void);		// The mouse down callback
			void (*onMouseOver)(void);		// The mouse over callback
			void (*onMouseOut)(void);		// The mouse out callback
			void (*onClick)(void);			// The click callback

		public:
			Rectangle rect;
			InputManager* inputManager;

			SDL_GUI_Element(SDL_Surface* screen, InputManager* passedInputManager);

			void SetOnClick(void (*callback)(void))		{ onClick		= callback; }
			void SetMouseUp(void (*callback)(void))		{ onMouseUp		= callback; }
			void SetMouseDown(void (*callback)(void))	{ onMouseDown	= callback; }
			void SetMouseOver(void (*callback)(void))	{ onMouseOver	= callback; }
			void SetMouseOut(void (*callback)(void))	{ onMouseOut	= callback; }

			virtual void Update();
			virtual void Draw(SDL_Surface* screen);
			
			~SDL_GUI_Element() { }
	};
}