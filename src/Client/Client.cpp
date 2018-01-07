//
// Created by Yahel Ben ishay on 12/7/17.
//

#include <sys/socket.h>
#include <arpa/inet.h>
#include "./include/Client.h"
#include <iostream>
#include <netdb.h>
#include <unistd.h>

using namespace std;

#define MAX_MSG_LEN 100


Client::Client(const char *serverIP, int serverPort) : serverIP(serverIP), serverPort(serverPort), clientSocket(0)  {
    this->localPNum = 0;
    try {
        connectToServer();
    } catch (const char *msg) {
        cout << "Failed to connect to server. Reason: " << msg << endl;
        exit(-1);
    }
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

    if (connect(clientSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error connecting to server";
    }
    cout << "Connected to server" << endl;

//    int plNum;
//    int r = read(clientSocket, &plNum, sizeof(plNum));
//    cout << "Player Number: " << plNum << endl;
//
//    if (plNum == 1) {
//        this->localPNum = -1;
//    } else{
//        this->localPNum = 1;
//    }
//    char msg[100] = {'\0'};
//    r = read(clientSocket, msg, sizeof(msg)/ sizeof(char));
//    cout << msg << endl;

}

int Client::getLocalPNum() const {
    return localPNum;
}

Disk Client::readFromServer(){
    char move[10] = {'\0'};
    int row, col;

    int r = read(clientSocket, move, sizeof(move)/ sizeof(char));
    row = (int) move[0];
    col = (int) move[2];

    Disk d;
    d.setRow(row);
    d.setCol(col);
    d.setPlayer(-localPNum);

    return d;
}

void Client::writeToServer(Disk* d) {
    char arg[MAX_MSG_LEN] = {'\0'};
    int w;
    arg[0] = d->getRow();
    arg[1] = ',';
    arg[2] = d->getCol();

    delete(d);

    w = write(clientSocket, arg, strlen(arg));
    if (w == -1) {
        std::cout << "Error writing to server" << std::endl;
        return;
    }

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

void Client::writeStringToServer(char* str) {
    int s = strlen(str);
    int w = write(clientSocket, str, s);
    if (w == -1) {
        std::cout << "Error writing to server" << std::endl;
        return;
    }
}

char* Client::readStringFromServer(){
    char msg[MAX_MSG_LEN] = {'\0'};
    int r;
    do{
        r = read(clientSocket,msg, MAX_MSG_LEN);
    } while(r==-1);

    cout<<msg<<endl;
    return msg;
}





