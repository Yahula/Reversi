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
     */
    GameRules();

    /**
     *
     * @param g the gameboard to copy
     */
    GameRules(GameRules *g);

    /**
     * Destructor
     */
    virtual ~GameRules();

    /**
     * This method makes the player move
     * @param d  the desired move - where the player wants to put its disk
     * @return true if succeded
     */
    virtual bool play(Board *b, Disk *d) = 0;

    /**
     * This method checks if a player has any moves
     * @param p - the current player
     * @return true if there is at least one move
     */
    virtual bool canPlay(Board *b, Player *p) = 0;

    /**
     * This move checks if the board is full
     * @return true if the board full
     */
    bool isBoardFull(Board *b);

    /**
     * @return the current score
     */
    int *getScore();

    /**
     * initials the score.
     * @param o the o score
     * @param x the x score
     */

protected:
    /**
     * keeps changing the score of the game as the game goes along.
     * @param change the new numbers to put in - what change to make in the score.
     * @param winner in what direction is the change going - black or white.
     */
    void updateScore(Board *b);

    /**
     * an array with 2 ints - both scores.
     */
    int *score;
};

#endif /* GAMERULES_H_ */
