/*
 * Main.cpp
 * Yahel Ben-Ishay
 * 305016297
 */

#include "Game.h"

int main(){

	Game *reversi = new Game();
	reversi->playGame();
	delete reversi;
}
