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


Client::Client(const char *serverIP, int serverPort, int num) : serverIP(serverIP), serverPort(serverPort), clientSocket(0)  {
    try {
        connectToServer();
    } catch (const char *msg) {
        cout << "Failed to connect to server. Reason: " << msg << endl;
        exit(-1);
    }
    this->pNum = num;

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

    if (pNum ==0) {
        if (connect(clientSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == -1) {
            throw "Error connecting to server";
        }
        cout << "Connected to server" << endl;

        int plNum;
        int r = read(clientSocket, &plNum, sizeof(plNum));
        cout << "Player Number: " << plNum << endl;
        this->pNum = plNum;

        char msg[100] = {'\0'};
        r = read(clientSocket, msg, 100);
        cout << msg << endl;
    }

    else{
        if (connect(clientSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
            throw "Error connecting to server";
        }
        cout << "Connected to server" << endl;
        handleServer();
    }
    close(clientSocket);
}

void Client::handleServer(){
    char move[3] = {'\0'};
    int r = read(clientSocket, move, 3);
    int row,col;
    row = move[0];
    col = move[2];
    this->remoteMove = new Disk(row,col,this->pNum*(-1));

}

Disk* Client::move() {
    return NULL;
}

