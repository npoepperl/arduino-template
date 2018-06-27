#include "gtest/gtest.h"
#include "Board.h"

class BoardTests : public ::testing::Test {

protected:
    BoardTests(){

    }

    virtual ~BoardTests(){

    }

private:
    Board* board;
};


TEST_F(BoardTests, SomeDumbNothingTest){
    ASSERT_EQ(true, false);
}