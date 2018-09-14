#pragma once

#include "Score.h"

class PlayersScore {
	Score current;
	Score score[4][10];
public:
	PlayersScore() = default;
	~PlayersScore() = default;
	void Load();
	void Save() const;
	void Draw() const;
	Score* getScore(int diff);
};