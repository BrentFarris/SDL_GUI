#include "TextBlock.h"

SDL_GUI::TextBlock::TextBlock()
{
	message = NULL;
}

SDL_GUI::TextBlock::TextBlock(SDL_Surface* screen, InputManager* passedInputManager, TTF_Font* pfont) : SDL_GUI::GUI_Element(screen, passedInputManager)
{
	fontColor = SDL_Color();
	font = pfont;
	text = "";
	message = NULL;
	RenderText();
}

SDL_GUI::TextBlock::TextBlock(SDL_Surface* screen, InputManager* passedInputManager, TTF_Font* pfont, string txt) : SDL_GUI::GUI_Element(screen, passedInputManager)
{
	fontColor = SDL_Color();
	font = pfont;
	text = txt;
	message = NULL;
	RenderText();
}

void SDL_GUI::TextBlock::ChangeText(string newText)
{
	text = newText;
	RenderText();
}

void SDL_GUI::TextBlock::RenderText()
{
	if (message != NULL)
		SDL_FreeSurface(message);

	message = TTF_RenderText_Solid(font, text.c_str(), fontColor);
	rect.width = message->w;
	rect.height = message->h;
}

void SDL_GUI::TextBlock::Draw(SDL_Surface* screen)
{
	SDL_BlitSurface(message, NULL, screen, &rect.SDL_Format());
}

void SDL_GUI::TextBlock::SetColor(int r, int g, int b)
{
	fontColor.r = r;
	fontColor.g = g;
	fontColor.b = b;
	RenderText();
}

void SDL_GUI::TextBlock::SetColor(int grayscale)
{
	fontColor.r = grayscale;
	fontColor.g = grayscale;
	fontColor.b = grayscale;
	RenderText();
}