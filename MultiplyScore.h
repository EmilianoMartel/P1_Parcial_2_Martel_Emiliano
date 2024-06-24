#pragma once
#include "Pickable.h"

class MultiplyScore : public Pickable {
private:
	void interact(Player* player) override;
public:
	MultiplyScore();
	~MultiplyScore();
};