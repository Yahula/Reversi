#ifndef HUMANPLAYER_H_
#define HUMANPLAYER_H_

#include "Player.h"

/**
 * The Human player class is derived from the Player class and represent a human player that input the desired moves
 */
class HumanPlayer : public Player {

public:
    /**
     * Constructor
     * @param pNum - the player "id" -1 for black, 1 for white
     */
    HumanPlayer(int pNum);

    /**
     * Destructor
     */
    virtual ~HumanPlayer();

    /**
     * This method asks from the player to insert it's desired move
     * @return Disk - the chosen disk location and color to the game manager
     */
    virtual Disk move();

};

#endif /* HUMANPLAYER_H_ */
