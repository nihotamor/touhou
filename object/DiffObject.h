#pragma once

#include "object\Object.h"

class DiffObject : public Object {
private:
	Vector2 accel;
public:
	DiffObject(Vector2 vec);
	~DiffObject() = default;
	Vector2 GetAccel() const;
	void Update() override;
	void Draw() const override;
	void SetAlpha(int alpha);
};