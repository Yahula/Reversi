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

	int playerPlay(Player* player);

	void handleRemoteGame();

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

	Client *client;

	vector <Player*> players;

	bool isRemoteGame;

    int endFlag;

};

#endif /* GAME_H_ */
