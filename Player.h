#pragma once
#include "Character.h"

class Player : public Character {
private:
	int maxMove;
	int maxLife;
	int actualLife;
public:
	Player(int maxMove = 10, int maxLife = 3);
	~Player();
};