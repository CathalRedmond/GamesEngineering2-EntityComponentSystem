#pragma once
#include "System.h"
#include "InputComponent.h"
#include "PositionComponent.h"
#include "ScreenSize.h"
#include <string>

class ControlSystem : public System
{
public:
	virtual void addEntity(Entity t_entity)
	{
		m_entities.push_back(t_entity);
	}
	virtual void update(SDL_Keycode t_buttonPressed)
	{
		for (int index = 0; index < m_entities.size(); index++)
		{
			std::vector<Component*> components = m_entities[index].getComponents();
			InputComponent* input = NULL;
			PositionComponent* position = NULL;
			for (int componentIndex = 0; componentIndex < components.size(); componentIndex++)
			{
				if (typeid(*components[componentIndex]) == typeid(InputComponent))
				{
					input = dynamic_cast<InputComponent*>(components[componentIndex]);
				}
				else if (typeid(*components[componentIndex]) == typeid(PositionComponent))
				{
					position = dynamic_cast<PositionComponent*>(components[componentIndex]);
				}
			}
			if (input != NULL && position != NULL)
			{
				input->setButtonPressed(t_buttonPressed);
				Vector2 currentPosition = position->getPosition();
				if (input->getButtonPressed() == SDLK_UP || input->getButtonPressed() == SDLK_w)
				{
					currentPosition = currentPosition + Vector2(0, -1);				
				}
				else if (input->getButtonPressed() == SDLK_DOWN || input->getButtonPressed() == SDLK_s)
				{
					currentPosition = currentPosition + Vector2(0, 1);				
				}
				else if (input->getButtonPressed() == SDLK_LEFT || input->getButtonPressed() == SDLK_a)
				{
					currentPosition = currentPosition + Vector2(-1, 0);				
				}
				else if (input->getButtonPressed() == SDLK_RIGHT || input->getButtonPressed() == SDLK_d)
				{
					currentPosition = currentPosition + Vector2(1, 0);				
				}
				// boundary checks
				if (currentPosition.x() > SCREEN_SIZE::WIDTH)
				{
					currentPosition = Vector2(0, currentPosition.y());
				}
				else if (currentPosition.x() < 0)
				{
					currentPosition = Vector2(SCREEN_SIZE::WIDTH, currentPosition.y());
				}
				if (currentPosition.y() > SCREEN_SIZE::HEIGHT)
				{
					currentPosition = Vector2(currentPosition.x(), 0);
				}
				else if (currentPosition.y() < 0)
				{
					currentPosition = Vector2(currentPosition.x(), SCREEN_SIZE::HEIGHT);
				}
				position->setPosition(currentPosition);
			}
		}
	}
private:
	std::vector<Entity> m_entities;
};

