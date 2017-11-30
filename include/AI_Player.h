//
// Created by Yahel Ben ishay on 11/28/17.
//

#ifndef REVERSI_AI_PLAYER_H
#define REVERSI_AI_PLAYER_H

#include "Reversi_I.h"

class AI_Player: public Player {

public:
    /**
     * Constructor
     * @param pNum - the player "id" -1 for black, 1 for white
     */
    AI_Player(int pNum, GameRules* g, Board* b);

    /**
     * Destructor
     */
    virtual ~AI_Player();

    /**
     * This method tell the machine to make its move.
     * @return Disk - the chosen disk location and color to the game manager
     */
    virtual Disk* move();

private:
    GameRules* gameRules;

    
    Board* board;

    /**
     * this method check one stepahead - what could be the result of this action?
     * @param Disk the location is question.
     * @return the max score the oponnent can make if this move is chosen
     */
    int check_one_place(Disk);


    int min;

};

#endif //REVERSI_AI_PLAYER_H

