#pragma once
#include "Component.h"
#include <vector>

using Components = std::vector<Component>;
using Entities = std::vector<Entity>;

class Entity
{
	int m_id;
public:
	Entity() {};
	void addComponent(Component t_component) { m_components.push_back(t_component); }
	void remove(Component t_component) {};
	Components getComponents() { return m_components; }
private:
	Components m_components;
};

