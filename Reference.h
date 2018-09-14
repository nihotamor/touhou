#pragma once

#include "misc\Vector2.h"

class Ref {
public:
	const static int WIN_W[3];
	const static int WIN_H[3];
	static float pxRate;

	const static int FLD_W;
	const static int FLD_H;

	const static int ENEMY_MAX;
	const static int PLAYER_SHOT_MAX;
	const static int ENEMY_SHOT_MAX;
	const static int EFFECT_MAX;
	const static int ITEM_MAX;
	const static int ITEM_INDRAW_HEIGHT;
	const static int SHOT_FUNC_MAX;
	const static int DEATH_FUNC_MAX;
	const static int ENEMY_SCRIPT_MAX;

	const static float PI;
	const static float PI2;

	const static Vector2 VectorZero;
};