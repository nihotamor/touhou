#pragma once

#include <DxLib.h>

class Vector2 {
public:
	Vector2() = default;
	Vector2(float x, float y) :x(x), y(y) {};
	~Vector2() = default;

	float GetLength(Vector2 other = { 0.0F, 0.0F });
	double GetAngle(Vector2 other);

	Vector2 operator + (Vector2 op);
	Vector2 operator - (Vector2 op);
	Vector2 operator * (float op);
	Vector2 operator / (float op);

	float x, y;
};