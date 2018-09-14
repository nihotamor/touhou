#pragma once

class Config {
private:
	int IsWindowMode;
	int DisplayMouse;
	int ResolutionNo;
	double WindowExRate;

	Config();
	~Config() = default;
public:
	static Config* GetInstance();
	void Load();
	void Save() const;

	int GetIsWindowMode() const;
	int GetDisplayMouse() const;
	int GetResolutionNo() const;
	double GetWindowExRate() const;
};