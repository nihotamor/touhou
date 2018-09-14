#pragma once

#include "object\Object.h"
#include "eEffectType.h"

class Effect : public Object {
	eEffectType effect;
public:
	Effect();
	Effect(Vector2 pos);
	~Effect() = default;
	void Init() override;
	void Fin() override;
	void Update() override;
	void Draw() const override;
};