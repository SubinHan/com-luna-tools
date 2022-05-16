#include "pch.h"
#include <queue>
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace CommandParserTest
{
	TEST_CLASS(CommandParserTest)
	{
	public:
		TEST_METHOD(EmptyTest)
		{
			string test = "";
			CommandParser parser(test);
			bool flag = parser.getFlag("something");
			string* args = parser.getArgs("something");
			Assert::IsTrue(!flag);
			Assert::IsTrue(args->size() == 0);
		}

		TEST_METHOD(OptionTest)
		{
			string test = "-o abc";
			CommandParser parser(test);
			bool flag = parser.getFlag("abc");
			Assert::IsTrue(!flag);
			string* args = parser.getArgs("o");
			Assert::IsTrue(args->size() == 1);
			Assert::AreEqual(args[0], "abc");
		}


	};
}