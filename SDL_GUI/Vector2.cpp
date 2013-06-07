#include "Vector2.h"
#include <cmath>

Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(int xy)
{
	x = xy;
	y = xy;
}

Vector2::Vector2(int px, int py)
{
	x = px;
	y = py;
}

Vector2 Vector2::GetNormalized()
{
	Vector2 tmp = Vector2(this->x, this->y);
		
	float mag = std::sqrt((tmp.x * tmp.x) + (tmp.y * tmp.y));
	tmp.x = tmp.x / mag;
	tmp.y = tmp.y / mag;
		
	return tmp;
}

void Vector2::Normalize()
{
	float mag = std::sqrt((x * x) + (y * y));
	x = x / mag;
	y = y / mag;
}

Vector2 Vector2::operator+(const Vector2&  other) { return Vector2(this->x + other.x, this->y + other.y); }
Vector2 Vector2::operator-(const Vector2&  other) { return Vector2(this->x - other.x, this->y - other.y); }
Vector2 Vector2::operator*(const Vector2&  other) { return Vector2(this->x * other.x, this->y * other.y); }
Vector2 Vector2::operator/(const Vector2&  other) { return Vector2(this->x / other.x, this->y / other.y); }