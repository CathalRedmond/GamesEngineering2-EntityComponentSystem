#pragma once
#include "Component.h"
#include "Vector2.h"
#include <random>
class PositionComponent :
	public Component
{
public:
	PositionComponent():
		m_position{0,0}
	{
		std::mt19937 range;
		range.seed(std::random_device()());
		std::uniform_int<int> randomNumber(0, 400);
		m_position = Vector2(randomNumber(range), randomNumber(range));
	}
	Vector2 getPosition() { return m_position; }
	void setPosition(Vector2 position) 
	{ 
		this->m_position = position;
	}
private:
	Vector2 m_position;
};

