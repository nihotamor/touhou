#pragma once

#include <string>
#include <map>

using namespace std;

class Sound {
private:
	map<string, int> mSoundMap;
	map<string, bool> mPlayFlag;
	Sound() = default;
	~Sound() = default;
	int allLoadNum = 0;

	void MyLoadSound(const string fileName, string tag);
public:
	void Update();
	static Sound *Instance();
	void Load();
	int getAllLoadNum();
	void playSound(string key);
};