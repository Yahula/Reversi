/*
 * GameRules.cpp
 */

#include "../include/GameRules.h"

GameRules::GameRules() {
	this->score = new int[2];
	this->score[0] = 2; //White (O) player score
	this->score[1] = 2; //Black (X) player score
}

GameRules::~GameRules() {
}

bool GameRules::isBoardFull(Board *b) {
	for(int i=0; i<b->getRow(); i++){
		for(int j=0; j<b->getCol(); j++){
			if (b->getCell(i,j) == 0){
				return false;
			}
		}
	}
	return true;
}

void GameRules::updateScore(int change, int winner){
	if (winner == 1){this->score[0]+= change; this->score[1] -= change;}
	if (winner == 2){this->score[0] -= change; this->score[1] += change;}
}


int *GameRules::getScore() {
	return this->score;
}
