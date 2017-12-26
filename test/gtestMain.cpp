//
// Created by Yahel Ben ishay on 11/28/17.
//

#include "../gtest_src/gtest/gtest.h"

int gmain(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
