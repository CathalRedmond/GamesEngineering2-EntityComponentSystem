#pragma once
#include "System.h"
class AISystem : public System
{
public:
	virtual void addEntity(Entity t_entity)
	{
		m_entities.push_back(t_entity);
	}
	virtual void update()
	{
		std::cout << "AI  System Update" << std::endl;
		for each (Entity entity in m_entities)
		{
			Components components = entity.getComponents();
			if (std::find(components.begin(), components.end(), InputComponent()) != components.end())
			{

			}
		}
	}
private:
	Entities m_entities;
};

