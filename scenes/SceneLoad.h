#pragma once

#include "scenes\Scene.h"

class SceneLoad : public Scene {
	int GraphResolution;
	int startingCounter;
	int loadedNum;
	int allLoadNum;
public:
	SceneLoad(ISceneChanger *changer, Param &param);
	~SceneLoad() = default;
	void Update() override;
	void Draw() const override;
};