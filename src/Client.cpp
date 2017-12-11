//
// Created by Yahel Ben ishay on 12/7/17.
//

#include <sys/socket.h>
#include <arpa/inet.h>
#include "../include/Client.h"
#include <iostream>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
using namespace std;


Client::Client(const char *serverIP, int serverPort) : serverIP(serverIP), serverPort(serverPort), clientSocket(0)  {
    try {
        connectToServer();
    } catch (const char *msg) {
        cout << "Failed to connect to server. Reason: " << msg << endl;
        exit(-1);
    }
    this->localPNum = 0;
}

Client::Client(Client* c) {
    this->serverIP = c->getServerIP();
    this->serverPort = c->getServerPort();
    this->clientSocket = c->getClientSocket();
    this->localPNum = c->getLocalPNum();
}

void Client::connectToServer(){
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        throw "Error opening socket";
    }

    struct in_addr address;
    if (!inet_aton(serverIP, &address)) {
        throw "Can't parse IP address";
    }

    struct hostent *server;
    server = gethostbyaddr((const void *)&address, sizeof address, AF_INET);

    if (server == NULL) {
        throw "Host is unreachable";
    }

    struct sockaddr_in serverAddress;
    bzero((char *)&address, sizeof(address));
    serverAddress.sin_family = AF_INET;
    memcpy((char *)&serverAddress.sin_addr.s_addr, (char *)server->h_addr, (size_t)(server->h_length));
    serverAddress.sin_port = htons(serverPort);

    if (this->localPNum == 0) {
        if (connect(clientSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == -1) {
            throw "Error connecting to server";
        }
        cout << "Connected to server" << endl;

        int plNum;
        int r = read(clientSocket, &plNum, sizeof(plNum));
        cout << "Player Number: " << plNum << endl;

        if (plNum == 1) {
            this->localPNum = -1;
        } else{
            this->localPNum = 1;
        }
        char msg[100] = {'\0'};
        r = read(clientSocket, msg, 100);
        cout << msg << endl;
        close(clientSocket);
    }

    else{
        if (connect(clientSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
            throw "Error connecting to server";
        }
        cout << "Connected to server" << endl;
    }
}

int Client::getLocalPNum() const {
    return localPNum;
}

Disk* Client::readFromServer(){
    char move[3] = {'\0'};
    int r = read(clientSocket, move, 3);
    int row,col;
    row = move[0];
    col = move[2];
    return new Disk(row,col,this->localPNum*-1);
}

void Client::writeToServer(Disk* d){
    char arg[3];
    arg[0] = (char)d->getRow();
    arg[1] = ',';
    arg[2] = (char)d->getCol();
    int w = write(clientSocket,arg,3);
    close(clientSocket);


}

const char *Client::getServerIP() const {
    return serverIP;
}

int Client::getServerPort() const {
    return serverPort;
}

int Client::getClientSocket() const {
    return clientSocket;
}




