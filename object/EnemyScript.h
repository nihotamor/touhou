#pragma once

#include "object\Enemy.h"

class EnemyScript {
	bool flag;
	int effectFlag;
	int spawnCount;
	int enemyType;
	int motionPettern;
	double x;
	double y;
	double speed;
	int shotFunc;
	int deathFunc;
	int life;
public:
	EnemyScript() = default;
	~EnemyScript() = default;
	int getSpawnCount() const;
	bool shouldSpawn() const;
	void Spawn(Enemy *enemy);
};