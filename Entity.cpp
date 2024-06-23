#include "Entity.h"

Entity::Entity(int positionX, int positionY, int width, int height, string view, Color color) {
	this->position.positionX = positionX;
	this->position.positionY = positionY;
	this->width = width;
	this->view = view;
	this->height = height;
	this->color = color;
}

void Entity::setPosition(int positionX, int positionY) {
	this->position.positionX = positionX;
	this->position.positionY = positionY;
}

bool Entity::collisionCheck(Entity* entity) {
	Vector2 temp = entity.getPosition();

	if (temp.positionX + entity.getWidth() <= position.positionX ||
		position.positionX + width <= temp.positionX) {
		return false;
	}

	if (temp.positionY + entity.getHeight() <= position.positionY ||
		position.positionY + height <= temp.positionY) {
		return false;
	}

	return true;
}

void Entity::draw() {
	goToCoordinates(position.positionX, position.positionY);
	cout << "X";
}

Vector2 Entity::getPosition() {
	return position;
}

int Entity::getHeight() {
	return height;
}

int Entity::getWidth() {
	return width;
}