#pragma once

#include <list>

#define FPS_VALUE 60.0
#define LIST_COUNT 120
#define UPDATE_INTERVAL 60

using namespace std;

class FPSManager {
	int counter;
	list<int> timeList;
	float fps;

	void updateAverage();
	void regist();
	unsigned getWaitTime() const;
public:
	FPSManager();
	~FPSManager();
	void Wait();
	void Draw() const;
};