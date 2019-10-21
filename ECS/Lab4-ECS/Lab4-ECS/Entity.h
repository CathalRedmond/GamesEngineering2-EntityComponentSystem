#pragma once
#include "Component.h"
#include <vector>

class Entity
{
public:
	Entity() {};
	Entity(int t_id) : m_id{ t_id } {};
	void addComponent(Component* t_component) { m_components.push_back(t_component); }
	void remove(Component* t_component) {};
	std::vector<Component*> getComponents() { return m_components; }
	void setId(int t_id);
	int getId();
private:
	std::vector<Component*> m_components;
	int m_id;
};

