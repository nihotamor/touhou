#include "TitleObject.h"
#include "Reference.h"
#include "misc\Func.h"
#include <string.h>

TitleObject::TitleObject(Vector2 vec) : Object(vec), accel(Ref::VectorZero) {
	alpha = 0;
}

void TitleObject::Update() {
	Object::Update();
	if (accel.x <= -1.0f) {
		accel.x += 1.0f;
		offset.x += accel.x;
	}
	else if (accel.x >= 1.0f) {
		accel.x -= 1.0f;
		offset.x += accel.x;
	}
}

void TitleObject::Init() {
	Fade(24);
}

void TitleObject::Fin() {
	Fade(-24);
}

void TitleObject::Draw() const {
	Object::Draw();
}

Vector2 TitleObject::GetAccel() const {
	return accel;
}

void TitleObject::Pop() {
	accel.x = -8.0f;
}

void TitleObject::Back() {
	accel.x = 8.0f;
}

void TitleObject::DrawOverlay() const {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	Func::DrawRotaGraphFWithRate(position.x + offset.x, position.y + offset.y, 1.0, 0.0, Image::Instance()->getImage("title.cross"), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
}

void TitleObject::DrawBackground() const {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)(alpha / 3.0));
	Func::DrawRotaGraphFWithRate(position.x + offset.x, position.y + offset.y, 1.0, 0.0, Image::Instance()->getImage("title.back"), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
}