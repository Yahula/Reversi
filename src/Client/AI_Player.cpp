//
// Created by Yahel Ben ishay on 11/28/17.
//

#include "./include/AI_Player.h"
#include "./include/Console.h"
#include "./include/HumanPlayer.h"
#include <iostream>

using namespace std;

AI_Player::AI_Player(int pNum, GameRules *g, Board *b) {
    this->pNum = pNum;
    this->gameRules = g;
    this->board = b;
    this->min = -100;
}

AI_Player::~AI_Player() {

}

Disk AI_Player::move() {
    int max = min;
    int temp;
    Disk disk(-1, -1, pNum);
    for (int i = 0; i < board->getRow(); ++i) {
        for (int j = 0; j < board->getCol(); ++j) {
            Disk d(i, j, pNum);
            temp = check_one_place(d);
            if (temp > max) {
                disk.setRow(i);
                disk.setCol(j);
                max = temp;
            }
        }
    }
    return disk;
}

int AI_Player::check_one_place(Disk disk) {
    Console tempBoard(this->board);
    Reversi_I tempRules(this->gameRules);
    HumanPlayer temPlayer(-pNum);
    int DoIt = 100;
    bool played = tempRules.play(&tempBoard, &disk);
    if (!played) {
        return min;
    }
    if (!tempRules.canPlay(&tempBoard, &temPlayer)) {
        return DoIt;
    }

    int max = min;
    Disk d(-1, -1, -pNum);
    for (int i = 0; i < tempBoard.getRow(); ++i) {
        for (int j = 0; j < tempBoard.getCol(); ++j) {
            d.setRow(i);
            d.setCol(j);
            if (tempRules.play(&tempBoard, &d)) {
                int temp = tempRules.getScore()[0] - tempRules.getScore()[1];
                if (temp > max) {
                    max = temp;
                }
            }
        }
    }

    return max;
}