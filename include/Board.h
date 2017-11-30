/*
 * Board.h
 * Yahel Ben-Ishay
 * 305016297
 */

#ifndef BOARD_H_
#define BOARD_H_
#include <iostream>
#include "Disk.h"
using namespace std;

/**
 * Board class
 * The board class is an abstract class that contains the game board that has the location of the white and black players
 * through this class it is possible to initialize the board
 */
class Board {
public:

	/**
	 * Board Constructor
	 * @param r - number of rows in the board (8 by default)
	 * @param c - number of columns in the board (8 by default)
	 */
	Board(int row=8, int col=8);

	Board(Board* b);
	/**
	 * Board Destructor
	 */
	virtual ~Board();

	void initialBoard();


	/**
	 * DisplayBoard Method
	 * each of the derived classes will implement a different way to display the board
	 */
	virtual void displayBoard()=0;

	/**
	 * getCol Method
	 * @return the number of columns in the board
	 */
	int getCol() const;

	/**
	 * getRow Method
	 * @return the number of rows in the board
	 */
	int getRow() const;

	/**
	 * getCell Method
	 * @param r - row number of the cell
	 * @param c - column number of the cell
	 * @return the value of the cell requested (r,c) in the board: (-1) for black, 1 for white
	 */
	int getCell(int r, int c) const;

	/**
	 * setCell
	 * sets the value in the requested cell
	 * @param d - the disk containing the information of the cell (row,col,player)
	 */
	void setCell(Disk *d);



protected:

	/**
	 * 2D matrix containing cells with values that represents the players disks on the board
	 * -1 represents black player, 1 represent white player
	 */
	int **board;


	/**
	 * the size of the rows (r) and columns (c) of the board
	 */
	int r,c;


};

#endif /* BOARD_H_ */
