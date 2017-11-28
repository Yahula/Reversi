/*
 * HumanPlayer.cpp
 */

#include "../include/HumanPlayer.h"
#include <iostream>
using namespace std;

HumanPlayer::HumanPlayer(int pNum){
	this->pNum = pNum;
}

HumanPlayer::~HumanPlayer() {

}

Disk* HumanPlayer::move() {
	int row, col;
	cin>>row>>col;

	while (!cin >> row || !cin << col) {
			cout << "invalid input ignored; please enter numbers only"<<endl;
			cin.clear();
	        cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    	cin>>row>>col;
	    }
	return new Disk(row-1,col-1,this->pNum);
}

