#include "../include/sonar_processing.h"
#include <bits/stdc++.h>

SonarProcess::SonarProcess(const int& window_size):window_size{window_size}{}

float SonarProcess::MovingAvg(const float& raw_measurement)
{
    if(moving_avg_window.size()==window_size)
    {
        moving_avg_window.pop_front();
    }
    moving_avg_window.push_back(raw_measurement);

    return (float)std::accumulate(moving_avg_window.begin(),moving_avg_window.end(),0.0)/(float) moving_avg_window.size();
}