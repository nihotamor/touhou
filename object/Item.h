#pragma once

#include "object\GameObject.h"
#include "eItemType.h"

class Item : public GameObject {
	double angle;
	double speed;
	bool isIndraw;
	eItemType type;
public:
	Item();
	Item(Vector2 pos);
	~Item() = default;
	void Init();
	void Fin();
	void Update();
	void Draw() const;
	void OnCollide(GameObject* obj);
};