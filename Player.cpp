#include "Player.h"

Player::Player(int maxMove, int maxLife) {
	this->maxMove = maxMove;
	this->actualMove = maxMove;
	this->maxLife = maxLife;
	this->actualLife = maxLife;
	width = 3;
	height = 3;
	view = " o \n/|\\\n/ \\\n";
	position.X = 10;
	position.Y = 10;
	score = 0;
	isLive = true;
}

Player::~Player() {

}

void Player::reset() {
	actualMove = maxMove;
	actualLife = maxLife;
	score = 0;
	position.X = 10;
	position.Y = 10;
}

int Player::getActualLife() {
	return actualLife;
}

int Player::getActualMove() {
	return actualMove;
}

bool Player::getIsLive() {
	return isLive;
}

void Player::changeLife(int changer) {
	if (changer < 0) {
		position.X = 10;
		position.Y = 10;
	}

	actualLife += changer;
}

bool Player::collisionCheck(Entity* entity) {
	Vector2 entityPosition = entity->getPosition();
	bool isCollided = !(entityPosition.X + entity->getWidth() < position.X ||
		entityPosition.X > position.X + width ||
		entityPosition.Y + entity->getHeight() < position.Y ||
		entityPosition.Y > position.Y + height);
	
	if (isCollided)
		entity->collisionCheck(this);

	return isCollided;
}

void Player::move(Vector2 input) {
	if (input.Y == 0 && input.X == 0)
		return;

	actualMove--;
	position.X += input.X;
	position.Y += input.Y;
}

void Player::sumScore(int sum) {
	score += sum;
}

void Player::multiplyScore(int multiplier) {
	score *= multiplier;
}

int Player::getScore() {
	return score;
}

bool Player::haveMoves() {
	return actualMove > 0;
}