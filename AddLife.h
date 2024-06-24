#pragma once
#include "Pickable.h"

class AddLife : public Pickable {
public:
	AddLife();
	~AddLife();
	void interact(Player* player) override;
};