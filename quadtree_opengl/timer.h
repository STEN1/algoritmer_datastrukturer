#pragma once
#include <chrono>


class Timer
{
public:
	Timer()
		:start_count(std::chrono::high_resolution_clock::now())
	{
	}

	double GetDelta()
	{
		auto end_count = std::chrono::high_resolution_clock::now();

		auto start = std::chrono::time_point_cast<std::chrono::nanoseconds>(start_count).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::nanoseconds>(end_count).time_since_epoch().count();

		auto duration = (end - start) * 0.000000001; // convert to seconds

		return duration;
	}

	double GetDeltaAndSetStartCountNow()
	{
		auto end_count = std::chrono::high_resolution_clock::now();

		auto start = std::chrono::time_point_cast<std::chrono::nanoseconds>(start_count).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::nanoseconds>(end_count).time_since_epoch().count();

		auto duration = (end - start) * 0.000000001; // convert to seconds

		start_count = end_count;
		return duration;
	}

private:
	std::chrono::time_point<std::chrono::high_resolution_clock> start_count;
};