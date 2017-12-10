//
// Created by Yahel Ben ishay on 12/7/17.
//

#include "Disk.h"
#include "Player.h"

#ifndef REVERSI_CLIENT_H
#define REVERSI_CLIENT_H

#endif //REVERSI_CLIENT_H

class Client: public Player {
public:
    Client(const char *serverIP, int serverPort, int pNum);
    void connectToServer();
    void handleServer();
    Disk* move();
private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
    Disk* remoteMove;
};