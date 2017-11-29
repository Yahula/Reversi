/*
 * Game.cpp
 */

#include "../include/Game.h"

Game::Game(int player) {
    this->myboard = new Console();
    this->myboard->displayBoard();

    this->gameRules = new Reversi_I();
	if (player == 1){this->playerW = new AI_Player(1,this->gameRules,this->myboard);}
	if (player == 2){this->playerW = new HumanPlayer(1);}
    this->playerB = new HumanPlayer(-1);

}

Game::~Game() {
	delete playerW;
	delete playerB;
	delete myboard;
	delete gameRules;
}

void Game::playGame() {
	int flag = 0;
	while(true){
		if(gameRules->isBoardFull(myboard)){
			cout<<"Board Full. Game Over!"<<endl;
			break;
		}
		else{
			cout<<"White player (O) Choose location: Row Column"<<endl;
			if(this->gameRules->canPlay(myboard,this->playerW)){
				this->gameRules->play(myboard,this->playerW->move());
				cout<<endl<<"Score - "<<"White (O): "<<this->gameRules->getScore()[0]<<", Black (X): "<<this->gameRules->getScore()[1]<<endl<<endl;

				this->myboard->displayBoard();
				flag=0;
			}
			else {
				cout << "White has No moves!" << endl;
				if (flag == 1) {
					cout << "Game Over!" << endl;
					break;
				}
				flag = 1;
			}
		}

		if(gameRules->isBoardFull(myboard)){
			cout<<"Board Full. Game Over!"<<endl;
			break;
		}
		else{
			cout<<"Black player (X) Choose location: Row Column"<<endl;
			if(this->gameRules->canPlay(myboard,this->playerB)){
				this->gameRules->play(myboard,this->playerB->move());
				cout<<endl<<"Score - "<<"White (O): "<<this->gameRules->getScore()[0]<<", Black (X): "<<this->gameRules->getScore()[1]<<endl<<endl;
				this->myboard->displayBoard();
				flag = 0;
			    }
			else{

				cout<<"Black has No moves!"<<endl;
				if(flag==1){
					cout<<"Game Over!"<<endl;
					break;
				}
				flag=1;
			}
		}
	}
}
