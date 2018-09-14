#include "object\Enemy.h"
#include "object\Player.h"

Enemy::Enemy() : Enemy(Ref::VectorZero) {
	behaviour = new BossBehaviour();
}

Enemy::Enemy(Vector2 pos) : GameObject(pos) {

}

void Enemy::Init() {
	GameObject::Init();
}

void Enemy::Fin() {
	GameObject::Fin();
}

BossBehaviour* Enemy::GetBehaviour() const {
	return behaviour;
}

void Enemy::Update() {
	GameObject::Update();
	switch (motionType) {
	case eMotionType::motion_down:
		break;
	default:
		break;
	}
	if (velocity.x > 2.0F && muki != 1) {
		muki = 1;
	}
	else if (velocity.x < -2.0F && muki != 2) {
		muki = 2;
	}
	else if (muki != 0) {
		muki = 0;
	}
}

void Enemy::Draw() const {
	int index;
	string tag;
	index = this->counter / 6 % 4;
	index += muki * 4;
	switch (enemyType) {
	case eEnemyType::alice:
		tag = "alice";
		break;
	case eEnemyType::cirno:
		tag = "cirno";
		break;
	case eEnemyType::doll:
		tag = "doll";
		break;
	case eEnemyType::fairy_blue:
		tag = "fairy_blue";
		break;
	case eEnemyType::fairy_green:
		tag = "fairy_green";
		break;
	case eEnemyType::fairy_red:
		tag = "fairy_red";
		break;
	case eEnemyType::fairy_sunflower:
		tag = "fairy_sunflower";
		break;
	case eEnemyType::fairy_yellow:
		tag = "fairy_yellow";
		break;
	case eEnemyType::ghost:
		tag = "ghost";
		break;
	default:
		tag = "null";
		break;
	}
	GameObject::Draw(position, tag + "_" + to_string(index));
}

void Enemy::OnCollide(GameObject* obj) {
	if (typeid(obj) != typeid(Player)) {
		return;
	}
}