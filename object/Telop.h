#pragma once

#include "object\Object.h"

class Telop : public Object {
	char str[32];
public:
	Telop();
	Telop(Vector2 pos);
	~Telop() = default;
	void Init() override;
	void Fin() override;
	void Update() override;
	void Draw() const override;
	Telop* WithString(const char strIn[32]);
};