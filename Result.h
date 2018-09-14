#pragma once

#include "object\Player.h"

class Result {
	Player *player;
	bool scoreAdded;
	int clearBonus;
	int point;
	int graze;
	int player;
	int bomb;
	double rank;
	int total;
public:
	Result() = delete;
	Result(Player *player);
	void Update();
	void Draw() const;
};