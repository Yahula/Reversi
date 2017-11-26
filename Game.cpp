/*
 * Game.cpp
 */

#include "Game.h"

Game::Game() {
	this->playerW = new HumanPlayer(1);
	this->playerB = new HumanPlayer(-1);
	this->myboard = new Console();
	this->gameRules = new Reversi_I(myboard);
	this->myboard->displayBoard();

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
		if(gameRules->isBoardFull()){
			cout<<"Game Over!";
			break;
		}
		else{
			cout<<"White player O - ";
			if(this->gameRules->canPlay(this->playerW)){
				while(!this->gameRules->play(this->playerW->move())){
					cout<<"Not your best selection. Try again!"<<endl;
				}
				this->myboard->displayBoard();
				flag=0;
			}
			else{
				cout<<"White has No moves!"<<endl;
				if(flag==1){
					cout<<"Game Over!";
					break;
				}
				flag = 1;
				continue;
			}
		}
		if(gameRules->isBoardFull()){
			cout<<"Game Over";
			break;
		}
		else{
			cout<<"Black player X - ";
			if(this->gameRules->canPlay(this->playerB)){
				while(!this->gameRules->play(this->playerB->move())){
					cout<<"Not your best selection. Try again!"<<endl;
				}
				this->myboard->displayBoard();
				flag = 0;
			}
			else{

				cout<<"Black has No moves!"<<endl;
				if(flag==1){
					cout<<"Game Over!";
					break;
				}
				flag=1;
				continue;
			}
		}
	}
}
