#include "GUI_Element.h"

SDL_GUI::GUI_Element::GUI_Element()
{

}

SDL_GUI::GUI_Element::GUI_Element(SDL_Surface* screen, InputManager* passedInputManager)
{
	mouseIsOver		= false;
	performingClick	= false;

	backgroundColor = SDL_MapRGB(screen->format, 0, 0, 0);

	onMouseUp		= NULL;
	onMouseDown		= NULL;
	onMouseOver		= NULL;
	onMouseOut		= NULL;
	onClick			= NULL;

	inputManager = passedInputManager;
}

void SDL_GUI::GUI_Element::Update()
{
	bool inRect = rect.Contains(inputManager->GetMousePosition());

	if (!mouseIsOver && inRect)
	{
		mouseIsOver = true;

		if (onMouseOver != NULL)
			onMouseOver();
	}
	else if (mouseIsOver && !inRect)
	{
		mouseIsOver = false;
		performingClick = false;

		if (onMouseOut != NULL)
			onMouseOut();
	}

	if (inRect)
	{
		if (inputManager->MouseDown())
		{
			performingClick = true;

			if (onMouseDown != NULL)
				onMouseDown();
		}
		else if (inputManager->MouseUp())
		{
			if (onMouseUp != NULL)
				onMouseUp();

			if (performingClick)
			{
				performingClick = false;

				if (onClick != NULL)
					onClick();
			}
		}
	}
}

void SDL_GUI::GUI_Element::Draw(SDL_Surface* screen)
{
	
}