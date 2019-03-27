#include "TestCase.h"

#include <vector>
#include <iostream>

#if _WIN32
#include <windows.h>
#endif

std::vector<TestCase*>* TestCaseList;

static void AddTestCase(TestCase* testCase)
{
	if (!TestCaseList)
		TestCaseList = new std::vector<TestCase*>();

	TestCaseList->push_back(testCase);
}

TestCase::TestCase(const std::string& name)
	: Name(name)
{
	AddTestCase(this);
}

void TestCase::assertTest(bool bValue, const char* message, const char* filename, int line)
{
	if (bValue)
		std::cout << message << " assert ok!" << std::endl;
	else
	{
#if _WIN32
		HANDLE hdl = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hdl, FOREGROUND_RED | FOREGROUND_INTENSITY);
#endif

		std::cout << filename << "(" << line << "): " << message << " assert failed!" << std::endl;

#if _WIN32
		SetConsoleTextAttribute(hdl, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#endif
	}
}

size_t UnitTestCount()
{
	return TestCaseList->size();
}

TestCase* GetTestCase(size_t i)
{
	return i < TestCaseList->size() ? (*TestCaseList)[i] : NULL;
}

void CleanTestCase()
{
	delete TestCaseList;
	TestCaseList = NULL;
}