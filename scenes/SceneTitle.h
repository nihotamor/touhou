#pragma once

#include <memory>
#include <array>

#include "scenes\Scene.h"
#include "object\TitleObject.h"
#include "misc\Vector2.h"

using namespace std;

class SceneTitle : public Scene {
	enum eSceneObject {
		gameStart, extraStart, practiceStart, replay, playerData, musicRoom, option, quit
	};
	bool isSelectable[8] = { true,false,false,false,false,false,false,true };
	int selectedObject;
public:
	SceneTitle(ISceneChanger *changer, Param &param);
	~SceneTitle();
	void Init() override;
	void Fin() override;
	void Select(int dir);
	void Update() override;
	void Draw() const override;
};