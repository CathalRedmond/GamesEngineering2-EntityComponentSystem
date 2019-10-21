#pragma once
#include <SDL.h>
#include "Entity.h"
#include "Component.h"
#include "HealthComponent.h"
#include "InputComponent.h"
#include "PositionComponent.h"
#include "AISystem.h"
#include "ControlSystem.h"
#include "RenderSystem.h"
#include "HealthSystem.h"
#include "EntityType.h"

class Game
{
public:
	Game();
	~Game();

	void run();

private:

	void processEvents();
	void update();
	void render();
	void cleanup();
	void setupECS();
	void setUpPlayer();
	void setUpAlien();
	void setUpDog();
	void setUpCat();

	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	
	bool m_isRunning;

	Entity m_player;
	Entity m_alien;
	Entity m_dog;
	Entity m_cat;

	Component* m_healthComponent;
	Component* m_positionComponent;
	Component* m_inputComponent;

	AISystem m_aiSystem;
	ControlSystem m_controlSystem;
	RenderSystem m_renderSystem;
	HealthSystem m_healthSystem;

	SDL_Keycode currentButtonPressed;
};


