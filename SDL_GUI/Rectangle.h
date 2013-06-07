#ifndef IMAGE_MANAGER_H
#define IMAGE_MANAGER_H
#endif

#pragma once

#include "SDL.h"

class Rectangle
{
	public:
		int x;
		int y;
		int width;
		int height;

		SDL_Rect sdlRect;
		
		Rectangle();
		Rectangle(int px, int py, int pw, int ph);
		
		bool Contains(int x, int y);
		bool Intersects(Rectangle inRect);
		SDL_Rect SDL_Format();

		~Rectangle()
		{

		}
};