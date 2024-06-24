#include "AddScore.h"


AddScore::AddScore(){
	view = "S";
	width = 0;
	height = 0;
	color = Color::BLUE;
}

AddScore::~AddScore(){}

void AddScore::interact(Player* player) {
	player->sumScore(1);
}