#pragma once

#include "object\GameObject.h"
#include "Bomb.h"

class Player : public GameObject {
	Bomb bomb;
	Vector2 lastPos;
	int lifeNum;
	int bombNum;
	int power;
	int point;
	int graze;
	bool isSlowMode;
	bool lockSlowMode;
	int shotCount;
	int muki;
public:
	Player();
	Player(Vector2 position);
	~Player() = default;
	void Init() override;
	void Fin() override;
	void Update() override;
	void Draw() const override;
	void OnCollide(GameObject* obj) override;

	void Move(Vector2 vec);
	void Shot();
	void SlowMode();
	void Bomb();
	void DrawPlayerInfo(Vector2 pos) const;
};