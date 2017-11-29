/*
 * Console.h
 * Yahel Ben-Ishay
 * 305016297
 */

#ifndef CONSOLE_H_
#define CONSOLE_H_
#include "Board.h"
/**
 * Console Class - a board derived class. displays the board in the console
 */
class Console: public Board {
public:
	/**
	 * Constructor
	 * @param r - number of rows in the board that supposed to be printed
	 * @param c - number of columns in the board that should be printed
	 */
	Console(int row=8, int col=8);

	Console(Board* b);
	/**
	 * Desructor
	 */
	virtual ~Console();

	/**
	 * displayBoard Method
	 * prints the board to the console
	 */
	void displayBoard();

};

#endif /* CONSOLE_H_ */
