#pragma once

#include "misc\Vector2.h"
#include "object\Object.h"
#include <vector>

class GameObject : public Object {
protected:
	static int resolution;
	int flag;
	int count;
	int minCount;
	float hitRange;
	float dispRange;
public:
	GameObject() = delete;
	GameObject(Vector2 position);
	void Init() override;
	void Fin() override;
	void Update() override;
	void Draw() const override;
	void Draw(Vector2 vec, string tag) const;
	void CheckCollision(vector<GameObject*> objs);
	virtual void OnCollide(GameObject* object) = 0;
	static void setResolution(int r);
	Vector2 GetPosition() const;
};