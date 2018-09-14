#include "Parameter.h"

void Param::set(string key, int data) {
	mParam[key] = data;
}

int Param::get(string key) const {
	auto data = mParam.find(key);
	if (mParam.end() == data) {
		return -1;
	}
	else {
		return data->second;
	}
}