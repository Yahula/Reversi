//
// Created by Yahel Ben ishay on 12/11/17.
//

#include "Player.h"
#include "Client.h"


#ifndef REVERSI_REMOTEPLAYER_H
#define REVERSI_REMOTEPLAYER_H

#endif //REVERSI_REMOTEPLAYER_H

class RemotePlayer: public Player {
public:
    RemotePlayer(Client* c, int num);

    virtual ~RemotePlayer();

    Disk* move();

private:
    Client* client;
};
