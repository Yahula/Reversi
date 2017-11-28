//
// Created by Yahel Ben ishay on 11/28/17.
//

#include "../include/AI_Player.h"
#include "../include/GameRules.h"
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
    int row, col;
    return new Disk(row-1,col-1,this->pNum);
}