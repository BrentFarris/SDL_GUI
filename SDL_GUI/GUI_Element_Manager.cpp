#include "GUI_Element_Manager.h"

SDL_GUI::GUI_Element_Manager::GUI_Element_Manager()
{

}

void SDL_GUI::GUI_Element_Manager::AddElement(GUI_Element* element)
{
	elements.push_back(element);
}

void SDL_GUI::GUI_Element_Manager::UpdateElements()
{
	for (vector<GUI_Element*>::iterator elm = elements.begin(); elm != elements.end(); ++elm)
		(*elm)->Update();
}

void SDL_GUI::GUI_Element_Manager::DrawElements(SDL_Surface* screen)
{
	for (vector<GUI_Element*>::iterator elm = elements.begin(); elm != elements.end(); ++elm)
		(*elm)->Draw(screen);
}