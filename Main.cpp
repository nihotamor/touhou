#include <DxLib.h>
#include "SystemMain.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SystemMain systemMain;
	if (systemMain.Initialize()) {
		systemMain.Update();
	}
	systemMain.Finalize();
}