#include "Entity.h"

Entity::Entity(int positionX, int positionY, int width, int height, string view, Color color) {
	this->position.X = positionX;
	this->position.Y = positionY;
	this->width = width;
	this->view = view;
	this->height = height;
	this->color = color;
}

Entity::~Entity() {

}

void Entity::setPosition(int positionX, int positionY) {
	this->position.X = positionX;
	this->position.Y = positionY;
}

bool Entity::collisionCheck(Entity* entity) {
	Vector2 temp = entity->getPosition();

	if (temp.X + entity->getWidth() <= position.X ||
		position.X + width <= temp.X) {
		return false;
	}

	if (temp.Y + entity->getHeight() <= position.Y ||
		position.Y + height <= temp.Y) {
		return false;
	}

	return true;
}

void Entity::draw() {
	goToCoordinates(position.X, position.Y);
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