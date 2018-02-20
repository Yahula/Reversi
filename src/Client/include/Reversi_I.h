#ifndef REVERSI_I_H_
#define REVERSI_I_H_

#include "GameRules.h"
#include "Disk.h"
#include <vector>

/**
 * This Class is dervied from gameRules class and represents one option of a set of rules
 */
class Reversi_I : public GameRules {
public:
    /**
     * Constructor
     * @param b - the Game board
     */
    Reversi_I();

    /**
     * copy constructor.
     * @param g the rules to copy.
     */
    Reversi_I(GameRules *g);

    /**
     * Destructor
     */
    virtual ~Reversi_I();

    /**
     * This method makes the player move
     * @param d - the desired move - where the player wants to put its disk
     * @return true if succeded
     */
    bool play(Board *b, Disk *d);

    /**
     * This method checks if a player has any moves
     * @param p - the current player
     * @return true if there is at least one move
     */
    bool canPlay(Board *b, Player *p);

protected:
    /**
     * This method checks if there are any neighbours of the oponent player around the selected location
     * @param d - the desired disk location and color
     * @return - an array of 0-8 neighbours where 0 is the neighbour to the left and the next neighbour is the one where you go clockwise.
     * 	if the neighbour exist there will be 1 in the neighbour place otherwise 0. i.e. for the upper right neighbour there'll be 1 in the 3rd place of the array
     */
    void lookAround(Board *b, Disk *d, vector<int> &v);

    /**
     * This method checks each neighbour and verifies that in it's other side (if there are more then one than in the end of this line) there is a disk with the same color of the current player
     * @param d - the desired disk and location
     * @param diractions - an array represents all neighbours of this disk
     * @param changePath - defines if this is a check only (if there are moves for the player) or if this is the actual move that requires the flip of the disks
     * @return true if the player can play\ true if the disk flip succeded
     */
    bool lookForDisk(Board *b, Disk *d, int diraction, bool changePath);

};

#endif /* REVERSI_I_H_ */
