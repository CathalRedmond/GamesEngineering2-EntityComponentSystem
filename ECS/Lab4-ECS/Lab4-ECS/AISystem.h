#pragma once
#include "System.h"
#include "PositionComponent.h"
#include "ScreenSize.h"
class AISystem : public System
{
public:
	virtual void addEntity(Entity t_entity)
	{
		m_entities.push_back(t_entity);
	}
	virtual void update()
	{
		for (int index = 0; index < m_entities.size(); index++)
		{
			std::vector<Component*> components = m_entities[index].getComponents();
			PositionComponent* position = NULL;
			for (int componentIndex = 0; componentIndex < components.size(); componentIndex++)
			{
				if (typeid(*components[componentIndex]) == typeid(PositionComponent))
				{
					position = dynamic_cast<PositionComponent*>(components[componentIndex]);
				}
				if (position != NULL)
				{
					Vector2 currentPosition = position->getPosition();

					currentPosition = currentPosition + Vector2(5, -3);
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
	}
private:
	std::vector<Entity> m_entities;
};

