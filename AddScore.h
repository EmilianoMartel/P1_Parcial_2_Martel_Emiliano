#pragma once
#include "Pickable.h"

class AddScore : public Pickable {
public:
	AddScore();
	~AddScore();
	void interact(Player* player) override;
};