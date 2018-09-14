#include <DxLib.h>
#include "object\Player.h"
#include "Reference.h"
#include "Resource.h"
#include "Config.h"

Player::Player() : Player(Ref::VectorZero) {

}

Player::Player(Vector2 position) : GameObject(position) {
	minCount = -1;
	animObject = true;
	hitRange = 2.4F;
}

void Player::Init() {
	lifeNum = 3;
	bombNum = 3;
	power = 0;
	point = 0;
	graze = 0;
	isSlowMode = false;
	lockSlowMode = false;
	shotCount = 0;
}

void Player::Fin() {

}

void Player::Update() {
	GameObject::Update();
}

void Player::Draw() const {
	int index = (this->counter / 6) % 4;
	index += muki * 4;
	DrawBoxAA(position.x - 24 + 16, position.y - 24 + 16, position.x + 24 + 16, position.y + 24 + 16, GetColor(255, 0, 255), TRUE);
	GameObject::Draw(position, "player_" + to_string(index));
}

void Player::OnCollide(GameObject* object) {
	if (typeid(object) == typeid(Player)) {

	}
}

void Player::Move(Vector2 vec) {
	this->position.x +=vec.x;
	this->position.y += vec.y;
	if (vec.x > 2.0F) {
		muki = 1;
	}
	else if (vec.x < -2.0F) {
		muki = 2;
	}
	else {
		muki = 0;
	}
	position.x = position.x < 5.0F ? 5.0F : position.x > Ref::FLD_W - 5.0F ? Ref::FLD_W - 5.0F : position.x;
	position.y = position.y < 5.0F ? 5.0F : position.y > Ref::FLD_H - 5.0F ? Ref::FLD_H - 5.0F : position.y;
}

void Player::Shot() {

}

void Player::SlowMode() {

}

void Player::Bomb() {

}

void Player::DrawPlayerInfo(Vector2 pos) const {
	pos = pos * (1.0F + Config::GetInstance()->GetResolutionNo() * 0.5F);
	int handle = Resource::GetFont();
	int size = 20 + 10 * Config::GetInstance()->GetResolutionNo();
	string str = "Player  ";
	for (int i = 0; i < this->lifeNum; i++) {
		str += "Åö";
	}
	DrawFormatStringFToHandle(pos.x, pos.y, GetColor(255, 255, 255), handle, str.c_str());
	str = "Bomb    ";
	for (int i = 0; i < this->bombNum; i++) {
		str += "Åö";
	}
	DrawFormatStringFToHandle(pos.x, pos.y + size, GetColor(255, 255, 255), handle, str.c_str());
	DrawFormatStringFToHandle(pos.x, pos.y + size * 2 + 10, GetColor(255, 255, 255), handle, "Power   %d", this->power);
	DrawFormatStringFToHandle(pos.x, pos.y + size * 3 + 10, GetColor(255, 255, 255), handle, "Point   %d", this->point);
	DrawFormatStringFToHandle(pos.x, pos.y + size * 4 + 10, GetColor(255, 255, 255), handle, "Graze   %d", this->graze);
}