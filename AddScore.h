#pragma once
#include "Pickable.h"

class AddScore : public Pickable {
private:
	void interact(Player* player) override;
public:
	AddScore();
	~AddScore();
};