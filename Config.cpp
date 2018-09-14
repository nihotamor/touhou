#include "Config.h"
#include <DxLib.h>
#include "object/GameObject.h"

Config::Config() : IsWindowMode(TRUE), DisplayMouse(TRUE), ResolutionNo(0), WindowExRate(1.0) {

}

Config* Config::GetInstance() {
	static Config config;
	return &config;
}

void Config::Load() {
	FILE *fp;
	fopen_s(&fp, "config.dat", "rb");
	if (fp) {
		fread(&IsWindowMode, sizeof(int), 1, fp);
		fread(&DisplayMouse, sizeof(int), 1, fp);
		fread(&ResolutionNo, sizeof(int), 1, fp);
		fread(&WindowExRate, sizeof(double), 1, fp);
		fclose(fp);
		GameObject::setResolution(ResolutionNo);
	}
}

void Config::Save() const {
	FILE *fp;
	fopen_s(&fp, "config.dat", "wb");
	if (fp) {
		fwrite(&IsWindowMode, sizeof(int), 1, fp);
		fwrite(&DisplayMouse, sizeof(int), 1, fp);
		fwrite(&ResolutionNo, sizeof(int), 1, fp);
		fwrite(&WindowExRate, sizeof(double), 1, fp);
		fclose(fp);
	}
}

int Config::GetIsWindowMode() const {
	return IsWindowMode;
}

int Config::GetDisplayMouse() const {
	return DisplayMouse;
}

int Config::GetResolutionNo() const {
	return ResolutionNo;
}

double Config::GetWindowExRate() const {
	return WindowExRate;
}