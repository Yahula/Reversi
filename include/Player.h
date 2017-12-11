/*
 * Player.h
 * Yahel Ben-Ishay
 * 305016297
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include "Disk.h"

/**
 * The Player class is an abstract class that represents the different types of players
 */
class Player {
public:
	/**
	 * Constructor
	 */
	Player();

	/**
	 * Destructor
	 */
	virtual ~Player();

	/**
	 * This method asks from the player it's desired move
	 * @return Disk - the desired location and disk color back to the game manager
	 */
	virtual Disk* move() = 0;

	/**
	 * @return pNum - the player id - -1 for black, 1 for white
	 */
	int getpNum() const;

	bool getIsRemote() const;

	void setIsRemote(bool isRemote);

protected:
	/**
	 * the player id
	 */
	int pNum;

	bool isRemote;
};

#endif /* PLAYER_H_ */
