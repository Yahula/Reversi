//
// Created by Yahel Ben ishay on 12/7/17.
//

#include "Disk.h"
#include "Player.h"

#ifndef REVERSI_CLIENT_H
#define REVERSI_CLIENT_H

#endif //REVERSI_CLIENT_H

class Client {

public:
    Client(const char *serverIP, int serverPort);
    Client(Client* c);
    void connectToServer();
    Disk* readFromServer();
    void writeToServer(Disk* d);

    int getServerPort() const;
    int getLocalPNum() const;
    const char *getServerIP() const;
    int getClientSocket() const;

private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
    int localPNum;
};