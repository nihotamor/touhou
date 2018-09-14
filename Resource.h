#pragma once

class Resource {
	Resource() = default;
	~Resource() = default;
	int Font;
public:
	static Resource* GetInstance();
	void Load();
	void UnLoad();
	static int GetFont();
};