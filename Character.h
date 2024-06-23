#pragma once
#include "Entity.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Character : public Entity {
protected:
	vector<string> splitByNewline(const string& str);
public:
	Character();
	~Character();
	void move(Vector2 input);
	void draw() override;
};