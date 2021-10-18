#pragma once

#include <string>
#include <iostream>
#include <chrono>

class Timer
{
public:
    Timer() : start(std::chrono::high_resolution_clock::now()) {}
    inline double Stop()
    {
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> duration = end-start;
        return duration.count();
    }
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
};