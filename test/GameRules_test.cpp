//
// Created by Yahel Ben ishay on 11/28/17.
//

#include "../gtest_src/gtest/gtest.h"
#include "../include/Reversi_I.h"
#include "../include/Console.h"
#include "../include/HumanPlayer.h"

class GameRules_test: public testing::Test{
public:
    GameRules_test() {
    }

protected:
    virtual void SetUp(){
        cout << "Setting up" << endl;
        rules = new Reversi_I();
        b = new Console();
        p = new HumanPlayer(1);
    }
    virtual void TearDown(){
        cout << "Tearing down" << endl;
        delete b;
        delete p;
        delete rules;
    }

    GameRules *rules;
    Board *b;
    Player *p;
};


/**
 * CanPlay function tests
 */

//on all tests below O player attampts to play
TEST_F(GameRules_test, CP_regularBoard)  {
    EXPECT_TRUE(rules->canPlay(b,p))<<"canPlay function is not good";
}

TEST_F(GameRules_test, CP_oneMoves)  {
    b->initialBoard();
    //empty the board
    b->setCell(new Disk(4,4,0));
    b->setCell(new Disk(5,5,0));
    b->setCell(new Disk(4,5,0));
    b->setCell(new Disk(5,4,0));

    //O on top
    b->setCell(new Disk(1,2,1));

    //X underneath O
    b->setCell(new Disk(2,2,-1));

    EXPECT_TRUE(rules->canPlay(b,p))<<"can play is not good";
}

TEST_F(GameRules_test, CP_XOnlyOnBoard)  {
    b->initialBoard();

    //change O default places to X
    b->setCell(new Disk(4,4,-1));
    b->setCell(new Disk(5,5,-1));
    EXPECT_FALSE(rules->canPlay(b,p))<<"canPlay function is not good";

}

TEST_F(GameRules_test, CP_noMoves)  {
    b->initialBoard();

    //empty the board
    b->setCell(new Disk(4,4,0));
    b->setCell(new Disk(5,5,0));
    b->setCell(new Disk(4,5,0));
    b->setCell(new Disk(5,4,0));

    //X on top
    b->setCell(new Disk(1,2,-1));

    //O underneath X
    b->setCell(new Disk(2,2,1));

    EXPECT_FALSE(rules->canPlay(b,p))<<"can play is not good";
}

TEST_F(GameRules_test, CP_emptyBoard)  {
    b->initialBoard();

    //empty the board
    b->setCell(new Disk(4,4,0));
    b->setCell(new Disk(5,5,0));
    b->setCell(new Disk(4,5,0));
    b->setCell(new Disk(5,4,0));
    EXPECT_FALSE(rules->canPlay(b,p))<<"canPlay function is not good";

}

/**
 * Play Function test
 */

//on all tests below O player attampts to play
TEST_F(GameRules_test, P_regularBoard)  {
    b->initialBoard();
    EXPECT_TRUE(rules->play(b,new Disk(6,4,1)))<<"Play function is not good - regular check";
}

TEST_F(GameRules_test, P_oneMoves)  {
    b->initialBoard();

    //empty the board
    b->setCell(new Disk(4,4,0));
    b->setCell(new Disk(5,5,0));
    b->setCell(new Disk(4,5,0));
    b->setCell(new Disk(5,4,0));

    //O on top
    b->setCell(new Disk(1,2,1));

    //X underneath O
    b->setCell(new Disk(2,2,-1));

    EXPECT_TRUE(rules->play(b,new Disk(2,3,1)))<<"Play function is not good - one move check";
}

TEST_F(GameRules_test, P_nonValidMove)  {
    b->initialBoard();

    EXPECT_FALSE(rules->play(b,new Disk(6,5,1)))<<"Play function is not good - non valid test";

}

TEST_F(GameRules_test, P_emptyAreaMove)  {
    b->initialBoard();

    EXPECT_FALSE(rules->play(b,new Disk(2,2,1)))<<"Play function is not good - empty area";
}

TEST_F(GameRules_test, P_takenPos)  {
    b->initialBoard();

    EXPECT_FALSE(rules->play(b,new Disk(5,4,1)))<<" Play function is not good - place already taken";
}

/**
 * isBoardFull function test
 */

TEST_F(GameRules_test, IBF_regularBoard)  {
    b->initialBoard();

    EXPECT_FALSE(rules->isBoardFull(b))<<"isBoardFull function is not good - regular";
}


TEST_F(GameRules_test, IBF_fullBoard)  {
    b->initialBoard();

    for (int i=1; i<9; i++){
        for (int j=1; j<9; j++) {
            b->setCell(new Disk(i,j,1));
        }
    }
    EXPECT_TRUE(rules->isBoardFull(b))<<"isBoardFull function is not good - full board";
}
