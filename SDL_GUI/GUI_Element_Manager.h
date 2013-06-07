#ifndef GUI_ELEMENT_MANAGER_H
#define GUI_ELEMENT_MANAGER_H
#endif

#pragma once

#include "GUI_Element.h"
#include <vector>

namespace SDL_GUI
{
	class GUI_Element_Manager
	{
		public:
			vector<GUI_Element*> elements;

			GUI_Element_Manager();

			void AddElement(GUI_Element* element);
			void UpdateElements();
			void DrawElements(SDL_Surface* screen);

			~GUI_Element_Manager() { }
	};
}