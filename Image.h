#pragma once

#include <string>
#include <map>

using namespace std;

class Image {
private:
	map<string, int> mImageMap;
	Image() = default;
	~Image() = default;
	int allLoadNum = 0;
	string res;

	void MyLoadGraph(const string fileName, string tag);
	void MyLoadDivGraph(const string fileName, int allNum, int xnum, int ynum, int xsize, int ysize, string tag);
public:
	static Image *Instance();
	void PreLoad(int resolution);
	void Load(int resolution);
	int getAllLoadNum();
	int getImage(string key);
};