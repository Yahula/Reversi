#include "./include/Disk.h"


int defaultNum = -2;

Disk::Disk(int r, int c, int p) {
    this->player = p;
    this->row = r;
    this->col = c;
}

Disk::Disk(Disk *d) {
    this->player = d->getPlayer();
    this->row = d->getRow();
    this->col = d->getCol();
}

Disk::Disk() {
    player = defaultNum;
    row = defaultNum;
    col = defaultNum;
}


Disk::~Disk() {

}

int Disk::getCol() const {
    return col;
}

int Disk::getPlayer() const {
    return player;
}

int Disk::getRow() const {
    return row;
}

void Disk::setCol(int col) {
    this->col = col;
}


void Disk::setRow(int row) {
    this->row = row;
}


void Disk::setPlayer(int p) {
    player = p;
}
