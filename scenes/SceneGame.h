#pragma once

#include "object\Player.h"
#include "object\Enemy.h"
#include "object\PlayerShot.h"
#include "object\EnemyShot.h"
#include "object\Effect.h"
#include "object\Item.h"
#include "object\EnemyScript.h"
#include "scenes\Scene.h"

class SceneGame : public Scene {
	int difficulty;
	int count;
	Player* player;
	vector<Enemy*> enemy;
	vector<PlayerShot*> pShot;
	vector<EnemyShot*> eShot;
	vector<Effect*> effect;
	vector<Item*> item;
	vector<EnemyScript*> script;
public:
	SceneGame(ISceneChanger *changer, Param &param);
	~SceneGame() = default;
	void Update() override;
	void Draw() const override;
};