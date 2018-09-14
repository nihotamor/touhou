#pragma once

#include "object/GameObject.h"
#include "eEnemyType.h"
#include "eMotionType.h"
#include "BossBehaviour.h"

class Enemy : public GameObject {
	eEnemyType enemyType;
	eMotionType motionType;
	BossBehaviour* behaviour;
	bool isBoss;
	double angle;
	double speed;
	Vector2 velocity;
	int muki;
	int shotFunc;
	int deathFunc;
	int life;
	int shotCount;
public:
	Enemy();
	Enemy(Vector2 pos);
	~Enemy() = default;
	BossBehaviour* GetBehaviour() const;
	void InitWithEnemyScript();
	void Init() override;
	void Fin() override;
	void Update() override;
	void Draw() const override;
	void OnCollide(GameObject* objs) override;
};