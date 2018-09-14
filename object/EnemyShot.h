#pragma once

#include "object\GameObject.h"
#include "object\Enemy.h"
#include "eBulletType.h"

class EnemyShot : public GameObject {
	eBulletType type;
	int color;
	Vector2 velocity;
	double angle;
	double speed;
	int accelCount;
	Vector2 accel;
	int grazed;
	int state;
public:
	EnemyShot();
	EnemyShot(Vector2 pos);
	~EnemyShot() = default;
	void Init() override;
	void Fin() override;
	void Update() override;
	void Draw() const override;
	void OnCollide(GameObject* obj) override;
};