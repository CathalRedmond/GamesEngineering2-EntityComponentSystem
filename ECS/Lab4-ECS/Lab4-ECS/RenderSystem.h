#pragma once
#include <SDL_image.h>
#include "System.h"
#include "PositionComponent.h"
#include "EntityType.h"
class RenderSystem : public System
{
public:
	virtual void addEntity(Entity t_entity)
	{
		m_entities.push_back(t_entity);
	}
	virtual void update(SDL_Renderer* t_renderer)
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
					switch (m_entities[index].getId())
					{
					case ENTITY_TYPE::PLAYER:
						m_texture = IMG_LoadTexture(t_renderer, "./ASSETS/player.png");
						break;
					case ENTITY_TYPE::ALIEN:
						m_texture = IMG_LoadTexture(t_renderer, "./ASSETS/alien.png");
						break;
					case ENTITY_TYPE::DOG:
						m_texture = IMG_LoadTexture(t_renderer, "./ASSETS/dog.png");
						break;
					case ENTITY_TYPE::CAT:
						m_texture = IMG_LoadTexture(t_renderer, "./ASSETS/cat.png");
						break;
					default:
						break;
					}
					if (!m_texture)
					{
						std::cout << "Error Loading Texture" << std::endl;
					}
					destRect.x = position->getPosition().x();
					destRect.y = position->getPosition().y();
					destRect.w = 200;
					destRect.h = 200;
				}
				SDL_RenderClear(t_renderer);
				SDL_RenderCopy(t_renderer, m_texture, NULL, &destRect);
				SDL_RenderPresent(t_renderer);
			}
		}
	}
private:
	std::vector<Entity> m_entities;
	SDL_Texture* m_texture;
	SDL_Rect destRect;

};

