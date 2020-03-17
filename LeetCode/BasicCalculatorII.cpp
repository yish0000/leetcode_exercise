#include "TestCase.h"

using namespace std;

class SolutionBasicCalculatorII
{
public:
	int calculate(string s)
	{
		int i = 0;
		return add_min(s, i);
	}

	int add_min(string& s, int& i)
	{
		int result = mul_div(s, i);
		while (i < s.size())
		{
			if (s[i] == '+')
				result += mul_div(s, ++i);
			else if (s[i] == '-')
				result -= mul_div(s, ++i);
			else
				break;
		}
		return result;
	}

	int mul_div(string& s, int& i)
	{
		int result = atom(s, i);
		while (i < s.size())
		{
			if (s[i] == '*')
				result *= atom(s, ++i);
			else if (s[i] == '/')
				result /= atom(s, ++i);
			else
				break;
		}
		return result;
	}

	int atom(string& s, int& i)
	{
		return num(s, i);
	}

	int num(string& s, int& i)
	{
		int result = 0;
		while (isspace(s[i]) && i < s.size()) i++;
		while (isdigit(s[i])) result = result * 10 + (s[i++] - '0');
		while (isspace(s[i]) && i < s.size()) i++;
		return result;
	}
};

RUN_TESTCASE(BasicCalculatorII)
{
	SolutionBasicCalculatorII sln;
	TESTCASE_ASSERT(sln.calculate("2* 3  + 5 / 2 + 7") == 15);
	TESTCASE_ASSERT(sln.calculate("3+2*2") == 7);
	TESTCASE_ASSERT(sln.calculate(" 3/2 ") == 1);
	TESTCASE_ASSERT(sln.calculate(" 3+5  / 2 ") == 5);
}