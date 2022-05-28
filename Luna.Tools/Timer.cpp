#include "Timer.h"
#include <string>
#include <iostream>

using namespace std;

Timer::Timer() 
{
	startedTime = chrono::high_resolution_clock::now();
	totalPaused = {};
	bPaused = false;
}

void Timer::resume()
{
	if (bPaused)
	{
		bPaused = false;
		totalPaused += chrono::high_resolution_clock::now() - pausedTime;
		pausedTime = {};
	}
}

void Timer::pause()
{
	if (!bPaused)
	{
		pausedTime = chrono::high_resolution_clock::now();
		bPaused = true;
	}
}

void Timer::resetTime()
{
	startedTime = chrono::high_resolution_clock::now();
	totalPaused = {};
}

chrono::nanoseconds Timer::check()
{
	if (bPaused) 
	{
		auto result = pausedTime - startedTime;
		checkpoints.push_back(result);
		return result;
	}
	auto result = chrono::high_resolution_clock::now() - startedTime - totalPaused;
	checkpoints.push_back(result);
	return result;
}

chrono::nanoseconds Timer::getDuration()
{
	return chrono::high_resolution_clock::now() - startedTime - totalPaused;
}

vector<chrono::nanoseconds> Timer::getCheckpoints()
{
	return checkpoints;
}
