#include "object\EnemyShot.h"
#include "object\Player.h"

EnemyShot::EnemyShot() : EnemyShot(Ref::VectorZero) {

}

EnemyShot::EnemyShot(Vector2 vector) : GameObject(vector) {

}

void EnemyShot::Init() {

}

void EnemyShot::Fin() {

}

void EnemyShot::Update() {

}

void EnemyShot::Draw() const {

}

void EnemyShot::OnCollide(GameObject* obj) {
	if (typeid(obj) != typeid(Player)) {
		return;
	}
}