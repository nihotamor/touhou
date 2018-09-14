#pragma once

#include "Vector2.h"
#include "object\Player.h"
#include "object\Enemy.h"

class Func {
	static Player player;
public:
	void SetPlayer(Player playerIn);
	static void DrawRotaGraphFWithRate(float x, float y, double exRate, double angle, int handle, int trans);
	static Vector2 GetVectorWithLength(float vecX, float vecY, float length);
	static Vector2 GetVectorAimedPlayer(Vector2 posIn, float length);
	static Vector2 GetRandomPos(Vector2 pos, float distance);
	static double GetAngleAimedPlayer(Vector2 pos);
	static void MoveBossPos(Enemy *boss, Vector2 dest, int count);
	void RandomBossPos(Enemy *boss, int count);
};