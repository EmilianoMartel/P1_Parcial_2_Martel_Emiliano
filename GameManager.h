#pragma once
#include <map>
#include "Player.h"
#include "Pickable.h"
#include "AddLife.h"

class GameManager {
private:
	string title;
	int height;
	int width;
	Player player;
	vector<Pickable*> pickables;
	map<Vector2, Entity*> entityPositions;
	Vector2 getPlayerInput();
	Vector2 randomPosition(int entityWidth, int entityHeight);
	void draw();
public:
	GameManager(string title, int height, int width, int scorePicks);
	~GameManager();
	void Game();
};