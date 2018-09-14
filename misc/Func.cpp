#include "Func.h"

#include "Reference.h"

#include <DxLib.h>

Player Func::player;

void Func::SetPlayer(Player playerIn) {
	player = playerIn;
}

void Func::DrawRotaGraphFWithRate(float x, float y, double exRate, double angle, int handle, int trans) {
	DrawRotaGraphF(x * Ref::pxRate, y * Ref::pxRate, exRate, angle, handle, trans);
}

Vector2 Func::GetVectorWithLength(float vecX, float vecY, float length) {
	Vector2 vec = { vecX, vecY };
	float len = vec.GetLength();
	return vec * length / len;
}

Vector2 Func::GetVectorAimedPlayer(Vector2 vec, float length) {
	float vecX = player.GetPosition().x - vec.x;
	float vecY = player.GetPosition().y - vec.y;
	return GetVectorWithLength(vecX, vecY, length);
}

Vector2 Func::GetRandomPos(Vector2 pos, float distance) {
	return { pos.x + distance * 2.0F * GetRand(65535) / 65536.0F - distance, pos.y + distance * 2.0F * GetRand(65535) / 65536.0F - distance };
}

double Func::GetAngleAimedPlayer(Vector2 pos) {
	return atan2(player.GetPosition().y - pos.y, player.GetPosition().x - pos.x);
}

void Func::MoveBossPos(Enemy *boss, Vector2 dest, int count) {
	int divNum = count * (count + 1) / 2;
	(boss->GetBehaviour())->moveTime = count;
	(boss->GetBehaviour())->count = 0;
	(boss->GetBehaviour())->velocity = (dest - boss->GetPosition()) * 2 / (count + 1);
	(boss->GetBehaviour())->delta = (dest - boss->GetPosition()) * (-1) / divNum;
}

void Func::RandomBossPos(Enemy *boss, int count) {
	MoveBossPos(boss, { GetRand(65535) * 344.0F / 65535.0F + 20, 120.0F * GetRand(65535) / 65535.0F + 20.0F }, count);
}