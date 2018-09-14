#include "object\Telop.h"
#include "Config.h"
#include "Resource.h"

Telop::Telop() : Telop({ Ref::FLD_W * (1.0F + Config::GetInstance()->GetResolutionNo() / 2.0F) / 2.0F, 128 * (1.0F + Config::GetInstance()->GetResolutionNo() / 2.0F) }) {

}

Telop::Telop(Vector2 pos) : Object(pos) {

}

void Telop::Init() {

}

void Telop::Fin() {
	counter = -1;
}

void Telop::Update() {
	if (counter != -1) {
		counter++;
		if (counter == 300) {
			Fin();
		}
	}
}

void Telop::Draw() const {
	if (counter != -1) {
		int handle = Resource::GetFont();
		int width = GetDrawStringWidthToHandle(str, strlen(str), handle);
		float res = Config::GetInstance()->GetResolutionNo() * 8.0F;
		DrawStringFToHandle(16 + res + position.x - width, position.y + res, str, GetColor(255, 255, 255), handle);
	}
}

Telop* Telop::WithString(const char strIn[32]) {
	counter = 0;
	strcpy_s(str, strIn);
	return this;
}