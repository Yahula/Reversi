/*
 * Player.cpp
 */

#include "../include/Player.h"

Player::Player() {
	pNum=0;
	isRemote = false;
}

bool Player::getIsRemote() const {
	return isRemote;
}

void Player::setIsRemote(bool isRemote) {
	Player::isRemote = isRemote;
}

Player::~Player() {

}

int Player::getpNum() const {
	return pNum;
}
