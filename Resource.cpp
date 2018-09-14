#include <DxLib.h>

#include "Config.h"
#include "Resource.h"

Resource* Resource::GetInstance() {
	static Resource res;
	return &res;
}

void Resource::Load() {
	//if (AddFontResource("resources/font/wlcmaru2004emojip.ttf") <= 0) {
	//	MessageBox(NULL, "Font Load Failed.", "", MB_OK);
	//}
	//Font = CreateFontToHandle("˜a“cŒ¤’†ŠÛƒSƒVƒbƒN2004ŠG•¶ŽšP", 32 + 16 * Config::GetInstance()->GetResolutionNo(), 1);
	Font = CreateFontToHandle("", 16 + 8 * Config::GetInstance()->GetResolutionNo(), 1);
}

void Resource::UnLoad() {
	//if (RemoveFontResource("resources/font/wlcmaru2004emojip.ttf") <= 0) {
	//	MessageBox(NULL, "Font Unload Failed.", "", MB_OK);
	//}
}

int Resource::GetFont() {
	return GetInstance()->Font;
}