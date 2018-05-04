#include "gtest/gtest.h"

class BoardTests : public ::testing::Test {

protected:
    BoardTests(){

    }

    virtual ~BoardTests(){

    }
};


TEST_F(BoardTests, SomeDumbNothingTest){
    ASSERT_EQ(true, false);
}