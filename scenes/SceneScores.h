#pragma once

#include "scenes\Scene.h"

class SceneScores : public Scene {
public:
	SceneScores(ISceneChanger *changer, Param &param);
	~SceneScores() = default;
	void Update() override;
	void Draw() const override;
};