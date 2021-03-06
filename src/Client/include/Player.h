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
    virtual Disk move() = 0;

    /**
     * @return pNum - the player id - -1 for black, 1 for white
     */
    int getpNum() const;

    /**
     * @return the mode of the game. rather the game is played through a rever(remote) -true. or not - fals.
     */
    bool getIsRemote() const;

    /**
     * sets the game to be a remote game.
     * @param isRemote true if it is remote.
     */
    void setIsRemote(bool isRemote);

protected:
    /**
     * the player id
     */
    int pNum;

    /**
     * the mode of the game - remote = true/fals.
     */
    bool isRemote;
};

#endif /* PLAYER_H_ */
