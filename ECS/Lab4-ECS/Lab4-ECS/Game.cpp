#include "Game.h"
#include <iostream>

Game::Game() 
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "Error Loading SDL" << std::endl;
		m_isRunning = false;
	}
	else
	{
		m_window = SDL_CreateWindow("ECS", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, NULL);
		if (!m_window)
		{
			std::cout << "Error Loading SDL Window" << std::endl;
		}
		m_renderer = SDL_CreateRenderer(m_window, -1, 0);
		if (!m_renderer)
		{
			std::cout << "Error Loading Renderer" << std::endl;
		}
		SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
		m_isRunning = true;
		currentButtonPressed = NULL;
		m_player.setId(ENTITY_TYPE::PLAYER);
		m_alien.setId(ENTITY_TYPE::ALIEN);
		m_dog.setId(ENTITY_TYPE::DOG);
		m_cat.setId(ENTITY_TYPE::CAT);
		setupECS();
	}
}

Game::~Game()
{
	cleanup();
}

void Game::run()
{	
	while (m_isRunning)
	{
		processEvents();
		update();
		render();
	}
}

void Game::processEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		m_isRunning = false;
		break;
	case SDL_KEYDOWN:
		currentButtonPressed = event.key.keysym.sym;
		break;
	case SDL_KEYUP:
		currentButtonPressed = NULL;
		break;
	default:
		break;
	}
}

void Game::update()
{
	m_healthSystem.update();
	m_renderSystem.update(m_renderer);
	m_controlSystem.update(currentButtonPressed);
	m_aiSystem.update();
}

void Game::render()
{

}

void Game::cleanup()
{
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	SDL_QUIT;
}

void Game::setupECS()
{
	setUpPlayer();
	setUpAlien();
	setUpDog();
	setUpCat();

	m_healthSystem.addEntity(m_player);
	m_healthSystem.addEntity(m_alien);
	m_healthSystem.addEntity(m_dog);
	
	m_aiSystem.addEntity(m_alien);
	m_aiSystem.addEntity(m_dog);
	m_aiSystem.addEntity(m_cat);

	m_renderSystem.addEntity(m_player);
	m_renderSystem.addEntity(m_alien);
	m_renderSystem.addEntity(m_dog);
	m_renderSystem.addEntity(m_cat);

	m_controlSystem.addEntity(m_player);
}

void Game::setUpPlayer()
{
	Component* playerHealthComponent = new HealthComponent();
	Component* playerPositionComponent = new PositionComponent();
	Component* playerInputComponent = new InputComponent();

	m_player.addComponent(playerHealthComponent);
	m_player.addComponent(playerPositionComponent);
	m_player.addComponent(playerInputComponent);
}

void Game::setUpAlien()
{
	Component* alienHealthComponent = new HealthComponent();
	Component* alienPositionComponent = new PositionComponent();

	m_alien.addComponent(alienHealthComponent);
	m_alien.addComponent(alienPositionComponent);
}

void Game::setUpDog()
{
	Component* dogHealthComponent = new HealthComponent();
	Component* dogPositionComponent = new PositionComponent();

	m_dog.addComponent(dogHealthComponent);
	m_dog.addComponent(dogPositionComponent);
}

void Game::setUpCat()
{
	Component* catPositionComponent = new PositionComponent();
	m_cat.addComponent(catPositionComponent);
}
