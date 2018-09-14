#include <DxLib.h>
#include "GameManager.h"
#include "scenes\SceneLoad.h"
#include "scenes\SceneTitle.h"
#include "scenes\SceneDifficulty.h"
#include "scenes\SceneGame.h"
#include "scenes\SceneResult.h"
#include "scenes\SceneScores.h"
#include "misc\Input.h"

GameManager::GameManager() {
	Param param;
	mSceneList.push_back(make_shared<SceneLoad>(this, param));
	scores.Load();
}

GameManager::~GameManager() {
	scores.Save();
}

bool GameManager::Loop() {
	Input::GetInstance()->Update();
	if (mSceneList.empty()) {
		return false;
	}
	vector<shared_ptr<Scene>> scenes = mSceneList;
	for (unsigned i = 0; i < scenes.size(); i++) {
		if (scenes[i]->IsSceneActive()) {
			scenes[i]->Update();
			scenes[i]->Draw();
		}
	}
	return true;
}

void GameManager::ChangeScene(eScene nextScene, Param &param, bool clearStackFlag) {
	shared_ptr<Scene> top = mSceneList.back();
	top->SetCustomObjectActive(false);
	top->Fin();
	if (clearStackFlag) {
		while (!mSceneList.empty()) {
			mSceneList.pop_back();
		}
	}
	switch (nextScene) {
	case eScene::load:
		mSceneList.push_back(make_shared<SceneLoad>(this, param));
		break;
	case eScene::title:
		mSceneList.push_back(make_shared<SceneTitle>(this, param));
		break;
	case eScene::difficulty:
		mSceneList.push_back(make_shared<SceneDifficulty>(this, param));
		break;
	case eScene::game:
		mSceneList.push_back(make_shared<SceneGame>(this, param));
		break;
	case eScene::result:
		mSceneList.push_back(make_shared<SceneResult>(this, param));
		break;
	case eScene::scores:
		mSceneList.push_back(make_shared<SceneScores>(this, param));
		break;
	case eScene::debug:
		break;
	}
	mSceneList.back()->Init();
}

void GameManager::PopScene() {
	mSceneList.pop_back();
	if (!mSceneList.empty()) {
		shared_ptr<Scene> top = mSceneList.back();
		top->SetCustomObjectActive(true);
		top->Init();
	}
}