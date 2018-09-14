#pragma once

#include "object\DiffObject.h"
#include "scenes\Scene.h"

class SceneDifficulty : public Scene {
	int selectedIndex;
	DiffObject *difficulty[4];
public:
	SceneDifficulty(ISceneChanger *changer, Param &param);
	~SceneDifficulty() = default;
	void Select(int dir);
	void Update() override;
	void Draw() const override;
};