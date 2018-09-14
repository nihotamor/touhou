#include <DxLib.h>

#include "Resource.h"
#include "Reference.h"
#include "SceneLoad.h"
#include "Config.h"
#include "misc\Func.h"
#include <math.h>

SceneLoad::SceneLoad(ISceneChanger *changer, Param &param) : Scene(changer, param), allLoadNum(0), startingCounter(0) {
	GraphResolution = Config::GetInstance()->GetResolutionNo();
	Image *image = Image::Instance();
	image->Load(GraphResolution);

	Sound *sound = Sound::Instance();
	sound->Load();

	Resource *resource = Resource::GetInstance();
	resource->Load();

	allLoadNum = image->getAllLoadNum() + sound->getAllLoadNum();
}

void SceneLoad::Update() {
	Scene::Update();
	loadedNum = allLoadNum - GetASyncLoadNum();
	if (loadedNum == allLoadNum) {
		startingCounter++;
	}
	if (startingCounter == 60) {
		Param param;
		mChanger->ChangeScene(eScene::title, param, TRUE);
	}
}

void SceneLoad::Draw() const {
	Func::DrawRotaGraphFWithRate(Ref::WIN_W[0] / 2.f, Ref::WIN_H[0] / 2.f, 1.0, 0.0, Image::Instance()->getImage("load.display"), TRUE);
	DrawBoxAA(20.0F * Ref::pxRate, 220.0F * Ref::pxRate, 620.0F * Ref::pxRate, 260.0F * Ref::pxRate, GetColor(200, 200, 200), TRUE);
	SetDrawArea(20, 220, 20 + 600 * loadedNum / allLoadNum, 260);
	Func::DrawRotaGraphFWithRate(Ref::WIN_W[0] / 2.f, Ref::WIN_H[0] / 2.f, 1.0, 0.0, Image::Instance()->getImage("load.bar"), TRUE);
	SetDrawArea(0, 0, Ref::WIN_W[GraphResolution], Ref::WIN_H[GraphResolution]);
	Func::DrawRotaGraphFWithRate(Ref::WIN_W[0] / 2.f, Ref::WIN_H[0] / 2.f, 1.0, 0.0, Image::Instance()->getImage("load.frame"), TRUE);
	if (startingCounter == 0) {
		DrawString(10, (int)(5.0 * sin(sceneCounter * 0.07) + 10), "Loading...", GetColor(255, 255, 255));
	}
	else {
		DrawString(10, (int)(5.0 * sin(sceneCounter * 0.07) + 10), "Starting...", GetColor(255, 255, 255));
	}
}