#pragma once
#include "Pickable.h"

class AddLife : public Pickable {
private:
	void interact(Player* player) override;
public:
	AddLife();
	~AddLife();
};