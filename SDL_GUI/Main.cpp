#include "SDL.h"
#include "SDL_TTF.h"

#include <string>
#include "ImageManager.h"
#include "InputManager.h"

#include "SDL_GUI.h"

// The attributes of the screen
const int SCREEN_WIDTH	= 1280;
const int SCREEN_HEIGHT	= 720;
const int SCREEN_BPP	= 32;

// The images
SDL_Surface* screen = NULL;

// Functions to test the button events
void ChangeName(string txt);
void MouseOver();
void MouseOut();
void MouseDown();
void MouseUp();
void MouseClick();

TTF_Font *font = NULL;

int main(int argc, char* args[])
{
	ImageManager imageManager = ImageManager();
	InputManager inputManager = InputManager(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP);
	SDL_GUI::GUI_Element_Manager elementManager =  SDL_GUI::GUI_Element_Manager();

	// Make sure that the program waits for quit
	bool quit = false;

	// Start SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
		return 1;

	// Set up screen
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE | SDL_RESIZABLE);

	if (screen == NULL)
		return 1;

	if(TTF_Init() == -1)
		return 1;

	SDL_WM_SetCaption("SDL_GUI", NULL);

	// Open the font
	font = TTF_OpenFont("Fonts/PTC55F.ttf", 18);

	if (font == NULL)
		return 1;

	// Load the images
	if (imageManager.AddImage("hello", "BeardedManStudios.bmp"))
	{
		Image* tmp = imageManager.GetBaseImage("hello");
		tmp->rect.x = (inputManager.GetScreenWidth() * 0.5f) - (tmp->image->w * 0.5f);
		tmp->rect.y = (inputManager.GetScreenHeight() * 0.5f) - (tmp->image->h * 0.5f);
	}

	// Create a button and its events
	SDL_GUI::Button button = SDL_GUI::Button(screen, &inputManager, font, "Button!");
	button.rect = Rectangle(15, 15, 150, 50);
	button.SetMouseOver(&MouseOver);
	button.SetMouseOut(&MouseOut);
	button.SetMouseDown(&MouseDown);
	button.SetMouseUp(&MouseUp);
	button.SetOnClick(&MouseClick);

	elementManager.AddElement(&button);

	SDL_GUI::TextBlock textBlock = SDL_GUI::TextBlock(screen, &inputManager, font, "The quick brown fox jumps over the lazy dog");
	textBlock.rect = Rectangle(300, 25, 15, 15);

	elementManager.AddElement(&textBlock);

	while (!quit)
	{
		inputManager.Update(screen, &quit);

		elementManager.UpdateElements();

		SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));

		Image* tmpHello = imageManager.GetBaseImage("hello");
		tmpHello->rect.x = (inputManager.GetScreenWidth() * 0.5f) - (tmpHello->image->w * 0.5f);
		tmpHello->rect.y = (inputManager.GetScreenHeight() * 0.5f) - (tmpHello->image->h * 0.5f);

		imageManager.DrawAllImages(screen);
		
		elementManager.DrawElements(screen);

		if (SDL_Flip(screen) == -1)
			return 1;
	}

	// Quit TTF
	TTF_CloseFont(font);
	TTF_Quit();

	// Quit SDL
	SDL_Quit();

	return 0;
}

// These are tests to make sure that the button events are working.
void ChangeName(string txt) { SDL_WM_SetCaption((string("SDL_GUI: ") + txt).c_str(), NULL); }
void MouseOver() { ChangeName("Mouse Over"); }
void MouseOut() { ChangeName("Mouse Out"); }
void MouseDown() { ChangeName("Mouse Down"); }
void MouseUp() { ChangeName("Mouse Up"); }
void MouseClick() { ChangeName("Mouse Click"); }