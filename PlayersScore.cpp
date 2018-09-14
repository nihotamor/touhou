#include <DxLib.h>
#include <stdio.h>

#include "PlayersScore.h"

void PlayersScore::Load() {
	FILE *fp;
	fopen_s(&fp, "save.dat", "rb");
	if (fp == NULL) {
		for (int i = 0; i < 4; i++) {
			for (int i1 = 0; i1 < 10; i1++) {
				strcpy_s(score[i][i1].name, "NoName");
			}
			score[0][0].score = 200000;
			score[0][1].score = 175000;
			score[0][2].score = 150000;
			score[0][3].score = 125000;
			score[0][4].score = 100000;
			score[0][5].score = 90000;
			score[0][6].score = 80000;
			score[0][7].score = 70000;
			score[0][8].score = 60000;
			score[0][9].score = 50000;

			score[1][0].score = 300000;
			score[1][1].score = 275000;
			score[1][2].score = 250000;
			score[1][3].score = 225000;
			score[1][4].score = 200000;
			score[1][5].score = 175000;
			score[1][6].score = 150000;
			score[1][7].score = 125000;
			score[1][8].score = 100000;
			score[1][9].score = 50000;

			score[1][0].score = 3000000;
			score[1][1].score = 2750000;
			score[1][2].score = 2500000;
			score[1][3].score = 2250000;
			score[1][4].score = 2000000;
			score[1][5].score = 1750000;
			score[1][6].score = 1500000;
			score[1][7].score = 1250000;
			score[1][8].score = 1000000;
			score[1][9].score = 500000;

			score[3][0].score = 4500000;
			score[3][1].score = 4250000;
			score[3][2].score = 4000000;
			score[3][3].score = 3750000;
			score[3][4].score = 3500000;
			score[3][5].score = 3250000;
			score[3][6].score = 3000000;
			score[3][7].score = 2500000;
			score[3][8].score = 2000000;
			score[3][9].score = 1000000;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		for (int i1 = 0; i1 < 10; i1++) {
			int s;
			fread(score[i][i1].name, sizeof(char), 9, fp);
			fread(&s, sizeof(int), 1, fp);
			score[i][i1].score = (s + 81425) / 3;
		}
	}
	fclose(fp);
}

void PlayersScore::Save() const {
	FILE *fp;
	fopen_s(&fp, "save.dat", "wb");
	if (fp) {
		for (int i = 0; i < 4; i++) {
			for (int i1 = 0; i1 < 10; i1++) {
				int s = score[i][i1].score * 3 - 81425;
				fwrite(score[i][i1].name, sizeof(char), 9, fp);
				fwrite(&s, sizeof(int), 1, fp);
			}
		}
		fclose(fp);
	}
}

void PlayersScore::Draw() const {

}

Score* PlayersScore::getScore(int diff) {
	return score[diff];
}