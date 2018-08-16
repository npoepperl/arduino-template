#include "gtest/gtest.h"
#include "Roti.h"

class RotiTests : public ::testing::Test {

protected:
    RotiTests(){
        roti = new Roti();
    }

    virtual ~RotiTests(){
        delete roti;
    }

public:
    Roti* roti;
};

TEST_F(RotiTests, InitializingRotiResultsInZeroAverage){
    this->roti->Initialize();
    ASSERT_EQ((float)0.0, roti->CurrentAverage());
}

TEST_F(RotiTests, NewRotiAfterPushingRatingTwoResultsInCountRatedTwoEquals1){
    this->roti->Initialize();
    this->roti->RatedTwo();
    ASSERT_EQ(1, roti->CountRatedTwo());
}

TEST_F(RotiTests, NewRotiAfterPushingRatingTwoTwiceResultsInCountRatedTwoEquals2){
    this->roti->Initialize();
    this->roti->RatedTwo();
    this->roti->RatedTwo();
    ASSERT_EQ(2, roti->CountRatedTwo());
}

TEST_F(RotiTests, NewRotiAfterPushingRatingTwoTwiceResultsInAverage2){
    this->roti->Initialize();
    this->roti->RatedTwo();
    this->roti->RatedTwo();
    ASSERT_EQ(2, roti->CurrentAverage());
}

TEST_F(RotiTests, NewRotiAfterPushingRatingOneResultsInCountRatedOneEquals1){
    this->roti->Initialize();
    this->roti->RatedOne();
    ASSERT_EQ(1, roti->CountRatedOne());
}

TEST_F(RotiTests, NewRotiAfterPushingRatingOneTwiceResultsInCountRatedOneEquals2){
    this->roti->Initialize();
    this->roti->RatedOne();
    this->roti->RatedOne();
    ASSERT_EQ(2, roti->CountRatedOne());
}

TEST_F(RotiTests, NewRotiAfterPushingRatingOneTwiceResultsInAverage1){
    this->roti->Initialize();
    this->roti->RatedOne();
    this->roti->RatedOne();
    ASSERT_EQ(1, roti->CurrentAverage());
}

