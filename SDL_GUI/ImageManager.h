/////////////////////////////////////////////////
//                                             //
// Brent Farris, Bearded Man Studios, Inc.     //
// https://www.beardedmangames.com/            //
//                                             //
/////////////////////////////////////////////////
//                                             //
// This input manager is used to keep track    //
// of the input events and should be expanded  //
// to support any range of inputs.             //
//                                             //
/////////////////////////////////////////////////

#ifndef IMAGE_MANAGER_H
#define IMAGE_MANAGER_H
#endif

#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "Rectangle.h"
#include <map>
#include <string>

using namespace std;

class Image
{
	public:
		Image() { }

		Rectangle rect;
		SDL_Surface* image;
};

class ImageManager
{
	private:
		map<string, Image> images;			// A key value map to get images by key name

	public:
		ImageManager();
		
		bool AddImage(string imageKey, string imagePath);
		Image* GetBaseImage(string imageKey) { return &images[imageKey]; }
		SDL_Surface* GetImage(string imageKey) { return images[imageKey].image; }
		SDL_Surface* LoadImage(std::string filename);
		void DrawImage(string imageKey, SDL_Surface* destination);

		// Free the images from the map
		~ImageManager()
		{
			for (map<string, Image>::iterator image = images.begin(); image != images.end(); ++image)
				SDL_FreeSurface((*image).second.image);
		}
};