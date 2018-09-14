#include "FPSManager.h"

#include <DxLib.h>

FPSManager::FPSManager() : counter(0), fps(0) {

}

FPSManager::~FPSManager() {
	timeList.clear();
}

void FPSManager::Wait() {
	counter++;
	WaitTimer(getWaitTime());
	regist();
	if (counter == UPDATE_INTERVAL) {
		updateAverage();
		counter = 0;
	}
}

void FPSManager::Draw() const {
	if (fps == 0) {
		return;
	}
	DrawFormatString(0, 0, GetColor(255, 255, 255), "[%04.1f]", fps);
}

void FPSManager::regist() {
	timeList.push_back(GetNowCount());
	if (timeList.size() > LIST_COUNT) {
		timeList.pop_front();
	}
}

unsigned FPSManager::getWaitTime() const {
	int Len = (int)timeList.size();
	if (Len == 0) {
		return 0;
	}
	int exceptTime = (int)(1000.0f / 60.f * (Len));
	int passedTime = GetNowCount() - timeList.front();
	int WaitTime = exceptTime - passedTime;
	WaitTime = WaitTime > 0 ? WaitTime : 0;
	return (unsigned)WaitTime;
}

void FPSManager::updateAverage() {
	int Len = (int)timeList.size();
	if (Len < LIST_COUNT) {
		return;
	}
	int passedTime = timeList.back() - timeList.front();
	float average = (float)passedTime / (Len - 1);
	if (average == 0) {
		return;
	}
	fps = 1000 / average;
}