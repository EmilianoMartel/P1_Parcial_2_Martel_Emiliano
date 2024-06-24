#pragma once
#include <map>
#include "Player.h"
#include "Pickable.h"
#include "AddLife.h"
#include "MultiplyScore.h"
#include "AddScore.h"
#include "GeneralFunctions.h"
#include "Enemy.h"

class GameManager {
private:
	string title;
	int height;
	int width;
	int entityPicksSize;
	int enemySize;
	Player player;
	vector<Entity*> entities;
	map<Vector2, Entity*> entityPositions;
	bool isWin;
	bool isPlaying;
	
	Vector2 getPlayerInput();
	Vector2 randomPosition(int entityWidth, int entityHeight);
	void draw();
	void printPlayerStates();
	void finalScene();
	void menu();
	void gameLoop();
	void instructions();
	template <typename T>
	void createAndAddEntities(size_t count);
	void resetGame();
public:
	GameManager(string title, int height, int width, int scorePicks, int enemyCount);
	~GameManager();
	void Game();
};