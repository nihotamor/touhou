#pragma once

#include "ISceneChanger.h"
#include "object\Object.h"
#include <array>
#include <vector>
#include <memory>
#include "Image.h"
#include "Sound.h"
#include "misc\Input.h"

using namespace std;

class Scene {
protected:
	bool CustomObjectActive;
	bool IsActive;
	int sceneCounter;
	ISceneChanger *mChanger;
	vector<vector<Object*>> mObjs;
public:
	Scene() = delete;
	Scene(ISceneChanger *changer, Param &param);
	virtual ~Scene();
	virtual void Init();
	virtual void Fin();
	virtual void Update();
	virtual void Draw() const;
	bool IsSceneActive() const;
	void SetCustomObjectActive(bool active);
};