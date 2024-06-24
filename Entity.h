#pragma once
#include "AwesomeLibrary.h"
#include <string>
using namespace std;

class Entity {
protected:
	Vector2 position;
	int height;
	int width;
	Color color;
	string view;
	
public:
	Entity(int positionX = 1, int positionY = 1, int width = 1, int height = 1, string view = "X", Color color = Color::WHITE);
	virtual ~Entity();
	virtual void setPosition(int positionX, int positionY);
	virtual bool collisionCheck(Entity* entity);
	virtual Vector2 getPosition();
	virtual int getHeight();
	virtual int getWidth();
	virtual void draw();
};