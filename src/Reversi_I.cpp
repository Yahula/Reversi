/*
 * Reversi_I.cpp
 */

#include "../include/Reversi_I.h"

Reversi_I::Reversi_I(){
}

Reversi_I::Reversi_I(GameRules* g) : GameRules(g) {}

Reversi_I::~Reversi_I() {
}

bool Reversi_I::play(Board *b, Disk *d) {
	bool didHePlay = false;
    if(b->getCell(d->getRow(),d->getCol())!=0){
        return false;
    }

    vector<int> v(8);
    lookAround(b,d,v);
    for (int k = 0; k < 8; ++k) {
        if (v[k]==1) {
            bool t =  lookForDisk(b, d, k, true);
            if(t){
                didHePlay = true;
                b->setCell(d);
            }
        }
    }
    return didHePlay;
}

bool Reversi_I::canPlay(Board *b,Player *p) {

	for (int i = 0; i < b->getRow(); ++i) {
		for (int j = 0; j < b->getCol(); ++j) {
			if(b->getCell(i,j)==0){
				vector<int> lookarray(8);
				lookAround(b,new Disk(i,j,p->getpNum()),lookarray);
				for (int k = 0; k < 8; ++k) {
					if (lookarray[k]==1) {
						bool bol =  lookForDisk(b, new Disk(i,j,p->getpNum()), k, false);
						if(bol){return bol;}
					}
				}
			}
		}
	}

	return false;
}

void Reversi_I::lookAround(Board *b,Disk *d, vector<int> &v) {
	if(d->getCol()-1>=0) {
		if(b->getCell(d->getRow(),d->getCol()-1)==-d->getPlayer()){
			v[0]=1;
		}
	}
	if((d->getCol()-1)>=0&&(d->getRow()-1)>=0){
		if(b->getCell(d->getRow()-1,d->getCol()-1)==-d->getPlayer()){
			v[1]=1;
		}
	}
	if (d->getRow()-1>=0) {
		if(b->getCell(d->getRow()-1,d->getCol())==-d->getPlayer()){
			v[2]=1;
		}
	}
	if (d->getRow()-1>=0&&d->getCol()+1<b->getCol()) {
		if(b->getCell(d->getRow()-1,d->getCol()+1)==-d->getPlayer()){
			v[3]=1;
		}
	}
	if (d->getCol()+1<b->getCol()) {
		if(b->getCell(d->getRow(),d->getCol()+1)==-d->getPlayer()){
			v[4]=1;
		}
	}
	if (d->getCol()+1<b->getCol()&&d->getRow()+1<b->getRow()) {
		if(b->getCell(d->getRow()+1,d->getCol()+1)==-d->getPlayer()){
			v[5]=1;
		}
	}
	if (d->getRow()+1<b->getRow()) {
		if(b->getCell(d->getRow()+1,d->getCol())==-d->getPlayer()){
			v[6]=1;
		}
	}
	if (d->getCol()-1>=0&&d->getRow()+1<b->getRow()) {
		if(b->getCell(d->getRow()+1,d->getCol()-1)==-d->getPlayer()){
			v[7]=1;
		}
	}
}

bool Reversi_I::lookForDisk(Board *b,Disk* d, int direction, bool changePath) {
	bool isthereadisk = false;

	if (direction==0){
		for (int i = 2; i <= d->getCol(); ++i) {
			if(b->getCell(d->getRow(),d->getCol()-i)==0){
				break;
			}
			else {
				if (b->getCell(d->getRow(), d->getCol() - i) == d->getPlayer()) {
					if (changePath) {
						for (int j = i - 1; j > 0; --j) {
							b->setCell(new Disk(d->getRow(), d->getCol()-j, d->getPlayer()));
						}
						if(d->getPlayer()==1){updateScore(i,1);}
						else{updateScore(i,2);}
					}
					isthereadisk = true;
					break;
				}
			}
		}
	}
	if (direction==1){
		for (int i = 2; i <= d->getCol()&&i<=d->getRow(); ++i) {
			if (b->getCell(d->getRow()-i,d->getCol()-i)==0){break;}
			if(b->getCell(d->getRow()-i,d->getCol()-i)==d->getPlayer()){
				if(changePath){
					for (int j = i-1; j > 0; --j) {
						b->setCell(new Disk(d->getRow()-j, d->getCol()-j, d->getPlayer()));
					}
					if(d->getPlayer()==1){updateScore(i,1);}
					else{updateScore(i,2);}
				}
				isthereadisk = true;
				break;
			}
		}
	}
	if (direction==2){
		for (int i = 2; i <= d->getRow(); ++i) {
			if (b->getCell(d->getRow()-i,d->getCol())==0){break;}
			if(b->getCell(d->getRow()-i,d->getCol())==d->getPlayer()){
				if(changePath){
					for (int j = i-1; j > 0; --j) {
						b->setCell(new Disk(d->getRow()-j, d->getCol(), d->getPlayer()));
					}
					if(d->getPlayer()==1){updateScore(i,1);}
					else{updateScore(i,2);}
				}
				isthereadisk = true;
				break;
			}
		}
	}
	if (direction==3){
		for (int i = 2; d->getCol()+i < b->getCol()&&i<=d->getRow(); ++i) {
			if (b->getCell(d->getRow()-i,d->getCol()+i)==0){break;}
			if(b->getCell(d->getRow()-i,d->getCol()+i)==d->getPlayer()){
				if(changePath){
					for (int j = i-1; j > 0; --j) {
						b->setCell(new Disk(d->getRow()-j, d->getCol()+j, d->getPlayer()));
					}
					if(d->getPlayer()==1){updateScore(i,1);}
					else{updateScore(i,2);}
				}
				isthereadisk = true;
				break;
			}
		}
	}
	if (direction==4){
		for (int i = 2; d->getCol()+i < b->getCol(); ++i) {
			if (b->getCell(d->getRow(),d->getCol()+i)==0){break;}
			if(b->getCell(d->getRow(),d->getCol()+i)==d->getPlayer()){
				if(changePath){
					for (int j = i-1; j > 0; --j) {
						b->setCell(new Disk(d->getRow(), d->getCol()+j, d->getPlayer()));
					}
					if(d->getPlayer()==1){updateScore(i,1);}
					else{updateScore(i,2);}
				}
				isthereadisk = true;
				break;
			}
		}
	}
	if (direction==5){
		for (int i = 2; d->getCol()+i < b->getCol()&& d->getRow()+i<b->getRow(); ++i) {
			if (b->getCell(d->getRow()+i,d->getCol()+i)==0){break;}
			if(b->getCell(d->getRow()+i,d->getCol()+i)==d->getPlayer()){
				if(changePath){
					for (int j = i-1; j > 0; --j) {
						b->setCell(new Disk(d->getRow()+j, d->getCol()+j, d->getPlayer()));
					}
					if(d->getPlayer()==1){updateScore(i,1);}
					else{updateScore(i,2);}
				}
				isthereadisk = true;
				break;
			}
		}
	}
	if (direction==6){
		for (int i = 2; d->getRow()+i<b->getRow(); ++i) {
			if (b->getCell(d->getRow()+i,d->getCol())==0){break;}
			if(b->getCell(d->getRow()+i,d->getCol())==d->getPlayer()){
				if(changePath){
					for (int j = i-1; j > 0; --j) {
						b->setCell(new Disk(d->getRow()+j, d->getCol(), d->getPlayer()));
					}
					if(d->getPlayer()==1){updateScore(i,1);}
					else{updateScore(i,2);}
				}
				isthereadisk = true;
				break;
			}
		}
	}
	if (direction==7){
		for (int i = 2; i <= d->getCol() && d->getRow()+i < b->getRow(); ++i) {
			if (b->getCell(d->getRow()+i,d->getCol()-i)==0){break;}
			if(b->getCell(d->getRow()+i,d->getCol()-i)==d->getPlayer()){
				if(changePath){

					for (int j = i-1; j > 0; --j) {
						b->setCell(new Disk(d->getRow()+j, d->getCol()-j, d->getPlayer()));
					}
					if(d->getPlayer()==1){updateScore(i,1);}
					else{updateScore(i,2);}
				}
				isthereadisk = true;
				break;
			}
		}
	}
	return isthereadisk;
}




