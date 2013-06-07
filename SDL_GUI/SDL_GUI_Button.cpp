#include "SDL_GUI_Button.h"

SDL_GUI::SDL_GUI_Button::SDL_GUI_Button(SDL_Surface* screen, InputManager* passedInputManager) : SDL_GUI::SDL_GUI_Element(screen, passedInputManager)
{
	text = "Button";
}

SDL_GUI::SDL_GUI_Button::SDL_GUI_Button(SDL_Surface* screen, InputManager* passedInputManager, string txt) : SDL_GUI::SDL_GUI_Element(screen, passedInputManager)
{
	text = txt;
}

void SDL_GUI::SDL_GUI_Button::Update()
{
	SDL_GUI::SDL_GUI_Element::Update();
}