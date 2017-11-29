//
// Created by Yahel Ben ishay on 11/28/17.
//

#include "../include/AI_Player.h"
#include "../include/GameRules.h"
#include "../include/Console.h"
#include <iostream>
using namespace std;

AI_Player::AI_Player(int pNum, GameRules* g, Board* b){
    this->pNum = pNum;
    this->gameRules = g;
    this->board = b;

}

AI_Player::~AI_Player() {

}

Disk* AI_Player::move() {
    int max = -100;
    int temp;
    Disk disk(-1, -1, pNum);
    for (int i = 0; i < board->getRow(); ++i) {
        for (int j = 0; j < board->getCol(); ++j) {
            Disk d(i, j, pNum);
            temp = check_one_place(d);
            if (temp > max) {
                disk.setRow(i);
                disk.setCol(j);
                max=temp;
            }
        }
    }
    return new Disk(disk.getRow(), disk.getCol(), disk.getPlayer());
}

int AI_Player::check_one_place(Disk disk) {
    Console tempBoard(this->board);
    if(gameRules->canPlay(&tempBoard, pNum)){
        Disk disk(-1,-1,-pNum);
        for (int i = 0; i < tempBoard.getRow(); ++i) {
            for (int j = 0; j < tempBoard.getCol(); ++j) {



            }

        }
    }
    return 0;
}