#include "Button.h"

SDL_GUI::Button::Button(SDL_Surface* screen, InputManager* passedInputManager, TTF_Font* pfont) : SDL_GUI::GUI_Element(screen, passedInputManager)
{
	text = "Button";
	textBlock = TextBlock(screen, passedInputManager, pfont, text);
	textBlock.SetColor(175);
	lastRect = rect;
}

SDL_GUI::Button::Button(SDL_Surface* screen, InputManager* passedInputManager, TTF_Font* pfont, string txt) : SDL_GUI::GUI_Element(screen, passedInputManager)
{
	text = txt;
	textBlock = TextBlock(screen, passedInputManager, pfont, text);
	textBlock.SetColor(175);
	lastRect = rect;
}

void SDL_GUI::Button::Update()
{
	SDL_GUI::GUI_Element::Update();

	if (lastRect != rect)
		textBlock.rect.Center(rect);

	lastRect = rect;

	textBlock.Update();
}

void SDL_GUI::Button::Draw(SDL_Surface* screen)
{
	SDL_FillRect(screen, &rect.SDL_Format(), backgroundColor);
	textBlock.Draw(screen);
}