#include "Button.h"

SDL_GUI::Button::Button(SDL_Surface* screen, InputManager* passedInputManager) : SDL_GUI::GUI_Element(screen, passedInputManager)
{
	text = "Button";
}

SDL_GUI::Button::Button(SDL_Surface* screen, InputManager* passedInputManager, string txt) : SDL_GUI::GUI_Element(screen, passedInputManager)
{
	text = txt;
}

/*
void SDL_GUI::Button::Update()
{
	SDL_GUI::GUI_Element::Update();
}
*/

void SDL_GUI::Button::Draw(SDL_Surface* screen)
{
	SDL_FillRect(screen, &rect.SDL_Format(), backgroundColor);
}