#include "misc/Vector2.h"
#include <math.h>

float Vector2::GetLength(Vector2 other) {
	return sqrtf((this->x - other.x) * (this->x - other.x) + (this->y - other.y) * (this->y - other.y));
}

double Vector2::GetAngle(Vector2 other) {
	return atan2(other.y - this->y, other.x - this->x);
}

Vector2 Vector2::operator + (Vector2 op) {
	Vector2 ret;
	ret.x = this->x + op.x;
	ret.y = this->y + op.y;
	return ret;
}
Vector2 Vector2::operator - (Vector2 op) {
	Vector2 ret;
	ret.x = this->x - op.x;
	ret.y = this->y - op.y;
	return ret;
}
Vector2 Vector2::operator * (float op) {
	Vector2 ret;
	ret.x = this->x * op;
	ret.y = this->y * op;
	return ret;
}
Vector2 Vector2::operator / (float op) {
	Vector2 ret;
	ret.x = this->x / op;
	ret.y = this->y / op;
	return ret;
}