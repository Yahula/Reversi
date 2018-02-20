#include "./include/GameRules.h"

GameRules::GameRules() {
    this->score = new int[2];
    this->score[0] = 2; //White (O) player score
    this->score[1] = 2; //Black (X) player score
}

GameRules::GameRules(GameRules *g) {
    this->score[0] = g->getScore()[0];
    this->score[1] = g->getScore()[1];
}

GameRules::~GameRules() {

}

bool GameRules::isBoardFull(Board *b) {
    for (int i = 0; i < b->getRow(); i++) {
        for (int j = 0; j < b->getCol(); j++) {
            if (b->getCell(i, j) == 0) {
                return false;
            }
        }
    }
    return true;
}

void GameRules::updateScore(Board *b) {
    score[0] = 0;
    score[1] = 0;
    for (int i = 0; i < b->getRow(); i++) {
        for (int j = 0; j < b->getCol(); j++) {
            if (b->getCell(i, j) == 1) {
                score[0]++;
            } else if (b->getCell(i, j) == -1) {
                score[1]++;
            }
        }
    }
}


int *GameRules::getScore() {
    return this->score;
}
