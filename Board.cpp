/*
 * Board.cpp
 */

#include "Board.h"

Board::Board(int x, int y) {
	r=x;
	c=y;

	initialBoard();

}

Board::Board(Board* b) {
    r=b->getRow();
    c=b->getCol();
    initialBoard();

}


Board::~Board() {
	delete board;
}


void Board::initialBoard(){
	board = new int *[c];
		for (int i=0; i<r; i++){
			board[i] = new int[c];
		}
		for (int i=0; i<r; i++){
			for (int j=0; j<c; j++){
				board[i][j] = 0;
			}
		}
	board[(r/2)-1][(c/2)-1] = 1;
	board[(r/2)-1][c/2] = -1;
	board[r/2][(c/2)-1] = -1;
	board[r/2][c/2] = 1;

}

int Board::getCol() const {
	return c;
}

int Board::getRow() const {
	return r;
}


int Board::getCell(int r, int c) const {
	return this->board[r][c];
}

void Board::setCell(Disk* d) {
	this->board[d->getRow()][d->getCol()] = d->getPlayer();
	delete d;
}
