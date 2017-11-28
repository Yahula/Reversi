//
// Created by Yahel Ben ishay on 11/28/17.
//

#ifndef REVERSI_AI_PLAYER_H
#define REVERSI_AI_PLAYER_H

#include "Player.h"

class AI_Player: public Player {

public:
    /**
     * Constructor
     * @param pNum - the player "id" -1 for black, 1 for white
     */
    AI_Player(int pNum);

    /**
     * Destructor
     */
    virtual ~AI_Player();

    /**
     * This method asks from the player to insert it's desired move
     * @return Disk - the chosen disk location and color to the game manager
     */
    virtual Disk* move();

};

#endif //REVERSI_AI_PLAYER_H

