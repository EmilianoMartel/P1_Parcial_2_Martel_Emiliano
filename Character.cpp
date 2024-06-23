#include "Character.h"

Character::Character() {

}

void Character::move(Vector2 input) {
	position.positionX += input.positionX;
	position.positionY += input.positionY;
}