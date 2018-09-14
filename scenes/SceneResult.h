#pragma once

#include "scenes\Scene.h"

class SceneResult : public Scene {
public:
	SceneResult(ISceneChanger *changer, Param &param);
	~SceneResult() = default;
	void Update() override;
	void Draw() const override;
};