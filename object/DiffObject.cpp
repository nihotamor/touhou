#include "object\\DiffObject.h"
#include "Reference.h"

DiffObject::DiffObject(Vector2 vec) : Object(vec), accel(Ref::VectorZero) {
	alpha = 0, fade = 24;
	shouldRender = true;
}

Vector2 DiffObject::GetAccel() const {
	return accel;
}

void DiffObject::SetAlpha(int alphaIn) {
	alpha = alphaIn;
}

void DiffObject::Update() {
	Object::Update();
	if (accel.x <= -1.0f) {
		accel.x += 1.0f;
		offset.x += accel.x;
	}
	else if (accel.x >= 1.0f) {
		accel.x -= 1.0f;
		offset.x += accel.x;
	}
	if (accel.y <= -1.0f) {
		accel.y += 1.0f;
		offset.y += accel.y;
	}
	else if (accel.y >= 1.0f) {
		accel.y -= 1.0f;
		offset.y += accel.y;
	}
}

void DiffObject::Draw() const {
	Object::Draw();
}