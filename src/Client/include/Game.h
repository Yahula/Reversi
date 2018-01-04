/*
 * Game.h
 * Yahel Ben-Ishay
 * 305016297
 */

#ifndef GAME_H_
#define GAME_H_
#include "HumanPlayer.h"
#include "Console.h"
#include "Reversi_I.h"
#include "AI_Player.h"
#include "RemotePlayer.h"
#include <vector>



/**
 * The Game class is the manager of our game
 */
class Game {
public:
	/**
	 * constructor
	 */
	Game(int player);
	/**
	 * destructor
	 */
	virtual ~Game();

	/**
	 * playGame Method
	 * Runs the game, verifies each player has moves and if the board is full or not.
	 * calls all relevant functions and objects in order to run the game
	 */
	void playGame();


	/**
	 * this method make one move for one player.
	 * @param player the player that will make the move.
	 * @return rather he moved or not - 0 if he did, 1 if he didn't, 2 if they both did not move.
	 */
	int playerPlay(Player* player);

    /**
     * true if it is the first turn.
     */
    bool firstTurn;

private:
	/**
	 * The game board
	 */
	Board *myboard;

	/**
	 * The rules of the game
	 */
	GameRules *gameRules;

    /**
     * if its a remoth game this will be the client.
	*/
    Client *client;

    /**
     * a vector of the players and their type.
    */
	vector <Player*> players;

    /**
     * true if the game will be played through a server.
     */
	bool isRemoteGame;



    /*
     * a flag that will sign the end of the game.
     */
    int endFlag;

};

#endif /* GAME_H_ */
