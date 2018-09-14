#pragma once

#include "object\GameObject.h"

class PlayerShot : public GameObject {
	bool subshot;
	Vector2 velocity;
	double angle;
	double speed;
	int power;
public:
	PlayerShot();
	PlayerShot(Vector2 pos);
	~PlayerShot() = default;
	void OnCollide(GameObject* obj) override;
	void Init() override;
	void Fin() override;
	void Update() override;
	void Draw() const override;
};