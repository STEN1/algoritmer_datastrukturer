#pragma once

#include <string>
#include <iostream>
#include <chrono>

class Timer
{
public:
    Timer(std::string tname = "", double* outCumulativeTime = nullptr)
        :start_count(std::chrono::high_resolution_clock::now())
        ,timer_name(tname)
        ,m_outCumulativeTime(outCumulativeTime)
    {
    }
    ~Timer()
    {
        auto end_count = std::chrono::high_resolution_clock::now();

        auto start = std::chrono::time_point_cast<std::chrono::nanoseconds>(start_count).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::nanoseconds>(end_count).time_since_epoch().count();

        auto duration = (end - start) * 0.000000001; // convert to seconds
        if (m_outCumulativeTime)
        {
            (*m_outCumulativeTime) += duration;
        }
        std::cout << timer_name << " timer: " << duration << "s" << std::endl;
    }
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_count;
    std::string timer_name;
    double* m_outCumulativeTime;
};