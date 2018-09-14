#pragma once

#include "misc\Vector2.h"
#include <string>
#include <memory>
#include "Image.h"
#include "Reference.h"

using namespace std;

class Object {
protected:
	bool animObject;
	int alpha, fade;
	bool shouldRender;
	int counter;
	string key;
	Vector2 position, offset;
public:
	Object() = delete;
	Object(Vector2 position);
	~Object() = default;
	virtual void Init();
	virtual void Fin();
	virtual void Update();
	virtual void Draw() const;
	bool ShouldRender() const;
	void WithKey(string keyIn);
	void Fade(int speed);
	void fadeTime(int time);
};