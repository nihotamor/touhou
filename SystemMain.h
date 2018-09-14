#pragma once

class SystemMain {
private:
	bool IsPlaying;
public:
	bool Initialize();
	void Finalize() const;
	void Update();
};