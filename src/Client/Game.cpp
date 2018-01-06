/*
 * Game.cpp
 */

#include <fstream>
#include <sstream>
#include "./include/Game.h"

Game::Game(int player) {
	myboard = new Console();
	gameRules = new Reversi_I();
    firstTurn = true;
    endFlag = 0;
    isRemoteGame = false;

    if (player == 1) {
        players.push_back(new HumanPlayer(-1));
        players.push_back(new AI_Player(1, gameRules, myboard));
	}
	if (player == 2) {
        players.push_back(new HumanPlayer(-1));
        players.push_back(new HumanPlayer(1));
	}
	if (player == 3) {
        isRemoteGame = true;
        handleRemoteGame();
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
    myboard->displayBoard();

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

void Game::handleRemoteGame() {
    //read config from file
    ifstream cconfig;
    cconfig.open("../../exe/client_config.txt");
    string ipnum;
    getline(cconfig, ipnum);
    char* ip = new char[ipnum.length()+1];
    strcpy(ip,ipnum.c_str());

    string p;
    getline(cconfig, p);
    int port;
    istringstream(p) >> port ;

    //get from server who's first
    client = new Client("127.0.0.1", 5001);
    if (client->getLocalPNum() == 1){
        players.push_back(new RemotePlayer(client, -1));
        players[0]->setIsRemote(true);
        players.push_back(new HumanPlayer(1));
    }
    else{
        players.push_back(new HumanPlayer(-1));
        players.push_back(new RemotePlayer(this->client, 1));
        players[1]->setIsRemote(true);
    }

    //join or create a new game?
    cout<<"Please select: "<<endl<<"1 - New Remote Game"<<endl<<"2 - Join an Existing Game"<<endl;
    int type;
    cin>>type;
    if (type == 1){
        string s1 = "start ";
        string s2;

        cout<<"Please type name of game: "<<endl;
        cin>>s2;
        string s3 = s1+s2;

        char *command = new char[s3.length() + 1];
        strcpy(command, s3.c_str());
        client->writeStringToServer(command);

        delete[] command;

    }
    if (type == 2){
        client->writeStringToServer("list_games");
        cout<<"Please select Game to Join: "<<endl;
        client->readStringFromServer();

        string s1 = "join ";
        string s2;
        cin>>s2;
        string s3 = s1+s2;

        char *command = new char[s3.length() + 1];
        strcpy(command, s3.c_str());

        client->writeStringToServer(command);
        delete[] command;
    }
}