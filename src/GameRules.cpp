/*
 * GameRules.cpp
 */

#include "../include/GameRules.h"

GameRules::GameRules() {}

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
