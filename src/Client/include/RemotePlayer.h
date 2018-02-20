#include "Player.h"
#include "Client.h"


#ifndef REVERSI_REMOTEPLAYER_H
#define REVERSI_REMOTEPLAYER_H

class RemotePlayer : public Player {

public:
    /**
     * contructor.
     * @param c the client through which the player connects to the server.
     * @param num
     */
    RemotePlayer(Client *c, int num);

    /**
     * ditructor.
     */
    virtual ~RemotePlayer();

    /**
     * gets the move the remote player made from the server.
     * @return a disk the player placed.
     */
    Disk move();

private:
    /**
     * the client that connects to the server.
     */
    Client *client;
};


#endif //REVERSI_REMOTEPLAYER_H