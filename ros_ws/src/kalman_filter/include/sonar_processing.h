#ifndef SONAR_PROCESSING
#define SONAR_PROCESSING

#include <deque>

class SonarProcess
{
    public:
        SonarProcess(const int& window_size);
        float MovingAvg(const float& raw_measurement);
    private:
        int window_size;
        std::deque<float> moving_avg_window;
};

#endif