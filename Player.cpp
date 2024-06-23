#include "Player.h"

Player::Player(int maxMove, int maxLife) {
	this->maxMove = maxMove;
	this->maxLife = maxLife;
	this->actualLife = maxLife;
	width = 3;
	height = 3;
	view = " o \n/|\\\n/ \\\n";
	position.X = 10;
	position.Y = 10;
}

Player::~Player() {

}

