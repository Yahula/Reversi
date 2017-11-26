/*
 * Reversi_I.cpp
 */

#include "Reversi_I.h"

Reversi_I::Reversi_I(Board *b) : GameRules(b){
}

Reversi_I::~Reversi_I() {
	delete b;
}

bool Reversi_I::play(Disk *d) {
	int* dir = lookAround(d);
	if (dir[0] == -1){
		return false;
	}
	else{
		if (lookForDisk(d,dir,true)){
			cout<<"You're on fire!!!" <<endl;
			return true;
		}
		else{
			return false;
		}
	}
}

bool Reversi_I::canPlay(Player *p) {
	for (int i=0; i<this->b->getRow(); i++){
		for(int j=0; j<this->b->getCol(); j++){
			if (this->b->getCell(i,j) == 0){
				int* dir = new int [8];
				dir = lookAround(new Disk(i,j,p->getpNum()));
				if (dir[0] == -1){
					continue;
				}
				else{
					if (lookForDisk(new Disk(i,j,p->getpNum()),dir,false)){
						return true;
					}
					else{
						continue;
					}
				}
			}
		}
	}
	return false;
}

int* Reversi_I::lookAround(Disk *d) {
	int r = d->getRow();
	int c = d->getCol();
	int p = d->getPlayer();
	int* dir = new int[8];
	bool b = false;

	for(int i=0; i<8; i++){
		dir[i]=0;
	}


	if ((c!=0) && (this->b->getCell(r,c-1)) == -1*p){
		dir[0] = 1;
		b=true;
	}
	if ((c!=0)&&(r!=0)&&(this->b->getCell(r-1,c-1) == -1*p)){
		dir[1] = 1;
		b=true;
	}
	if ((r!=0)&&(this->b->getCell(r-1,c) == -1*p)){
		dir[2] = 1;
		b=true;
	}
	if ((r!=0)&&(c!=this->b->getCol()-1)&&(this->b->getCell(r-1,c+1)) == -1*p){
		dir[3] = 1;
		b=true;
	}
	if ((c!=this->b->getCol()-1)&&(this->b->getCell(r,c+1) == -1*p)){
		dir[4] = 1;
		b=true;
	}
	if ((r!=this->b->getRow()-1)&&(c!=this->b->getCol()-1)&&(this->b->getCell(r+1,c+1) == -1*p)){
		dir[5] = 1;
		b=true;
	}
	if ((r!=this->b->getRow()-1)&&(this->b->getCell(r+1,c) == -1*p)){
		dir[6] = 1;
		b=true;
	}
	if ((r!=this->b->getRow()-1)&&(c!=0)&&(this->b->getCell(r+1,c-1) == -1*p)){
		dir[7] = 1;
		b=true;
	}
	if (!b){
		dir[0] = -1;
	}
	delete d;
	return dir;
}

bool Reversi_I::lookForDisk(Disk* d, int* diractions, bool changePath) {
	int p = d->getPlayer();
	int* dir = diractions;
	bool moneyTime = false;
	bool success = false;


	for(int i=0; i<9; i++){
		int r = d->getRow();
		int c = d->getCol();

		if(!moneyTime&&changePath&&i==8){
			if(success){
				this->b->setCell(new Disk (r,c,p));
			}
			else{
				return success;
			}
			moneyTime = true;
			i=-1;
			continue;
		}

		if(i==8){
			break;
		}

		if(dir[i]==0){
			continue;
		}
		else{
			switch(i){
			case 0:
				while((c>0)&&(this->b->getCell(r,c-1)== -1*p)){
					c--;
					if(moneyTime){
						this->b->setCell(new Disk (r,c,p));
					}
				}
				if (!moneyTime){
					if(!isPathGood(r,c-1)){
						dir[i] = 0;
					}
					else{
						success = true;
					}
				}
				break;

			case 1:
				while((c>0)&& (r>0)&&(this->b->getCell(r-1,c-1) == -1*p)){
					c--;
					r--;
					if(moneyTime){
						this->b->setCell(new Disk (r,c,p));
					}

				}
				if (!moneyTime){
					if(!isPathGood(r-1,c-1)){
						dir[i] = 0;
					}
					else{
						success = true;
					}
				}
				break;

			case 2:
				while((r>0) && (this->b->getCell(r-1,c)== -1*p)){
					r--;
					if(moneyTime){
						this->b->setCell(new Disk (r,c,p));
					}
				}
				if (!moneyTime){
					if(!isPathGood(r-1,c)){
						dir[i] = 0;
					}
					else{
						success = true;
					}
				}
				break;

			case 3:
				while((c<b->getCol()-1) && (r>0) && (this->b->getCell(r-1,c+1) == -1*p)){
					c++;
					r--;
					if(moneyTime){
						this->b->setCell(new Disk (r,c,p));
					}
				}
				if (!moneyTime){
					if(!isPathGood(r-1,c+1)){
						dir[i] = 0;
					}
					else{
						success = true;
					}
				}
				break;

			case 4:
				while((c<b->getCol()-1) && (this->b->getCell(r,c+1)== -1*p)){
					c++;
					if(moneyTime){
						this->b->setCell(new Disk (r,c,p));
					}
				}
				if (!moneyTime){
					if(!isPathGood(r,c+1)){
						dir[i] = 0;
					}
					else{
						success = true;
					}
				}
				break;

			case 5:
				while((c<b->getCol()-1) && (r<b->getRow()-1) && (this->b->getCell(r+1,c+1) == -1*p)){
					c++;
					r++;
					if(moneyTime){
						this->b->setCell(new Disk (r,c,p));
					}
				}
				if (!moneyTime){
					if(!isPathGood(r+1,c+1)){
						dir[i] = 0;
					}
					else{
						success = true;
					}
				}
				break;

			case 6:
				while((r<b->getRow()-1) && (this->b->getCell(r+1,c)== -1*p)){
					r++;
					if(moneyTime){
						this->b->setCell(new Disk (r,c,p));
					}
				}
				if (!moneyTime){
					if(!isPathGood(r+1,c)){
						dir[i] = 0;
					}
					else{
						success = true;
					}
				}
				break;

			case 7:
				while((c>0) && (r<b->getRow()-1) && (this->b->getCell(r+1,c-1) == -1*p)){
					c--;
					r++;
					if(moneyTime){
						this->b->setCell(new Disk (r,c,p));
					}
				}
				if (!moneyTime){
					if(!isPathGood(r+1,c-1)){
						dir[i] = 0;
					}
					else{
						success = true;
					}
				}

				break;
			}
		}
	}
	delete dir;
	return success;
}

bool Reversi_I::isPathGood(int r, int c) {
	if (c==-1||c==b->getCol()||r==-1||r==b->getRow()||this->b->getCell(r,c)==0){
		return false;
	}
	else{
		return true;
	}
}
