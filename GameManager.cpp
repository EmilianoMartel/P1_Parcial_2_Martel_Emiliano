#include "GameManager.h"

GameManager::GameManager(string title, int height, int width, int scorePicks, int enemyCount) {
	this->title = title;
	this->height = height;
	this->width = width;
	this->entityPicksSize = scorePicks;
	enemySize = enemyCount;
	player = Player(20,3);
	createAndAddEntities<AddLife>(scorePicks / 3);
	createAndAddEntities<AddScore>(scorePicks / 3);
	createAndAddEntities<MultiplyScore>(scorePicks / 3);
	createAndAddEntities<Enemy>(enemyCount);
}

GameManager::~GameManager() {

}

void GameManager::Game() {
	menu();
	player.move(getPlayerInput());
}

Vector2 GameManager::randomPosition(int entityWidth, int entityHeight) {
	int positionX;
	int positionY;

	if (entityWidth == 0)
		positionX = (rand() % (width - 1)) + 2;
	else
		positionX = (rand() % (width - (entityWidth * 2))) + 2;

	if (entityHeight == 0)
		positionY = (rand() % (height - 1)) + 2;
	else
		positionY = (rand() % (height - (entityHeight * 2))) + 2;

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
	setForegroundColor(Color::WHITE);
	drawFrame(1, 1, width, height);
	player.draw();

	for (const auto& entity : entities)
		entity->draw();

	printPlayerStates();
}

void GameManager::printPlayerStates() {
	setForegroundColor(Color::WHITE);
	goToCoordinates(1, height + 1);
	cout << "Life: " << player.getActualLife() << endl;
	cout << "Actual moves: " << player.getActualMove() << endl;
	cout << "Score: " << player.getScore();
}

Vector2 GameManager::getPlayerInput() {
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

template <typename T>
void GameManager::createAndAddEntities(size_t count) {
	for (size_t i = 0; i < count; i++) {
		T* pick = new T();
		Vector2 position = randomPosition(pick->getWidth(), pick->getHeight());
		pick->setPosition(position.X, position.Y);
		entityPositions[position] = pick;
		entities.push_back(pick);
	}
}

void GameManager::finalScene() {
	int input;
	bool exit = false;
	do
	{
		int indexer;
		string lines;
		stringstream ss;

		if (player.getIsLive())
			lines = "YOU WIN\n";
		else
			lines = "YOU LOOSE\n";
		ss << "Your score is " << player.getScore() << "\n";
		lines += ss.str();
		lines += "1 - Replay\n2 - Back to menu\n3 - Exit";
		printData(lines, 41, &indexer);
		goToCoordinates(41, indexer);
		input = questionWithIntReturn("Select a option: ", 41, indexer);
		resetGame();
		switch (input)
		{
		case 1:
			gameLoop();
			break;
		case 2:
			menu();
			break;
		case 3:
			exit = questionWithBoolReturn("Are you sure? Y/N", 40, 1);
			if (exit)
				ExitProcess(0);

			input = 0;
			break;
		default:
			cout << "Wrong input." << endl;
			miliSleep(500);
			break;
		}
	} while (input != 3);
}

void GameManager::menu() {
	int input;
	bool exit = false;
	do
	{
		int indexer;
		string lines = "1 - Play\n2 - Instructions\n3 - Exit";
		printData(lines, 41, &indexer);
		goToCoordinates(41, indexer);
		input = questionWithIntReturn("Select a option: ", 41, indexer);
		switch (input)
		{
		case 1:
			gameLoop();
			break;
		case 2:
			instructions();
			break;
		case 3:
			exit = questionWithBoolReturn("Are you sure? Y/N", 40, indexer);
			if (exit)
				ExitProcess(0);

			input = 0;
			break;
		default:
			cout << "Wrong input." << endl;
			miliSleep(500);
			break;
		}
	} while (input != 3);
}

void GameManager::instructions() {
	system("cls");
	string lines = R"(The goal is to get the maximum amount of points before running out of moves.
You can pick the boxes for that
          - S -
Increases your score.
          - M - 
Multiply your score.
          - L - 
Get you 1 life more.
		  - Enemies -
They can get you 1 life less and they put you at the beginning again)";
	int indexer;
	printData(lines, 24, &indexer);
	indexer++;
	goToCoordinates(24, indexer);
	cout << "Press any key to continue..." << endl;
	_getch();
	system("cls");
}

void GameManager::gameLoop() {
	isPlaying = true;

	while (isPlaying) {
		draw();

		player.move(getPlayerInput());
		for (size_t i = 0; i < entities.size(); i++)
		{
			if (player.collisionCheck(entities[i]))
				entities.erase(remove(entities.begin(), entities.end(), entities[i]), entities.end());
		}

		isPlaying = player.getIsLive() && player.haveMoves();
	}

	finalScene();
}

void GameManager::resetGame() {
	entityPositions.clear();
	for (auto it = entities.rbegin(); it != entities.rend(); ++it) {
		delete* it;
	}
	entities.clear();
	player.reset();
	createAndAddEntities<AddLife>(entityPicksSize / 3);
	createAndAddEntities<AddScore>(entityPicksSize / 3);
	createAndAddEntities<MultiplyScore>(entityPicksSize / 3);
	createAndAddEntities<Enemy>(enemySize);
}