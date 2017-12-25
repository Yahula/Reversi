//
// Created by Yahel Ben ishay on 11/28/17.
//

#include "../gtest_src/gtest/gtest.h"
#include "../include/Reversi_I.h"
#include "../include/Console.h"
#include "../include/AI_Player.h"

class AI_test: public testing::Test{
public:
    AI_test() {
        b = new Console();
        g = new Reversi_I();
        p = new AI_Player(1,g,b);
    }

protected:
    virtual void SetUp(){
        cout << "Setting up" << endl;
    }
    virtual void TearDown(){
        cout << "Tearing down" << endl;
    }
    Board* b;
    GameRules* g;
    Player* p;
};


/**
 * Move function tests
 */

TEST_F(AI_test, regualarCheck)  {
    Disk temp;

    temp.setRow(3);
    temp.setCol(3);
    temp.setPlayer(0);
    b->setCell(temp);

    temp.setRow(4);
    temp.setCol(4);
    temp.setPlayer(-1);
    b->setCell(temp);

    temp.setRow(4);
    temp.setCol(5);
    temp.setPlayer(-1);
    b->setCell(temp);

    temp.setRow(5);
    temp.setCol(5);
    temp.setPlayer(1);
    b->setCell(temp);

    temp.setRow(6);
    temp.setCol(5);
    temp.setPlayer(1);
    b->setCell(temp);

    g->setScore(2,4);

    Disk move(p->move());

    EXPECT_EQ(move.getRow(),3);
    EXPECT_EQ(move.getCol(),5);

    EXPECT_NE(move.getCol(),3);
    EXPECT_NE(move.getCol(),3);

}
