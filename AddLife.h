#pragma once
#include "Pickable.h"

class AddLife : public Pickable {
public:
	void draw() override;
	void interact() override;
};