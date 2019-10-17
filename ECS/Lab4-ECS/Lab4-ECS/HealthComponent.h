#pragma once
#include "Component.h"
class HealthComponent :
	public Component
{
public:
	HealthComponent() : m_health(100) {}
	int getHealth() { return m_health; }
	void setHealth(int t_health) { this->m_health = t_health; }
private:
	int m_health;
};

