#pragma once
#include "Entity.h"

class Character : public Entity {
private:

public:
	Character();
	~Character();
	void move(Vector2 input);
};