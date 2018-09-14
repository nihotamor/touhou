#pragma once

#include <array>

using namespace std;

enum eInput {
	left, right, up, down, shot, bomb, slow, start,
};

class Input {
	Input();
	~Input() = default;

	static const int KEY_NUM = 256;
	array<int, KEY_NUM> rawInputCounter;

	static const int PAD_NUM = 16;
	array<int, PAD_NUM> padConfig;
	array<int, PAD_NUM> padInputCounter;
	void MergeToPad();
public:
	static Input* GetInstance();
	void Update();
	int GetRawInput(int key) const;
	int GetPadInput(eInput type) const;
};