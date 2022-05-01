#include "pch.h"
#include <queue>
#include "CppUnitTest.h"
#include "../Luna.Tools/CsvIoStream.cpp"
#include "../Luna.Tools/Utils.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CsvReaderTest
{
	TEST_CLASS(CsvReaderTest)
	{
	public:

		TEST_METHOD(ShortTest)
		{
			CsvReader reader = CsvReader("D:/c++/Luna.Tools/CsvReaderTest/Resources/Short.csv");
			queue<wstring> expected;
			expected.push(LR"(¤¡¤¡¤¿¤¡¤¡¤¿)"s);
			expected.push(LR"(¤¡¤¡¤¿¤¡¤¡¤Ì)"s);
			expected.push(LR"(¤¡¤¡¤¿¤¡¤¡¤Ó)"s);
			expected.push(LR"(¤¡¤¡¤¿¤¡¤§¤Ó)"s);
			expected.push(LR"(¤¡¤¡¤¿¤¡¤µ¤Ó)"s);
			expected.push(LR"(¤¡¤¡¤¿¤¡¤¸¤Ó)"s);

			queue<wstring> q;

			for (int i = 0; i < expected.size(); i++)
			{
				q.push(reader.readNext2());
			}

			while (!expected.empty())
			{
				Assert::AreEqual(peekAndPop(expected), peekAndPop(q));
			}
		
		}

		TEST_METHOD(LongTest)
		{
			CsvReader reader = CsvReader("D:/c++/Luna.Tools/CsvReaderTest/Resources/Long.csv");
			queue<wstring> expected;
			expected.push(LR"(¤¡¤¡¤¿¤¡¤¡¤¿)"s);
			expected.push(LR"(¤¡¤¡¤¿¤¡¤¡¤Ì)"s);
			expected.push(LR"(¤¡¤¡¤¿¤¡¤¡¤Ó)"s);
			expected.push(LR"(¤¡¤¡¤¿¤¡¤§¤Ó)"s);
			expected.push(LR"(¤¡¤¡¤¿¤¡¤µ¤Ó)"s);
			expected.push(LR"(¤¡¤¡¤¿¤¡¤¸¤Ó)"s);
			expected.push(LR"(¤¡¤¡¤¿¤¡¤Å¤¡)"s);
			expected.push(LR"(¤¡¤¡¤¿¤¤¤¤¤¿)"s);
			expected.push(LR"(¤¡¤¡¤¿¤¤¤²¤Ó)"s);
			expected.push(LR"(¤¡¤¡¤¿¤¤¤º¤Ó)"s);
			expected.push(LR"(¤¡¤¡¤¿¤¤¤¿¤©)"s);
			expected.push(LR"(¤¡¤¡¤¿¤¤¤¿¤±)"s);
			expected.push(LR"(¤¡¤¡¤¿¤¤¤Ç¤¤)"s);
			expected.push(LR"(¤¡¤¡¤¿¤§¤¿¤¡)"s);

			queue<wstring> q;

			for (int i = 0; i < expected.size(); i++)
			{
				q.push(reader.readNext2());
			}

			while (!expected.empty())
			{
				Assert::AreEqual(peekAndPop(expected), peekAndPop(q));
			}

		}

		TEST_METHOD(EmptyTest)
		{
			CsvReader reader = CsvReader("D:/c++/Luna.Tools/CsvReaderTest/Resources/Empty.csv");
			queue<wstring> expected;
			expected.push(LR"()"s);

			queue<wstring> q;

			for (int i = 0; i < expected.size(); i++)
			{
				q.push(reader.readNext2());
			}

			while (!expected.empty())
			{
				Assert::AreEqual(peekAndPop(expected), peekAndPop(q));
			}
		}
	};
}
