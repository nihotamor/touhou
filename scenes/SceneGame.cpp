#include <DxLib.h>

#include "SceneGame.h"
#include "Reference.h"
#include "Resource.h"

SceneGame::SceneGame(ISceneChanger *changer, Param &param) : Scene(changer, param) {
	difficulty = param.get("Difficulty");
	count = 0;
	vector<Object*> objs;

	for (int i = 0; i < Ref::ENEMY_MAX; i++) {
		enemy.push_back(new Enemy());
		objs.push_back(enemy[i]);
	}
	mObjs.push_back(objs);
	objs.clear();

	for (int i = 0; i < Ref::EFFECT_MAX; i++) {
		effect.push_back(new Effect());
		objs.push_back(effect[i]);
	}
	mObjs.push_back(objs);
	objs.clear();

	player = new Player({ 100.0f, 100.0f });
	objs.push_back(player);
	mObjs.push_back(objs);

	for (int i = 0; i < Ref::PLAYER_SHOT_MAX; i++) {
		pShot.push_back(new PlayerShot());
		objs.push_back(pShot[i]);
	}
	mObjs.push_back(objs);
	objs.clear();

	for (int i = 0; i < Ref::ITEM_MAX; i++) {
		item.push_back(new Item());
		objs.push_back(item[i]);
	}
	mObjs.push_back(objs);
	objs.clear();

	for (int i = 0; i < Ref::ENEMY_SHOT_MAX; i++) {
		eShot.push_back(new EnemyShot());
		objs.push_back(eShot[i]);
	}
	mObjs.push_back(objs);
	objs.clear();

	for (int i = 0; i < Ref::ENEMY_SCRIPT_MAX; i++) {
		script.push_back(new EnemyScript());
	}
	
}

void SceneGame::Update() {
	Scene::Update();
	count++;
	Input* input = Input::GetInstance();
	float speed = 4.0f;
	Vector2 vec = { 0.0F, 0.0F };
	int cross = 0;
	if (input->GetPadInput(eInput::slow)) {
		speed /= 3.0F;
	}
	if (input->GetPadInput(eInput::up)) {
		vec.y -= speed;
		cross |= 0x1;
	}
	if (input->GetPadInput(eInput::down)) {
		vec.y += speed;
		cross |= 0x1;
	}
	if (input->GetPadInput(eInput::left)) {
		vec.x -= speed;
		cross |= 0x2;
	}
	if (input->GetPadInput(eInput::right)) {
		vec.x += speed;
		cross |= 0x2;
	}
	if (cross & 0x1 && cross & 0x2) {
		vec = vec / 1.4142F;
	}
	player->Move(vec);
}

void SceneGame::Draw() const {
	DrawBox(16, 16, 16 + 384, 16 + 448, GetColor(255, 255, 255), TRUE);
	Scene::Draw();
	clsDx();
	printfDx("%d", mObjs[2].size());
	player->DrawPlayerInfo({ 460, 200 });
}