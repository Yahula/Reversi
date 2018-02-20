/*
 * Board.cpp
 */

#include "./include/Board.h"

Board::Board(int row, int col) {
    this->r = row;
    this->c = col;
    initialBoard();
}

Board::Board(Board *b) {
    r = b->getRow();
    c = b->getCol();
    this->board = new int *[c];
    for (int i = 0; i < r; i++) {
        this->board[i] = new int[c];
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            this->board[i][j] = b->getCell(i, j);
        }
    }
}

void Board::initialBoard() {
    this->board = new int *[c];
    for (int i = 0; i < r; i++) {
        this->board[i] = new int[c];
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            this->board[i][j] = 0;
        }
    }
    this->board[(r / 2) - 1][(c / 2) - 1] = 1;
    this->board[(r / 2) - 1][c / 2] = -1;
    this->board[r / 2][(c / 2) - 1] = -1;
    this->board[r / 2][(c / 2)] = 1;
}

Board::~Board() {
    delete this->board;
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

void Board::setCell(Disk d) {
    this->board[d.getRow()][d.getCol()] = d.getPlayer();
}