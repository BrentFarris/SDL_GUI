/////////////////////////////////////////////////
//                                             //
// Brent Farris, Bearded Man Studios, Inc.     //
// https://www.beardedmangames.com/            //
//                                             //
/////////////////////////////////////////////////
//                                             //
// This is a simple vector class that holds an //
// x and y. It's common purpose is to keep     //
// track of screen coordinates.                //
//                                             //
/////////////////////////////////////////////////

#ifndef VECTOR2_H
#define VECTOR2_H
#endif

#pragma once

class Vector2
{
	public:
		int x;						// The x coordinate
		int y;						// The y coordinate

		Vector2();					// Construct the vector and set x and y to 0
		Vector2(int xy);			// Construct the vector and set x and y to xy
		Vector2(int px, int py);	// Construct the vector and set x to pX and y to pY

		Vector2 GetNormalized();	// Return a vector that is normalized
		void Normalize();			// Normalize this vector

		Vector2 operator+(const Vector2& other);	// Add this x to the incoming x and add this y to the incoming y
		Vector2 operator-(const Vector2& other);	// Subtract this x to the incoming x and subtract this y to the incoming y
		Vector2 operator*(const Vector2& other);	// Multiply this x to the incoming x and multiply this y to the incoming y
		Vector2 operator/(const Vector2& other);	// Divide this x to the incoming x and divide this y to the incoming y

		~Vector2() { }
};