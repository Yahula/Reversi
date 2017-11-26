/*
 * Disk.cpp
 */

#include "Disk.h"

Disk::Disk(int r, int c, int p) {
	this->player = p;
	this->row = r;
	this->col = c;
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
