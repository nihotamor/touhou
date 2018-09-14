#include "scenes/Scene.h"

Scene::Scene(ISceneChanger *changer, Param &param) : mChanger(changer), sceneCounter(0), IsActive(true), CustomObjectActive(true) {

}

Scene::~Scene() {
	while (!mObjs.empty()) {
		while (!mObjs[0].empty()) {
			delete mObjs[0].back();
			mObjs[0].pop_back();
		}
		mObjs.pop_back();
	}
}

void Scene::Init() {

}

void Scene::Fin() {

}

void Scene::Update() {
	for (unsigned i = 0; i < mObjs.size(); i++) {
		for (unsigned j = 0; j < mObjs[i].size(); j++) {
			mObjs[i][j]->Update();
		}
	}
	sceneCounter++;
}

void Scene::Draw() const {
	for (unsigned i = 0; i < mObjs.size(); i++) {
		for (unsigned j = 0; j < mObjs[i].size(); j++) {
			if (mObjs[i][j]->ShouldRender()) {
				mObjs[i][j]->Draw();
			}
		}
	}
}

bool Scene::IsSceneActive() const {
	return IsActive;
}

void Scene::SetCustomObjectActive(bool active) {
	CustomObjectActive = active;
}