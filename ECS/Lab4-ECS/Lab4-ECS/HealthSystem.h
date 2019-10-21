#pragma once
#include "System.h"
#include "HealthComponent.h"
#include "EntityType.h"
#include <string>
class HealthSystem :
	public System
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
			HealthComponent* health = NULL;
			for (int componentIndex = 0; componentIndex < components.size(); componentIndex++)
			{
				if (typeid(*components[componentIndex]) == typeid(HealthComponent))
				{
					health = dynamic_cast<HealthComponent*>(components[componentIndex]);
				}
			}
			if (health != NULL)
			{
				if (health->getHealth() > 0)
				{
					health->setHealth(health->getHealth() - 1);
				}
				switch (m_entities[index].getId())
				{
				case ENTITY_TYPE::PLAYER:
					std::cout << "Player's ";
					break;
				case ENTITY_TYPE::ALIEN:
					std::cout << "Alien's ";
					break;
				case ENTITY_TYPE::DOG:
					std::cout << "Dog's ";
					break;
				case ENTITY_TYPE::CAT:
					std::cout << "Cat's ";
					break;
				default:
					break;
				}
				std::cout << "Health: " + std::to_string(health->getHealth()) << std::endl;
 			}
		}
	}
private:
	std::vector<Entity> m_entities;
};

