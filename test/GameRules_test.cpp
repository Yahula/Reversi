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

    void emptyBoard(){
        Disk temp;

        //empty the board
        temp.setRow(3);
        temp.setCol(3);
        temp.setPlayer(0);
        b->setCell(temp);

        temp.setRow(4);
        temp.setCol(4);
        temp.setPlayer(0);
        b->setCell(temp);

        temp.setRow(3);
        temp.setCol(4);
        temp.setPlayer(0);
        b->setCell(temp);

        temp.setRow(4);
        temp.setCol(3);
        temp.setPlayer(0);
        b->setCell(temp);
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

TEST_F(GameRules_test, CP_oneMove)  {
    b->initialBoard();
    Disk temp;

    emptyBoard();

    //O on top
    temp.setRow(0);
    temp.setCol(1);
    temp.setPlayer(1);
    b->setCell(temp);

    //X underneath O
    temp.setRow(1);
    temp.setCol(1);
    temp.setPlayer(-1);
    b->setCell(temp);

    EXPECT_TRUE(rules->canPlay(b,p))<<"can play is not good";
}

TEST_F(GameRules_test, CP_XOnlyOnBoard)  {
    b->initialBoard();
    Disk temp;

    //change O default places to X
    temp.setRow(3);
    temp.setCol(3);
    temp.setPlayer(-1);
    b->setCell(temp);

    temp.setRow(4);
    temp.setCol(4);
    temp.setPlayer(-1);
    b->setCell(temp);
    EXPECT_FALSE(rules->canPlay(b,p))<<"canPlay function is not good";

}

TEST_F(GameRules_test, CP_noMoves)  {
    b->initialBoard();
    Disk temp;

    emptyBoard();

    //X on top
    temp.setRow(0);
    temp.setCol(1);
    temp.setPlayer(-1);
    b->setCell(temp);

    //O underneath X
    temp.setRow(1);
    temp.setCol(1);
    temp.setPlayer(1);
    b->setCell(temp);

    EXPECT_FALSE(rules->canPlay(b,p))<<"can play is not good";
}

TEST_F(GameRules_test, CP_emptyBoard)  {
    b->initialBoard();

    emptyBoard();

    EXPECT_FALSE(rules->canPlay(b,p))<<"canPlay function is not good";

}

/**
 * Play Function test
 */

//on all tests below O player attampts to play
TEST_F(GameRules_test, P_regularBoard)  {
    b->initialBoard();

    EXPECT_TRUE(rules->play(b,new Disk(5,3,1)))<<"Play function is not good - regular check";
}

TEST_F(GameRules_test, P_oneMoves)  {
    b->initialBoard();
    Disk temp;

    emptyBoard();

    //O on top
    temp.setRow(0);
    temp.setCol(1);
    temp.setPlayer(1);
    b->setCell(temp);

    //X underneath O
    temp.setRow(1);
    temp.setCol(1);
    temp.setPlayer(-1);
    b->setCell(temp);

    EXPECT_TRUE(rules->play(b,new Disk(2,1,1)))<<"Play function is not good - one move check";
}

TEST_F(GameRules_test, P_nonValidMove)  {
    b->initialBoard();

    EXPECT_FALSE(rules->play(b,new Disk(5,4,1)))<<"Play function is not good - non valid test";

}

TEST_F(GameRules_test, P_emptyAreaMove)  {
    b->initialBoard();

    EXPECT_FALSE(rules->play(b,new Disk(2,2,1)))<<"Play function is not good - empty area";
}

TEST_F(GameRules_test, P_takenPos)  {
    b->initialBoard();

    EXPECT_FALSE(rules->play(b,new Disk(4,3,1)))<<" Play function is not good - place already taken";
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
    Disk temp;
    temp.setPlayer(1);

    for (int i=0; i<8; i++){
        for (int j=0; j<8; j++) {
            temp.setRow(i);
            temp.setCol(j);
            b->setCell(temp);
        }
    }
    EXPECT_TRUE(rules->isBoardFull(b))<<"isBoardFull function is not good - full board";
}
