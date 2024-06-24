#pragma once
#include "Entity.h"
#include "Player.h"

class Pickable :public Entity {
protected:
	void virtual interact(Player* player);
public:
	Pickable();
	virtual ~Pickable();
	void draw() override;
	bool collisionCheck(Entity* entity) override;
};