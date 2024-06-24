#pragma once
#include "Character.h"

class Player : public Character {
private:
	int maxMove;
	int actualMove;
	int maxLife;
	int actualLife;
	int score;
	bool isLive;
public:
	Player(int maxMove = 10, int maxLife = 3);
	~Player();
	int getActualLife();
	int getActualMove();
	void changeLife(int changer);
	void move(Vector2 input) override;
	bool collisionCheck(Entity* entity) override;
	bool getIsLive();
	void sumScore(int sum);
	void multiplyScore(int multiplier);
	int getScore();
	bool haveMoves();
	void reset();
};