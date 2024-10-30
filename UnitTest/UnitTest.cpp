#include "pch.h"
#include "CppUnitTest.h"
#include "../pr_08_1_it/pr_08_1_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestContainsWhileLetters)
		{
			Assert::IsTrue(ContainsWhileLetters("hello, while!"));
			Assert::IsFalse(ContainsWhileLetters("whi"));
			Assert::IsFalse(ContainsWhileLetters("hello, hwo!"));
		}

		TEST_METHOD(TestReplaceWhile_MultipleOccurrences)
		{
			char str[] = "while x";
			char* result = ReplaceWhile(str);
			Assert::AreEqual("** x", result);
			delete[] result;
		}

	};
}

