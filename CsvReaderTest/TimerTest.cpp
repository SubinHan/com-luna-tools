#include "pch.h"
#include "CppUnitTest.h"
#include "../Luna.Tools/Timer.cpp"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace TimerTest
{
	TEST_CLASS(TimerTest)
	{
	public:

		TEST_METHOD(SimpleTest)
		{
			Timer timer;
			Logger::WriteMessage(("timer1: " + to_string(timer.check().count())).c_str());
			Logger::WriteMessage(("timer1: " + to_string(timer.check().count())).c_str());
			timer.pause();
			Logger::WriteMessage(("timer1: " + to_string(timer.check().count())).c_str());
			Timer timer2;
			Logger::WriteMessage(("timer2: " + to_string(timer2.check().count())).c_str());
			for (int i = 0; i < 10000000; i++)
			{
				timer2.resume();
			}
			Logger::WriteMessage(("timer2: " + to_string(timer2.check().count())).c_str());
			Logger::WriteMessage(("timer2: " + to_string(timer2.check().count())).c_str());
			timer.resume();
			Logger::WriteMessage(("timer1: " + to_string(timer.check().count())).c_str());
			timer.getCheckpoints();
			Logger::WriteMessage(("timer1: " + to_string(timer.check().count())).c_str());
			Logger::WriteMessage(("timer1: " + to_string(timer.getDuration().count())).c_str());
			timer.resetTime();
			Logger::WriteMessage(("timer1: " + to_string(timer.check().count())).c_str());
			Logger::WriteMessage(("timer1: " + to_string(timer.check().count())).c_str());
			Logger::WriteMessage(("timer1: " + to_string(timer.getDuration().count())).c_str());
		}


	};
}