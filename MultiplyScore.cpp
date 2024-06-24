#include "MultiplyScore.h"

MultiplyScore::MultiplyScore() {
	view = "M";
	width = 0;
	height = 0;
	color = Color::YELLOW;
}

MultiplyScore::~MultiplyScore() {

}

void MultiplyScore::interact(Player* player) {
	player->multiplyScore(2);
}