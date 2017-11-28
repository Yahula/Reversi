/*
 * Game.cpp
 */

#include "../include/Game.h"

Game::Game() {
	this->playerW = new HumanPlayer(1);
	this->playerB = new HumanPlayer(-1);
	this->myboard = new Console(4,4);
	this->gameRules = new Reversi_I(myboard);
	this->myboard->displayBoard();
	this->score = new int[2];
	this->score[0] = 2; //White (O) player score
	this->score[1] = 2; //Black (X) player score

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
			cout<<"Board Full. Game Over!"<<endl;
			break;
		}
		else{
			cout<<"White player (O) Choose location: Row Column"<<endl;
			if(this->gameRules->canPlay(this->playerW)){
				this->gameRules->play(this->playerW->move(),this->score);
				cout<<endl<<"Score - "<<"White (O): "<<this->score[0]<<", Black (X): "<<this->score[1]<<endl<<endl;

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

		if(gameRules->isBoardFull()){
			cout<<"Board Full. Game Over!"<<endl;
			break;
		}
		else{
			cout<<"Black player (X) Choose location: Row Column"<<endl;
			if(this->gameRules->canPlay(this->playerB)){
				this->gameRules->play(this->playerB->move(), this->score);
				cout<<endl<<"Score - "<<"White (O): "<<this->score[0]<<", Black (X): "<<this->score[1]<<endl<<endl;
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
