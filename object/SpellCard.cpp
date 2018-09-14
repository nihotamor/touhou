#include "object\SpellCard.h"
#include "Config.h"
#include "Resource.h"

const int SpellCard::FLAG_FALSE = 0;
const int SpellCard::FLAG_TRUE = 1;
const int SpellCard::FLAG_ENDURANCE = 2;

SpellCard::SpellCard() : SpellCard({ Ref::FLD_W * (Config::GetInstance()->GetResolutionNo() * 0.5F + 1.0F) - 8.0F - Config::GetInstance()->GetResolutionNo() * 4.0F, 8.0F + Config::GetInstance()->GetResolutionNo() * 4.0F }) {

}

SpellCard::SpellCard(Vector2 pos) : Object(pos) {

}

void SpellCard::Init() {

}

void SpellCard::Fin() {

}

void SpellCard::Update() {

}

void SpellCard::Draw() const {
	int handle = Resource::GetFont();
	int width = GetDrawStringWidthToHandle(spellCardName, strlen(spellCardName), handle);
	int res = Config::GetInstance()->GetResolutionNo() * 8;
	DrawStringFToHandle(16 + res + position.x - width, 16 + res + position.y, spellCardName, GetColor(255, 255, 255), handle);
}

SpellCard* SpellCard::WithName(const char name[64]) {
	strcpy_s(spellCardName, name);
	return this;
}

SpellCard* SpellCard::WithBonus(int flag, int amount) {
	bonusFlag = flag;
	bonusAmount = amount;
	return this;
}