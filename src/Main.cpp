/*
 * Main.cpp
 * Yahel Ben-Ishay
 * 305016297
 */

#include "../include/Game.h"

int main(){
	int player;
	cout<<"Welcome to Reversi! "<<endl<< "1 - Play against the computer"<<endl<<"2 - Play agains another player"<<endl;
	cin>>player;
//TODO check the inputs.
	Game *reversi = new Game(player);
	reversi->playGame();
	//delete reversi;
}
