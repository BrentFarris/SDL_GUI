#include "SDL.h"
#include "SDL_image.h"
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

void MouseOver();
void MouseOut();
void MouseDown();
void MouseUp();
void MouseClick();

int main(int argc, char* args[])
{
	ImageManager imageManager = ImageManager();
	InputManager inputManager = InputManager(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP);

	// Make sure that the program waits for quit
	bool quit = false;

	// Start SDL
	if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
		return 1;

	// Set up screen
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE | SDL_RESIZABLE);

	if (screen == NULL)
		return 1;

	SDL_WM_SetCaption("Five", NULL);

	// Load the images
	if (imageManager.AddImage("hello", "BeardedManStudios.bmp"))
	{
		Image* tmpHello = imageManager.GetBaseImage("hello");
		tmpHello->rect.x = (inputManager.GetScreenWidth() * 0.5f) - (tmpHello->image->w * 0.5f);
		tmpHello->rect.y = (inputManager.GetScreenHeight() * 0.5f) - (tmpHello->image->h * 0.5f);
	}

	SDL_GUI::SDL_GUI_Button button = SDL_GUI::SDL_GUI_Button(screen, &inputManager, "Hello Danielle");
	button.rect = Rectangle(0, 0, 100, 100);
	button.SetMouseOver(&MouseOver);
	button.SetMouseOut(&MouseOut);
	button.SetMouseDown(&MouseDown);
	button.SetMouseUp(&MouseUp);
	button.SetOnClick(&MouseClick);

	while (!quit)
	{
		inputManager.Update(screen, &quit);

		button.Update();

		SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));

		Image* tmpHello = imageManager.GetBaseImage("hello");
		tmpHello->rect.x = (inputManager.GetScreenWidth() * 0.5f) - (tmpHello->image->w * 0.5f);
		tmpHello->rect.y = (inputManager.GetScreenHeight() * 0.5f) - (tmpHello->image->h * 0.5f);

		imageManager.DrawImage("hello", screen);
		
		button.Draw(screen);

		if (SDL_Flip(screen) == -1)
			return 1;
	}

	// Quit SDL
	SDL_Quit();

	return 0;
}

void MouseOver()
{
	SDL_WM_SetCaption("Five Mouse Over", NULL);
}

void MouseOut()
{
	SDL_WM_SetCaption("Five Mouse Out", NULL);
}

void MouseDown()
{
	SDL_WM_SetCaption("Five Mouse Down", NULL);
}

void MouseUp()
{
	SDL_WM_SetCaption("Five Mouse Up", NULL);
}

void MouseClick()
{
	SDL_WM_SetCaption("Five Mouse Click", NULL);
}