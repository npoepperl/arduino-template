#include "include/Roti.h"

Roti::Roti(){
}

Roti::~Roti(){

}

void Roti::Initialize(){
    this->ratedOne = 0;
    this->ratedTwo = 0;
    this->ratingsSubmitted = 0;
}

float Roti::CurrentAverage(){
    if(this->ratingsSubmitted != 0){
        return CurrentTotalRating() / ratingsSubmitted;
    }

    return (float)0.0;
}

float Roti::CurrentTotalRating(){
    return (ratedTwo * 2) 
            + ratedOne;
}

void Roti::RatedOne(){
    this->ratingsSubmitted ++;
    this->ratedOne ++;
}

void Roti::RatedTwo(){
    this->ratingsSubmitted ++;
    this->ratedTwo ++;
}

char Roti::CountRatedOne(){
    return ratedOne;
}

char Roti::CountRatedTwo(){
    return ratedTwo;
}
