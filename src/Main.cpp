/*
 * Main.cpp
 * Yahel Ben-Ishay
 * 305016297
 */

#include "../include/Game.h"

int main(){
	int player;
	cout<<"Welcome to Reversi! "<<endl<< "1 - Play against the computer"<<endl<<"2 - Play against another player"<<endl<<"3 - Play against a remote player"<<endl;

	cin>>player;

	while (!cin >> player) {
		cout << "invalid input ignored; please enter 1,2 or 3 only"<<endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin>>player;
	}

	while (player>3 || player<1) {
		cout << "invalid input ;( please enter 1,2 or 3 only"<<endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin>>player;
	}

	Game *reversi = new Game(player);
	reversi->playGame();
	delete (reversi);
}
