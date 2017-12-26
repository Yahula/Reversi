//
// Created by Yahel Ben ishay on 12/11/17.
//

#include <iostream>
#include "../../include/RemotePlayer.h"

RemotePlayer::RemotePlayer(Client* c, int num) {
    this->client = new Client(c);
    this->pNum = num;

}


RemotePlayer::~RemotePlayer() {
    delete (client);
}

Disk RemotePlayer::move() {
    std::cout<<"Waiting for other player move..."<<std::endl;
    return this->client->readFromServer();
}

