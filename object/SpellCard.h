#pragma once

#include "object\Object.h"
#include "object\Enemy.h"

class SpellCard : public Object {
	char spellCardName[64];
	Enemy *bossPointer;
	int lifeMax;
	int bonusFlag;
	int bonusAmount;
public:
	const static int FLAG_FALSE;
	const static int FLAG_TRUE;
	const static int FLAG_ENDURANCE;

	SpellCard();
	SpellCard(Vector2 pos);
	~SpellCard() = default;
	void Init() override;
	void Fin() override;
	void Update() override;
	void Draw() const override;
	SpellCard* WithName(const char name[64]);
	SpellCard* WithBonus(const int flag, const int amount);
};