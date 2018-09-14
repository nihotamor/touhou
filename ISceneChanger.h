#pragma once

#include "eScene.h"
#include "Parameter.h"

class ISceneChanger {
public:
	virtual void ChangeScene(eScene scene, Param &param, bool clearScenesFlag = false) = 0;
	virtual void PopScene() = 0;
};