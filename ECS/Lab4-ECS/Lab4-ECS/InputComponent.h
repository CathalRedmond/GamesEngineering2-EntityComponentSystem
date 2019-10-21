#pragma once
#include "Component.h"
#include <SDL.h>
class InputComponent :
	public Component
{
public:
	InputComponent() {};
	SDL_Keycode getButtonPressed() { return m_buttonPressed; }
	void setButtonPressed(SDL_Keycode t_buttonPressed) 
	{
		this->m_buttonPressed = t_buttonPressed;
	}
private:
	SDL_Keycode m_buttonPressed;
};

