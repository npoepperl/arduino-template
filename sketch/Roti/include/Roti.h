class Roti{
public:
    Roti();
    ~Roti();

    void Initialize();

    float CurrentAverage();

    void RatedOne();
    void RatedTwo();

    char CountRatedOne();
    char CountRatedTwo();

private:

    char ratedOne;

    char ratedTwo;

    short ratingsSubmitted;

    float CurrentTotalRating();
};

