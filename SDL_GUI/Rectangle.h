/////////////////////////////////////////////////
//                                             //
// Brent Farris, Bearded Man Studios, Inc.     //
// https://www.beardedmangames.com/            //
//                                             //
/////////////////////////////////////////////////
//                                             //
// This is the main rectangle class for the    //
// library.  It should have all the needed     //
// functionality to keep track of position,    //
// collision, contains, etc.                   //
//                                             //
/////////////////////////////////////////////////

#ifndef IMAGE_MANAGER_H
#define IMAGE_MANAGER_H
#endif

#pragma once

#include "SDL.h"
#include "Vector2.h"

class Rectangle
{
	public:
		int x;											// The x position of the rectangle
		int y;											// The y position of the rectangle
		int width;										// The width of the rectangle
		int height;										// The height of the rectangle
		
		Rectangle();									// Initialize the rectangle to have 0 in the x, y, widht, and height
		Rectangle(int px, int py, int pw, int ph);		// Initialize x to px, y to py, width to pw and height to ph
		
		bool Contains(int x, int y);					// Checks to see if the passed in x and y are within the rectangle
		bool Contains(Vector2 position);				// Breaks the vector2 down to x and y and passes it into the other Contains function
		bool Intersects(Rectangle inRect);				// Checks to see if another rectangle is intersecting this one
		SDL_Rect SDL_Format();							// Turns this rect into a SDL format rect
		void Center(Rectangle inRect);					// Center this rectangle on another rectangle

		bool operator==(const Rectangle& other);
		bool operator!=(const Rectangle& other);

		~Rectangle()
		{

		}
};