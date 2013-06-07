#ifndef TEXTBLOCK_H
#define TEXTBLOCK_H
#endif

#pragma once

#include "GUI_Element.h"
#include "SDL_TTF.h"
#include <string>

namespace SDL_GUI
{
	class TextBlock : public GUI_Element
	{
		private:
			SDL_Color fontColor;
			SDL_Surface* message;
			
			void RenderText();

		public:
			string text;
			TTF_Font* font;
			
			TextBlock(SDL_Surface* screen, InputManager* passedInputManager, TTF_Font* pfont);
			TextBlock(SDL_Surface* screen, InputManager* passedInputManager, TTF_Font* pfont, string txt);

			void Draw(SDL_Surface* screen);
			void ChangeText(string newText);			// This allows for the text to be changed and updated

			~TextBlock() { }
	};
}