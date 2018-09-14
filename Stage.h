#pragma once

class Stage {
	int count;
	int titleDispCount;
	char title[32];
public:
	Stage();
	void WithTitle(const char title[32]);
	void Update();
};