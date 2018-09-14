#include <DxLib.h>

#include "SceneDifficulty.h"

SceneDifficulty::SceneDifficulty(ISceneChanger *changer, Param &param) : Scene(changer, param), selectedIndex(0) {
	vector<Object*> objs;
	string key[4] = { "diff.easy","diff.normal","diff.hard","diff.lunatic" };
	for (int i = 0; i < 4; i++) {
		difficulty[i] = new DiffObject(Vector2(320.0F, 150.0F + 90.0F * i));
		difficulty[i]->WithKey(key[i]);
		difficulty[i]->SetAlpha(60);
		objs.push_back(difficulty[i]);
	}
	difficulty[0]->SetAlpha(255);
	mObjs.push_back(objs);
}

void SceneDifficulty::Update() {
	if (Input::GetInstance()->GetPadInput(eInput::up) == 1 && selectedIndex > 0) {
		Select(-1);
	}
	else if (Input::GetInstance()->GetPadInput(eInput::down) == 1 && selectedIndex < 3) {
		Select(1);
	}
	if (Input::GetInstance()->GetPadInput(eInput::bomb) == 1) {
		mChanger->PopScene();
	}
	if (Input::GetInstance()->GetPadInput(eInput::shot) == 1) {
		Param param;
		param.set("Difficulty", selectedIndex);
		mChanger->ChangeScene(eScene::game, param, true);
	}
}

void SceneDifficulty::Select(int dir) {
	difficulty[selectedIndex]->SetAlpha(60);
	selectedIndex += dir;
	if (selectedIndex > 3) {
		selectedIndex = 3;
	}
	else if (selectedIndex < 0) {
		selectedIndex = 0;
	}
	difficulty[selectedIndex]->SetAlpha(255);
	Sound::Instance()->playSound("cursor");
}

void SceneDifficulty::Draw() const {
	Scene::Draw();
}