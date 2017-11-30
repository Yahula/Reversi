//
// Created by Yahel Ben ishay on 11/28/17.
//

#include "../gtest_src/googletest-master/googletest/include/gtest/gtest.h"
#include "../include/Reversi_I.h"
#include "../include/Console.h"
#include "../include/HumanPlayer.h"

class GameRules_test: public testing::Test{
public:
    GameRules_test() {
        rules = new Reversi_I();
        b = new Console();
        p = new HumanPlayer(1);
    }

protected:
    virtual void SetUp(){
        cout << "Setting up" << endl;

        b->setCell(new Disk(4,4,-1));
        b->setCell(new Disk(6,6,-1));
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


TEST_F(GameRules_test, ImpossibleToPlay)  {

    EXPECT_FALSE(rules->canPlay(b,p));

}



