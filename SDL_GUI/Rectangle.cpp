#include "Rectangle.h"

Rectangle::Rectangle()
{
	x = 0;
	y = 0;
	width = 0;
	height = 0;
}

Rectangle::Rectangle(int px, int py, int pw, int ph)
{
	x = px;
	y = py;
	width = pw;
	height = ph;
}

bool Rectangle::Contains(int x, int y)
{
	if (x >= this->x && x <= this->x + this->width && y >= this->y && y <= this->y + this->height)
		return true;
	else
		return false;
}

bool Rectangle::Contains(Vector2 position)
{
	return Contains(position.x, position.y);
}

bool Rectangle::Intersects(Rectangle inRect)
{
	if (this->Contains(inRect.x, inRect.y) || this->Contains(inRect.x + inRect.width, inRect.y) ||
		this->Contains(inRect.x, inRect.y + inRect.height) || this->Contains(inRect.x + inRect.width, inRect.y + inRect.height))
	{
		return true;
	}
	else if (inRect.Contains(this->x, this->y) || inRect.Contains(this->x + this->width, this->y) ||
		inRect.Contains(this->x, this->y + this->height) || inRect.Contains(this->x + this->width, this->y + this->height))
	{
		return true;
	}
		
	return false;
}

SDL_Rect Rectangle::SDL_Format()
{
	SDL_Rect tmp;
	tmp.x = x;
	tmp.y = y;
	tmp.w = width;
	tmp.h = height;

	return tmp;
}