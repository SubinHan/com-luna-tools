#include "pch.h"
#include <queue>
#include "CppUnitTest.h"
#include "../Luna.Tools/CommandParser.cpp"

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
			string command = parser.getCommand();

			Assert::IsTrue(!flag);
			Assert::IsTrue(args->size() == 0);
			Assert::IsTrue(command.compare("") == 0);
		}
		TEST_METHOD(SimpleTest)
		{
			string test = "command";
			CommandParser parser(test);
			bool flag = parser.getFlag("something");
			string* args = parser.getArgs("something");
			string command = parser.getCommand();

			Assert::IsTrue(command.compare("command") == 0);
			Assert::IsTrue(!flag);
			Assert::IsTrue(args->size() == 0);
		}

		TEST_METHOD(ArgsOptionTest)
		{
			string test = "command -o abc";
			CommandParser parser(test);
			bool flag = parser.getFlag("abc");
			string* args = parser.getArgs("o");
			string command = parser.getCommand();

			Assert::IsTrue(command.compare("command") == 0);
			Assert::IsTrue(!flag);
			Assert::IsTrue(args->size() == 1);
			Assert::IsTrue(args[0].compare("abc") == 0);
		}

		TEST_METHOD(FlagOptionTest)
		{
			string test = "command -flag";
			CommandParser parser(test);
			bool flag = parser.getFlag("flag");
			string* args = parser.getArgs("something");
			string command = parser.getCommand();

			Assert::IsTrue(command.compare("command") == 0);
			Assert::IsTrue(flag);
			Assert::IsTrue(args->size() == 0);
		}

		TEST_METHOD(CompoundTest)
		{
			string test = "command -flag1 -o abc -flag2 -c hello world";
			CommandParser parser(test);
			bool flag1 = parser.getFlag("flag1");
			bool flag2 = parser.getFlag("flag2");
			bool flag3 = parser.getFlag("flag3");
			string* oargs = parser.getArgs("o");
			string* cargs = parser.getArgs("c");
			string* xargs = parser.getArgs("x");
			string command = parser.getCommand();

			Assert::IsTrue(command.compare("command") == 0);
			Assert::IsTrue(flag1);
			Assert::IsTrue(flag2);
			Assert::IsTrue(!flag3);
			Assert::IsTrue(oargs->size() == 1);
			Assert::IsTrue(cargs->size() == 2);
			Assert::IsTrue(xargs->size() == 0);
			Assert::IsTrue(oargs[0].compare("abc") == 0);
			Assert::IsTrue(cargs[0].compare("hello") == 0);
			Assert::IsTrue(cargs[1].compare("world") == 0);
		}

	};
}