//
// Created by Yahel Ben ishay on 12/11/17.
//

#include "../include/RemotePlayer.h"

RemotePlayer::RemotePlayer(Client* c, int num) {
    this->client = new Client(c);
    this->pNum = num;

}


RemotePlayer::~RemotePlayer() {
    delete (client);
}

Disk RemotePlayer::move() {
    return this->client->readFromServer();
}

