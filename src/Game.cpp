/*
 * Game.cpp
 */

#include "../include/Game.h"

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
			cout<<"Board Full. Game Over!";
			break;
		}
		else{
			cout<<"White player O - ";
			if(this->gameRules->canPlay(this->playerW)){
				this->gameRules->play(this->playerW->move());
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
			}
		}
		if(gameRules->isBoardFull()){
			cout<<"Board Full. Game Over";
			break;
		}
		else{
			cout<<"Black player X - ";
			if(this->gameRules->canPlay(this->playerB)){
				this->gameRules->play(this->playerB->move());
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
			}
		}
	}
}
