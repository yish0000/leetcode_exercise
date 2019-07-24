#include "TestCase.h"

#include <vector>
#include <iostream>
#include <sstream>

#if _WIN32
#include <windows.h>
#endif

static std::vector<TestCase*>* TestCaseList;
static std::vector<std::string> assertFailed;

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
	{
		std::stringstream msg;
		msg << message << " assert ok!";
		std::cout << msg.str() << std::endl;

#if _WIN32
		OutputDebugStringA((msg.str() + '\n').c_str());
#endif
	}
	else
	{
#if _WIN32
		HANDLE hdl = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hdl, FOREGROUND_RED | FOREGROUND_INTENSITY);
#endif

		std::stringstream msg;
		msg << std::string(filename) << "(" << line << "): " << message << " assert failed!";
		std::cout << msg.str() << std::endl;

#if _WIN32
		OutputDebugStringA((msg.str() + '\n').c_str());
#endif

		assertFailed.push_back(msg.str());

#if _WIN32
		SetConsoleTextAttribute(hdl, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#endif
	}
}

void TestCase::PrintAssetFailed()
{
#if _WIN32
	HANDLE hdl = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hdl, FOREGROUND_RED | FOREGROUND_INTENSITY);
#endif

	for (std::vector<std::string>::const_iterator it = assertFailed.begin(); it != assertFailed.end(); ++it)
	{
		std::cout << *it << std::endl;

#if _WIN32
		OutputDebugStringA((*it + '\n').c_str());
#endif
	}

#if _WIN32
	SetConsoleTextAttribute(hdl, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#endif
}

bool TestCase::HaveAssetFailed()
{
	return assertFailed.size() > 0;
}

///////////////////////////////////////////////////////////////////////////

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