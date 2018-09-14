#include <DxLib.h>

#include "Image.h"

Image* Image::Instance() {
	static Image ins;
	return &ins;
}

void Image::MyLoadGraph(const string fileName, string tag) {
	int HANDLE = LoadGraph(("resources\\image\\" + res + "\\" + fileName).c_str());
	mImageMap[tag] = HANDLE;
	allLoadNum++;
}

void Image::MyLoadDivGraph(const string fileName, int allNum, int xnum, int ynum, int xsize, int ysize, string tag) {
	int *HANDLE;
	HANDLE = (int*)malloc(sizeof(int) * allNum);
	
	LoadDivGraph(("resources\\image\\" + res + "\\" + fileName).c_str(), allNum, xnum, ynum, xsize, ysize, HANDLE);

	for (int i = 0; i < allNum; i++) {
		mImageMap[tag + "_" + to_string(i)] = HANDLE[i];
		allLoadNum++;
	}
	free(HANDLE);
}

int Image::getAllLoadNum() {
	return allLoadNum;
}

int Image::getImage(string key) {
	auto it = mImageMap.find(key);
	if (mImageMap.end() == it) {
		return -1;
	}
	else {
		return it->second;
	}
}

void Image::PreLoad(int resolution) {
	res = to_string(resolution);
	MyLoadGraph("load\\bar.png", "load.bar");
	MyLoadGraph("load\\display.png", "load.display");
	MyLoadGraph("load\\frame.png", "load.frame");
}

void Image::Load(int resolution) {
	char str[32];
	res = to_string(resolution);
	MyLoadGraph("title\\title0.png", "title.0");
	MyLoadGraph("title\\title1.png", "title.1");
	MyLoadGraph("title\\title2.png", "title.2");
	MyLoadGraph("title\\title3.png", "title.3");
	MyLoadGraph("title\\title4.png", "title.4");
	MyLoadGraph("title\\title5.png", "title.5");
	MyLoadGraph("title\\title6.png", "title.6");
	MyLoadGraph("title\\title7.png", "title.7");
	MyLoadGraph("title\\cross.png", "title.cross");
	MyLoadGraph("title\\back.png", "title.back");
	MyLoadGraph("title\\easy.png", "diff.easy");
	MyLoadGraph("title\\normal.png", "diff.normal");
	MyLoadGraph("title\\hard.png", "diff.hard");
	MyLoadGraph("title\\lunatic.png", "diff.lunatic");

	MyLoadDivGraph("player.png", 12, 4, 3, 48, 48, "player");
}