#include "object\PlayerShot.h"
#include "object\Enemy.h"

PlayerShot::PlayerShot() : PlayerShot(Ref::VectorZero) {

}

PlayerShot::PlayerShot(Vector2 pos) : GameObject(pos), angle(-Ref::PI / 2) {
	hitRange = 6.0f;
	dispRange = 20.0f;
}

void PlayerShot::Init() {
	GameObject::Init();
}

void PlayerShot::Fin() {
	GameObject::Fin();
}

void PlayerShot::Update() {

}

void PlayerShot::Draw() const {

}

void PlayerShot::OnCollide(GameObject* obj) {
	if (typeid(obj) != typeid(Enemy)) {
		return;
	}
}