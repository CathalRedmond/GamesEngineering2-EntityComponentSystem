#pragma once
#include "Component.h"
#include "Vector2.h"
class PositionComponent :
	public Component
{
public:
	PositionComponent() : m_position(0,0) {}
	Vector2 getPosition() { return m_position; }
	void setPosition(Vector2 position) 
	{ 
		this->m_position = position;
	}
private:
	Vector2 m_position;
};

