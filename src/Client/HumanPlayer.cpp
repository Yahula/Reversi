/*
 * HumanPlayer.cpp
 */

#include "../../include/HumanPlayer.h"
#include <iostream>
using namespace std;

HumanPlayer::HumanPlayer(int pNum){
	this->pNum = pNum;
}

HumanPlayer::~HumanPlayer() {

}

Disk HumanPlayer::move() {
	int row, col;
	if(this->pNum ==-1) {
		cout << "Black player (X) your turn! Choose location: Row Column" << endl;
	} else{
		cout << "White player (O) your turn! Choose location: Row Column" << endl;

	}

	cin>>row>>col;

	while (!cin >> row || !cin >> col) {
			cout << "invalid input ignored; please enter numbers only"<<endl;
			cin.clear();
	        cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    	cin>>row>>col;
	    }
    Disk d;
    d.setRow(row-1);
    d.setCol(col-1);
    d.setPlayer(pNum);

	return d;
}

