#pragma once
#include "Entity.h"

class Pickable :public Entity {
protected:
	void virtual interact();
public:
	Pickable();
	~Pickable();
};