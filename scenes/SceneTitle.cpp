#include <DxLib.h>

#include "SceneTitle.h"

SceneTitle::SceneTitle(ISceneChanger *changer, Param &param) : Scene(changer, param), selectedObject(0) {
	const string key[8] = {
		"title.0","title.1","title.2","title.3",
		"title.4","title.5","title.6","title.7"
	};
	vector<Object*> objs;
	for (int i = 0; i < 8; i++) {
		objs.push_back(new TitleObject(Vector2(420.0f + 8.0F * i, 200.0f + 32.0f * i)));
		objs[i]->WithKey(key[i]);
	}
	mObjs.push_back(objs);
	Select(0);
}

void SceneTitle::Select(int dir) {
	((TitleObject*)mObjs[0][selectedObject])->Back();
	do {
		selectedObject += dir;
		while (selectedObject < 0) {
			selectedObject += 8;
		}
		while (selectedObject > 7) {
			selectedObject -= 8;
		}
	} while (!isSelectable[selectedObject]);
	((TitleObject*)mObjs[0][selectedObject])->Pop();
}

SceneTitle::~SceneTitle() {
	Scene::~Scene();
}

void SceneTitle::Init() {
	for (int i = 0; i < 8; i++) {
		mObjs[0][i]->Init();
	}
}

void SceneTitle::Fin() {
	for (int i = 0; i < 8; i++) {
		mObjs[0][i]->Fin();
	}
}

void SceneTitle::Update() {
	Scene::Update();
	
	if (CustomObjectActive) {
		float accelX = ((TitleObject*)mObjs[0][selectedObject])->GetAccel().x;
		if (accelX > -0.5f && accelX < 0.5f) {
			if (Input::GetInstance()->GetPadInput(eInput::up) > 0) {
				Select(-1);
				Sound::Instance()->playSound("cursor");
			}
			else if (Input::GetInstance()->GetPadInput(eInput::down) > 0) {
				Select(1);
				Sound::Instance()->playSound("cursor");
			}
		}
		if (Input::GetInstance()->GetPadInput(eInput::shot) == 1) {
			
			Sound::Instance()->playSound("decide");
			Param param;
			switch (selectedObject) {
			case eSceneObject::gameStart:
				mChanger->ChangeScene(eScene::difficulty, param, false);
				break;
			case eSceneObject::extraStart:
				break;
			case eSceneObject::practiceStart:
				break;
			case eSceneObject::replay:
				break;
			case eSceneObject::playerData:
				break;
			case eSceneObject::musicRoom:
				break;
			case eSceneObject::option:
				break;
			case eSceneObject::quit:
				mChanger->PopScene();
				break;
			}
		}
		else if (Input::GetInstance()->GetPadInput(eInput::bomb) == 1) {
			selectedObject = eSceneObject::quit;
		}
	}
}

void SceneTitle::Draw() const {
	((TitleObject*)mObjs[0][selectedObject])->DrawBackground();
	Scene::Draw();
	for (int i = 0; i < 8; i++) {
		if (!isSelectable[i]) {
			((TitleObject*)mObjs[0][i])->DrawOverlay();
		}
	}
}