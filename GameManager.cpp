#include "GameManager.h"

GameManager::GameManager(string title, int height, int width, int scorePicks) {
	this->title = title;
	this->height = height;
	this->width = width;
	player = Player();
	for (size_t i = 0; i < scorePicks/3; i++)
	{
		AddLife pick = AddLife();
		Vector2 position = randomPosition(pick.getWidth(), pick.getHeight());
		pick.setPosition(position.X,position.Y);
		entityPositions[position] = &pick;
		pickables.push_back(&pick);
	}
}

GameManager::~GameManager() {

}

void GameManager::Game() {
	draw();
	while (true) {
		player.move(getPlayerInput());
		draw();
	}
}

Vector2 GameManager::randomPosition(int entityWidth, int entityHeight) {
	int positionX = (rand() % (width - (entityWidth * 2))) + 2;
	int positionY = (rand() % (height - (entityHeight * 2))) + 2;

	Vector2 position{};
	position.X = positionX;
	position.Y = positionY;

	Vector2 posiblePosition{};
	
	bool isOccupied = false;
	for (int i = 0; i < entityWidth; i++) {
		for (int j = 0; j < entityHeight; j++) {
			posiblePosition = position;
			posiblePosition.X += i;
			posiblePosition.Y += j;

			auto positionsIt = entityPositions.find(posiblePosition);
			if (positionsIt != entityPositions.end()) {
				isOccupied = true;
				break;
			}
		}
	}

	return isOccupied
		? randomPosition(entityWidth, entityHeight)
		: position;
}

void GameManager::draw() {
	system("cls");
	drawFrame(1, 1, width, height);
	player.draw();

	for (const auto& entity : pickables)
		entity->draw();	
}

Vector2 GameManager::getPlayerInput(){
	char playerInput;
	bool isValidInput = false;
	Vector2 nextPosition{};

	while (!isValidInput) {
		playerInput = _getch();
	
		switch (playerInput) {
		case 'w':
		case 'W':
			nextPosition.X = 0;
			nextPosition.Y = -1;
			isValidInput = true;
			break;
		case 's':
		case 'S':
			nextPosition.X = 0;
			nextPosition.Y = 1;
			isValidInput = true;
			break;
		case 'a':
		case 'A':
			nextPosition.X = -1;
			nextPosition.Y = 0;
			isValidInput = true;
			break;
		case 'd':
		case 'D':
			nextPosition.X = 1;
			nextPosition.Y = 0;
			isValidInput = true;
			break;
		default:
			break;
		}
	}

	Vector2 position = player.getPosition();
	if (position.X + player.getWidth() + nextPosition.X >= width ||
		position.X + nextPosition.X <= 1)
		nextPosition.X = 0;

	if (position.Y + player.getHeight() + nextPosition.Y >= height ||
		position.Y + nextPosition.Y <= 1)
		nextPosition.Y = 0;
	
	return nextPosition;
}