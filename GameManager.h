#pragma once

#include "ISceneChanger.h"
#include "scenes\Scene.h"
#include "PlayersScore.h"

#include <vector>
#include <memory>

using namespace std;

class GameManager : public ISceneChanger {
	vector<shared_ptr<Scene>> mSceneList;
	PlayersScore scores;
public:
	GameManager();
	~GameManager();
	bool Loop();
	void ChangeScene(eScene nextScene, Param &param, bool clearStackFlag = false);
	void PopScene();
};