#include "GameObject.h"
#include <DxLib.h>
#include "Reference.h"
#include "misc\Func.h"

int GameObject::resolution;

void GameObject::setResolution(int r) {
	resolution = r;
}

GameObject::GameObject(Vector2 position) : Object(position), hitRange(0.0F), count(0), minCount(-1), dispRange(10.0F) {

}

void GameObject::Init() {
	flag = true;
	count = 0;
}

void GameObject::Fin() {
	flag = false;
}

void GameObject::Update() {
	Object::Update();
	if (!flag) {
		return;
	}
	if (minCount != -1 && count > minCount) {
		if (position.x < -dispRange || position.y < -dispRange || position.x > Ref::FLD_W + dispRange || position.y > Ref::FLD_H + dispRange) {
			Fin();
		}
	}
	count++;
}

void GameObject::Draw() const {
	Object::Draw();
}

void GameObject::Draw(Vector2 position, string tag) const {
	Func::DrawRotaGraphFWithRate(position.x + 16 + 8 * resolution, position.y + 16 + 8 * resolution, 1.0, 0.0, Image::Instance()->getImage(tag), TRUE);
}

void GameObject::CheckCollision(vector<GameObject*> objs) {
	if (hitRange <= 0.0F) {
		return;
	}
	for (unsigned i = 0; i < objs.size(); i++) {
		Vector2 pos = objs[i]->position;
		if ((pos.y - position.y) * (pos.y - position.y) + (pos.x - position.x) * (pos.x - position.x) < (objs[i]->hitRange - this->hitRange) * (objs[i]->hitRange - this->hitRange)) {
			this->OnCollide(objs[i]);
		}
	}
}

Vector2 GameObject::GetPosition() const {
	return position;
}