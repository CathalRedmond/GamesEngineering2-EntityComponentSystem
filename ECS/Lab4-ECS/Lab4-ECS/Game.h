#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Component.h"
#include "HealthComponent.h"
#include "InputComponent.h"
#include "PositionComponent.h"
#include "AISystem.h"
#include "ControlSystem.h"
#include "RenderSystem.h"

class Game
{
public:
	Game();
	~Game();

	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();

	sf::RenderWindow m_window;
	bool m_exitGame;

	Entity m_player;
	Entity m_alien;
	Entity m_dog;
	Entity m_cat;

	HealthComponent m_healthComponent;
	PositionComponent m_positionComponent;
	InputComponent m_inputComponent;

	AISystem m_aiSystem;
	ControlSystem m_controlSystem;
	RenderSystem m_renderSystem;
};


