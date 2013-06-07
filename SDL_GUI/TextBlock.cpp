#include "TextBlock.h"

SDL_GUI::TextBlock::TextBlock(SDL_Surface* screen, InputManager* passedInputManager, TTF_Font* pfont) : SDL_GUI::GUI_Element(screen, passedInputManager)
{
	fontColor = SDL_Color();
	font = pfont;
	text = "";
	RenderText();
}

SDL_GUI::TextBlock::TextBlock(SDL_Surface* screen, InputManager* passedInputManager, TTF_Font* pfont, string txt) : SDL_GUI::GUI_Element(screen, passedInputManager)
{
	fontColor = SDL_Color();
	font = pfont;
	text = txt;
	RenderText();
}

void SDL_GUI::TextBlock::ChangeText(string newText)
{
	text = newText;
	SDL_FreeSurface(message);
	RenderText();
}

void SDL_GUI::TextBlock::RenderText()
{
	message = TTF_RenderText_Solid(font, text.c_str(), fontColor);
}

void SDL_GUI::TextBlock::Draw(SDL_Surface* screen)
{
	SDL_BlitSurface(message, NULL, screen, &rect.SDL_Format());
}