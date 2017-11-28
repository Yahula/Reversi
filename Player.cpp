/*
 * Player.cpp
 */

#include "Player.h"

Player::Player() {
	pNum=0;
}

Player::~Player() = default;

int Player::getpNum() const {
	return pNum;
}
