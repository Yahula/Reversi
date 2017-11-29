/*
 * GameRules.h
 *
 * Yahel Ben-Ishay
 * 305016297
 */

#ifndef GAMERULES_H_
#define GAMERULES_H_
#include "Disk.h"
#include "Player.h"
#include "Board.h"
#include <vector>
/**
 * GameRules class is an abstract class which it's derived classes will define the different game rules
 */
class GameRules {
public:
	/**
	 * Constructor
	 * @param b - the game Board
	 */
	GameRules();

	/**
	 * Destructor
	 */
	virtual ~GameRules();

	/**
	 * This method makes the player move
	 * @param d  the desired move - where the player wants to put its disk
	 * @return true if succeded
	 */
	virtual bool play (Board *b,Disk* d) = 0;

	/**
	 * This method checks if a player has any moves
	 * @param p - the current player
	 * @return true if there is at least one move
	 */
	virtual bool canPlay(Board *b,Player* p) = 0;

	/**
	 * This move checks if the board is full
	 * @return true if the board full
	 */
	bool isBoardFull(Board *b);

	void updateScore(int change, int winner);

	int* getScore();

protected:
	 int* score;
};

#endif /* GAMERULES_H_ */
