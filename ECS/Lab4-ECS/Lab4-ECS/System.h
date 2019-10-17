#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include "Entity.h"
class System
{
public:
	virtual void addEntity(Entity t_entity) { entities.push_back(t_entity); }
	virtual void update() { std::cout << "System Update" << std::endl; }
private:
	std::vector<Entity> entities;
};

