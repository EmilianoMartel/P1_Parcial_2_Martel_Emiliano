#include "AddLife.h"

AddLife::AddLife() {
	view = "L";
	width = 0;
	height = 0;
	color = Color::GREEN;
}

AddLife::~AddLife(){}

void AddLife::interact(Player* player) {
	player->changeLife(1);
}