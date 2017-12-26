/*
 * Game.cpp
 */

#include <fstream>
#include <sstream>
#include "../../include/Game.h"

Game::Game(int player) {
	this->myboard = new Console();
	this->myboard->displayBoard();
	this->gameRules = new Reversi_I();
    this->firstTurn = true;
    this->endFlag = 0;

    if (player == 1) {
        this->isRemoteGame = false;
        this->players.push_back(new HumanPlayer(-1));
        this->players.push_back(new AI_Player(1, this->gameRules, this->myboard));
	}
	if (player == 2) {
        this->isRemoteGame = false;
        this->players.push_back(new HumanPlayer(-1));
        this->players.push_back(new HumanPlayer(1));
	}
	if (player == 3) {
        this->isRemoteGame = true;
        ifstream cconfig;
        cconfig.open("../../exe/client_config.txt");
        string ip;
        getline(cconfig, ip);
        string port;
        getline(cconfig, port);
        istringstream is(port);
        is>>port;

        this->client = new Client("127.0.0.1", 5001);
		if (this->client->getLocalPNum() == 1){
            this->players.push_back(new RemotePlayer(this->client, -1));
			this->players[0]->setIsRemote(true);
            this->players.push_back(new HumanPlayer(1));
		}
		else{
            this->players.push_back(new HumanPlayer(-1));
            this->players.push_back(new RemotePlayer(this->client, 1));
            this->players[1]->setIsRemote(true);
		}
	}

}

Game::~Game() {
	delete (myboard);
	delete (gameRules);
    delete (players[0]);
    delete (players[1]);
    if(isRemoteGame){
        delete(client);
    }
}

void Game::playGame() {
    int player = 0;
    int noMoves = 0;
    while (true) {
        if (gameRules->isBoardFull(myboard)) {
            cout << "Board Full. Game Over!" << endl;
            break;
        } else {
            int n = playerPlay(this->players[player]);
            player = (player + 1) % 2;

            if (n==0) {
                noMoves = 0;
            } else if (n==1) {
                noMoves++;
                if (noMoves == 1) {
                    continue;
                }
                if (noMoves == 2) {
                    cout << "Game Over" << endl;
                    break;
                }

            } else if(n==2){
                this->client->readFromServer();
                return;
            }
        }
    }
}

int Game::playerPlay(Player* player) {
    Disk *d;

    if (this->gameRules->canPlay(myboard, player)) {
        bool thereWasAMove;

        d = new Disk(player->move());

        thereWasAMove = this->gameRules->play(myboard, d);
        while (!thereWasAMove) {
            cout << "oops! not there! try agian: " << endl;
            d = new Disk(player->move());
            thereWasAMove = this->gameRules->play(myboard, d);
        }
        if (this->isRemoteGame &&!player->getIsRemote()) {
            this->client->writeToServer(d);
        }
        cout << endl << "Score - " << "White (O): " << this->gameRules->getScore()[0] << ", Black (X): "
             << this->gameRules->getScore()[1] << endl << endl;
        this->myboard->displayBoard();
        this->endFlag = 0;
        return 0;
    } else {
        if (this->isRemoteGame){
            if(endFlag){
                return 2;
            }
            if(!player->getIsRemote()) {
                char m[] = "nmv";
                this->client->writeStringToServer(m);
                this->endFlag = 1;
            }else{
                this->client->readFromServer();
            }
            return 0;

        } else {
            cout << "No moves!" << endl;
            return 1;
        }
    }
    delete (d);
}