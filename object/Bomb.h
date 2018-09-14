#pragma once

#include "object\GameObject.h"

class Bomb : public GameObject {
public:
	Bomb();
	Bomb(Vector2 pos);
	~Bomb() = default;
	void Init() override;
	void Fin() override;
	void Update() override;
	void Draw() const override;
	void OnCollide(GameObject* obj) override;
};