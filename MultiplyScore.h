#pragma once
#include "Pickable.h"

class MultiplyScore : public Pickable {
public:
	MultiplyScore();
	~MultiplyScore();
	void interact(Player* player) override;
};