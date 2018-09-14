#include "Object.h"
#include "misc\Func.h"

Object::Object(Vector2 position) : position(position), counter(0), offset(Ref::VectorZero), alpha(255), fade(0), shouldRender(true), animObject(false) {

}

void Object::Init() {

}

void Object::Fin() {

}

void Object::Update() {
	counter++;
	if (alpha < 255 && fade > 0) {
		alpha += fade;
		alpha = alpha > 255 ? 255 : alpha;
	}
	else if (alpha > 0 && fade < 0) {
		alpha += fade;
		alpha = alpha < 0 ? 0 : alpha;
	}
	else {
		fade = 0;
	}
}

bool Object::ShouldRender() const {
	return shouldRender && (key != "" || animObject);
}

void Object::WithKey(string keyIn) {
	this->key = keyIn;
}

void Object::Fade(int speed) {
	fade = speed;
}

void Object::fadeTime(int time) {
	fade = 255 / time;
}

void Object::Draw() const {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	Func::DrawRotaGraphFWithRate(position.x + offset.x, position.y + offset.y, 1.0, 0.0, Image::Instance()->getImage(key), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
}