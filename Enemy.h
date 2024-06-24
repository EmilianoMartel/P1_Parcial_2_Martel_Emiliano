#pragma once
#include "Player.h"

class Enemy :public Character {
public:
	Enemy();
	~Enemy();
	bool collisionCheck(Entity* entity) override;
};