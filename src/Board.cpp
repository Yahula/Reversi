/*
 * Board.cpp
 */

#include "../include/Board.h"

Board::Board(int x, int y) {
	r=x;
	c=y;

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

Board::Board(Board* b) {
    r=b->getRow();
    c=b->getCol();
    board = new int *[c];
    for (int i=0; i<r; i++){
        board[i] = new int[c];
    }
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            board[i][j] = b->getCell(i,j);
        }
    }
}


Board::~Board() {
	delete board;
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
//	delete d;
}