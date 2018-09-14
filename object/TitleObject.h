#pragma once

#include "Object.h"

#include <string>
#include <DxLib.h>

using namespace std;

class TitleObject : public Object {
private:
	Vector2 accel;
public:
	TitleObject(Vector2 vec);
	~TitleObject() = default;
	Vector2 GetAccel() const;
	void Init() override;
	void Fin() override;
	void Update() override;
	void Draw() const override;
	void DrawOverlay() const;
	void DrawBackground() const;
	void Pop();
	void Back();
};