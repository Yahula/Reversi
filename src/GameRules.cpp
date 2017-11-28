/*
 * GameRules.cpp
 */

#include "../include/GameRules.h"

GameRules::GameRules(Board *b) {
	this->b = b;
}

GameRules::~GameRules() {
	delete b;
}

bool GameRules::isBoardFull() {
	for(int i=0; i<this->b->getRow(); i++){
		for(int j=0; j<this->b->getCol(); j++){
			if (this->b->getCell(i,j) == 0){
				return false;
			}
		}
	}
	return true;
}
