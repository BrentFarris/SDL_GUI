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
			string text;

		public:
			SDL_GUI_Button(SDL_Surface* screen, InputManager* passedInputManager);
			SDL_GUI_Button(SDL_Surface* screen, InputManager* passedInputManager, string txt);

			void Update();

			~SDL_GUI_Button() { }
	};
}