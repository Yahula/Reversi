//
// Created by Yahel Ben ishay on 11/28/17.
//

#include "../gtest_src/gtest.h"

using namespace std;


TEST(BasicTests, TestThatWillWork) {
    vector<int> x(2);
    vector<int> y(2);
    x[0] = 1;
    x[1] = 2;
    y[0] = 1;
    y[1] = 2;
    ASSERT_EQ(x.size(), y.size()) << "Vectors x and y are of unequal length";
    for (unsigned i = 0; i < x.size(); ++i) {
        EXPECT_EQ(x[i], y[i]) << "Vectors x and y differ at index " << i;
    }
}

