#pragma once

#include "misc\Vector2.h"

class BossBehaviour {
public:
	int count;
	Vector2 velocity;
	Vector2 delta;
	int moveTime;

	BossBehaviour();
	~BossBehaviour() = default;
};