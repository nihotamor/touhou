#include <DxLib.h>
#include "SystemMain.h"
#include "Reference.h"
#include "GameManager.h"
#include "Image.h"
#include "Sound.h"
#include "Config.h"
#include "misc\FPSManager.h"
#include "Resource.h"

bool SystemMain::Initialize() {
	Config* config = Config::GetInstance();
	config->Load();

	SetOutApplicationLogValidFlag(TRUE);
	SetMainWindowText("–^–‚–@Žg‚¢‚l‚q‚r@`A Starry Witch.@ver1.00");
	SetWindowSizeChangeEnableFlag(TRUE);
	SetAlwaysRunFlag(TRUE);
	SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_DESKTOP);
	ChangeWindowMode(config->GetIsWindowMode()); //
	SetGraphMode(Ref::WIN_W[config->GetResolutionNo()], Ref::WIN_H[config->GetResolutionNo()], 32); //
	SetWindowSizeExtendRate(config->GetWindowExRate()); //

	if (config->GetResolutionNo() == 0) {
		Ref::pxRate = 1.0f;
	}
	else if (config->GetResolutionNo() == 1) {
		Ref::pxRate = 1.5f;
	}
	else {
		Ref::pxRate = 2.0f;
	}

	if (DxLib_Init()) {
		return false;
	}

	SetDrawScreen(DX_SCREEN_BACK);
	SetMouseDispFlag(config->GetDisplayMouse()); //

	Image::Instance()->PreLoad(config->GetResolutionNo());
	SetUseASyncLoadFlag(TRUE);

	this->IsPlaying = true;

	return true;
}

void SystemMain::Update() {
	GameManager game;
	FPSManager fpsmanager;
	while (this->IsPlaying) {
		if (ClearDrawScreen()) {
			this->IsPlaying = false;
		}

		if (!game.Loop()) {
			break;
		}
		Sound::Instance()->Update();
		fpsmanager.Wait();
		fpsmanager.Draw();

		if (ScreenFlip()) {
			this->IsPlaying = false;
		}
		if (ProcessMessage()) {
			this->IsPlaying = false;
		}
	}
}

void SystemMain::Finalize() const {
	Resource::GetInstance()->UnLoad();
	DxLib_End();
}