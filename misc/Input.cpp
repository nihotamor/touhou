#include <DxLib.h>
#include "Input.h"

Input::Input() {
	padConfig[eInput::down] = 0;
	padConfig[eInput::left] = 1;
	padConfig[eInput::right] = 2;
	padConfig[eInput::up] = 3;
	padConfig[eInput::shot] = 4;
	padConfig[eInput::bomb] = 5;
	padConfig[eInput::slow] = 6;
	padConfig[eInput::start] = 12;
}

void Input::Update() {
	char KeyStateArray[256];
	int i;
	GetHitKeyStateAll(KeyStateArray);
	for (i = 0; i < KEY_NUM; i++) {
		if (KeyStateArray[i]) {
			rawInputCounter[i]++;
		}
		else {
			rawInputCounter[i] = 0;
		}
	}

	int padIn = GetJoypadInputState(DX_INPUT_PAD1);
	for (i = 0; i < PAD_NUM; i++) {
		if (padIn & (1 << i)) {
			padInputCounter[i]++;
		}
		else {
			padInputCounter[i] = 0;
		}
	}

	MergeToPad();
}

Input* Input::GetInstance() {
	static Input input;
	return &input;
}

int Input::GetPadInput(eInput input) const {
	return padInputCounter[padConfig[input]];
}

int Input::GetRawInput(int key) const {
	if (key >= 0 && key < KEY_NUM) {
		return rawInputCounter[key];
	}
	return -1;
}

void Input::MergeToPad() {
	padInputCounter[padConfig[eInput::left]] = max(padInputCounter[padConfig[eInput::left]], GetRawInput(KEY_INPUT_LEFT));
	padInputCounter[padConfig[eInput::right]] = max(padInputCounter[padConfig[eInput::right]], GetRawInput(KEY_INPUT_RIGHT));
	padInputCounter[padConfig[eInput::up]] = max(padInputCounter[padConfig[eInput::up]], GetRawInput(KEY_INPUT_UP));
	padInputCounter[padConfig[eInput::down]] = max(padInputCounter[padConfig[eInput::down]], GetRawInput(KEY_INPUT_DOWN));
	padInputCounter[padConfig[eInput::shot]] = max(padInputCounter[padConfig[eInput::shot]], GetRawInput(KEY_INPUT_Z));
	padInputCounter[padConfig[eInput::shot]] = max(padInputCounter[padConfig[eInput::shot]], GetRawInput(KEY_INPUT_RETURN));
	padInputCounter[padConfig[eInput::bomb]] = max(padInputCounter[padConfig[eInput::bomb]], GetRawInput(KEY_INPUT_X));
	padInputCounter[padConfig[eInput::slow]] = max(padInputCounter[padConfig[eInput::slow]], GetRawInput(KEY_INPUT_LSHIFT));
	padInputCounter[padConfig[eInput::start]] = max(padInputCounter[padConfig[eInput::start]], GetRawInput(KEY_INPUT_ESCAPE));
}