#pragma once

#include <map>
#include <string>

using namespace std;

class Param {
	map<string, int> mParam;
public:
	Param() = default;
	~Param() = default;
	void set(string key, int data);
	int get(string key) const;
};