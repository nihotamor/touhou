#include "Stage.h"
#include <string.h>

Stage::Stage() {
	count = 0;
}

void Stage::WithTitle(const char titleIn[32]) {
	strcpy_s(title, titleIn);
}

void Stage::Update() {
	count++;
	if (count == titleDispCount) {

	}
}