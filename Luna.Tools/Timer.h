#pragma once
#include <chrono>
#include <vector>

using namespace std;

class Timer
{
private:
	chrono::steady_clock::time_point startedTime;
	vector<chrono::nanoseconds> checkpoints;

	chrono::steady_clock::time_point pausedTime;
	chrono::nanoseconds totalPaused;
	bool bPaused;

public:
	Timer();

	void resume();
	void pause();
	void resetTime();
	chrono::nanoseconds check();
	chrono::nanoseconds getDuration();

	vector<chrono::nanoseconds> getCheckpoints();
};
