#include "ImageManager.h"

ImageManager::ImageManager()
{

}

bool ImageManager::AddImage(string imageKey, string imagePath)
{
	images[imageKey].image = LoadImage(imagePath);

	if (images[imageKey].image != NULL)
		return true;

	return false;
}

SDL_Surface* ImageManager::LoadImage(string filename)
{
	// Temporary storage for the image that's loaded
	SDL_Surface* loadedImage = NULL;

	//The optimized image that will be used
	SDL_Surface* optimizedImage = NULL;

	// Load image
	loadedImage = IMG_Load(filename.c_str());

	//If nothing went wrong in loading the image
	if (loadedImage != NULL)
	{
		// Create an optimized image
		optimizedImage = SDL_DisplayFormat(loadedImage);

		// Free the old image
		SDL_FreeSurface(loadedImage);

		if (optimizedImage != NULL)
		{
			// Map the color key
			Uint32 colorKey = SDL_MapRGB(optimizedImage->format, 0, 0xFF, 0xFF);

			// Set all pixels of color R 0, G 0xFF, B 0xFF to be transparent
			SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, colorKey);
		}
	}

	return optimizedImage;
}

void ImageManager::DrawImage(string imageKey, SDL_Surface* destination)
{
	// Blit the surface
	SDL_BlitSurface(images[imageKey].image, NULL, destination, &images[imageKey].rect.SDL_Format());
}