#include <DxLib.h>

#include "Sound.h"

Sound* Sound::Instance() {
	static Sound sound;
	return &sound;
}

void Sound::MyLoadSound(const string fileName, string tag) {
	int HANDLE = LoadSoundMem(("resources\\sound\\" + fileName).c_str());

	mSoundMap[tag] = HANDLE;
	mPlayFlag[tag] = false;
	allLoadNum++;
}

int Sound::getAllLoadNum() {
	return allLoadNum;
}

void Sound::playSound(string key) {
	mPlayFlag[key] = true;
}

void Sound::Load() {
	MyLoadSound("th_1up.wav", "1up");
	MyLoadSound("th_bomb0.wav", "bomb0");
	MyLoadSound("th_bomb1.wav", "bomb1");
	MyLoadSound("th_bomb2.wav", "bomb2");
	MyLoadSound("th_cancel.wav", "cancel");
	MyLoadSound("th_char_death.wav", "player.death");
	MyLoadSound("th_charge.wav", "charge");
	MyLoadSound("th_cshot.wav", "player.shot");
	MyLoadSound("th_cursor.wav", "cursor");
	MyLoadSound("th_decide.wav", "decide");
	MyLoadSound("th_endtime.wav", "endtime");
	MyLoadSound("th_enemy_death.wav", "enemy.death");
	MyLoadSound("th_enemy_shot.wav", "enemy.shot");
	MyLoadSound("th_final_hit.wav", "finalhit");
	MyLoadSound("th_graze.wav", "graze");
	MyLoadSound("th_hit.wav", "hit");
	MyLoadSound("th_item_get.wav", "item");
	MyLoadSound("th_shot_effect.wav", "effect");
}

void Sound::Update() {
	auto it = mSoundMap.begin();
	while (it != mSoundMap.end()) {
		if (mPlayFlag[it->first]) {
			PlaySoundMem(it->second, DX_PLAYTYPE_BACK);
			mPlayFlag[it->first] = false;
		}
		it++;
	}
}