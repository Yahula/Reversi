//
// Created by Yahel Ben ishay on 12/7/17.
//

#include "Disk.h"
#include "Player.h"

#ifndef REVERSI_CLIENT_H
#define REVERSI_CLIENT_H

class Client {

public:
    /**
     * constructor.
     * @param serverIP the ip of the server.
     * @param serverPort the port of the server.
     */
    Client(const char *serverIP, int serverPort);

    /**
     * copy constructor.
     * @param c the client to copy.
     */
    Client(Client* c);

    /**
     * the method that connects to the server.
     */
    void connectToServer();

    /**
     * reads the move the remote player made.
     * @return the disk that presents the move.
     */
    Disk readFromServer();
    
    /*
     * reads a string from the server.
     */
    char* readStringFromServer();

    /**
     * writes a disk that was played by the local player to the server.
     * @param d the disk that was played.
     */
    void writeToServer(Disk* d);

    /**
     * writes a given string to the server.
     * @param srt the string to pass to the server.
     */
    void writeStringToServer(char* srt);

    /**
     * @return the server port.
     */
    int getServerPort() const;

    /**
     * @return the number of the player.
     */
    int getLocalPNum() const;

    /**
     * @return the server ip.
     */
    const char *getServerIP() const;

    /**
     * @return the socket number.
     */
    int getClientSocket() const;


    /**
     * get the palyer's number.
     * @return the number (1 or -1)
     */
    int readPlayerNumFromServer();


    /**
    * the method to end it all! will write to the socket that the game is over.
    */
    void endGame();

private:
    /**
     * the server's ip.
     */
    const char *serverIP;

    /**
     * the port of the server.
     */
    int serverPort;

    /**
     * the socket of the client
     */
    int clientSocket;

    /**
     * the players number.
     */
    int localPNum;
public:
    void setLocalPNum(int localPNum);
};

#endif //REVERSI_CLIENT_H