#include "object\EnemyScript.h"

int EnemyScript::getSpawnCount() const {
	return spawnCount;
}

bool EnemyScript::shouldSpawn() const {
	return flag;
}

void EnemyScript::Spawn(Enemy* enemy) {
	flag = false;
}