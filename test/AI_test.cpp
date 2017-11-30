//
// Created by Yahel Ben ishay on 11/28/17.
//

#include "../gtest_src/googletest-release-1.8.0/googletest/include/gtest/gtest.h"
#include "../include/Reversi_I.h"
#include "../include/Console.h"
#include "../include/AI_Player.h"

class AI_test: public testing::Test{
public:
    AI_test() {
        b = new Console();
        g = new Reversi_I();
        p = new AI_Player();
    }

protected:
    virtual void SetUp(){
        cout << "Setting up" << endl;
    }
    virtual void TearDown(){
        cout << "Tearing down" << endl;
    }
    Board* b;
    GameRulaes* g;
    Player* p;
};


/**
 * Move function tests
 */

TEST_F(GameRules_test, regualarCheck)  {
    b->setCell(new Disk(4,4,0));
    b->setCell(new Disk(5,5,-1));
    b->setCell(new Disk(5,6,-1));
    b->setCell(new Disk(6,6,1));
    b->setCell(new Disk(7,6,1));
    g->setScore(2,4);

    EXPECT_EQ(p->move(),new Disk (4,6,-1));
    EXPECT_NE(p->move(),new Disk (4,4,-1));
}
