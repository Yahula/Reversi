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

	while (!cin >> player) {
		cout << "invalid input ignored; please enter 1 or 2 only"<<endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin>>player;
	}

	while (player>2 || player<1) {
		cout << "invalid input ;( please enter 1 or 2 only"<<endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin>>player;
	}

	Game *reversi = new Game(player);
	reversi->playGame();
	//delete reversi;
}
