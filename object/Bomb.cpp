#include <DxLib.h>
#include "Bomb.h"
#include "object/Player.h"

Bomb::Bomb() : Bomb(Ref::VectorZero) {

}

Bomb::Bomb(Vector2 pos) : GameObject(pos) {
	this->hitRange = 10000;
	WithKey("bomb");
}

void Bomb::Init() {

}

void Bomb::Fin() {
	
}

void Bomb::Update() {
	GameObject::Update();
}

void Bomb::Draw() const {
	GameObject::Draw();
}

void Bomb::OnCollide(GameObject* obj) {
	if (typeid(Player) == typeid(obj)) {
		return;
	}
}