#include "TestCase.h"

using namespace std;

class SolutionBasicCalculator
{
public:
	int calculate(string s) {
		int end = 0;
		return calculate(s, 0, end);
	}

	enum NumState
	{
		NONE,
		READING,
		READY,
	};
	int calculate(string& s, int offset, int& end)
	{
		int num = 0;
		int cur = 0;
		char op = '+';
		int numState = 0;
		for (int i = offset; i < s.size(); i++)
		{
			if (s[i] == '(')
			{
				num = calculate(s, i + 1, end);
				i = end;
				numState = READY;
			}
			else if (s[i] == ')')
			{
				end = i;
				break;
			}
			else if (isdigit(s[i]))
			{
				if (numState == NONE)
					numState = READING;
				num = num * 10 + (s[i] - '0');
				if (i + 1 >= s.size() || !isdigit(s[i + 1]))
					numState = READY;
			}
			else
			{
				if (s[i] == '+')
					op = '+';
				else if (s[i] == '-')
					op = '-';
			}

			if (op != ' ' && numState == READY)
			{
				if (op == '+')
					cur += num;
				else if (op == '-')
					cur -= num;
				num = 0;
				numState = NONE;
				op = ' ';
			}
		}
		return cur;
	}
};

RUN_TESTCASE(BasicCalculator)
{
	SolutionBasicCalculator sln;

	TESTCASE_ASSERT(sln.calculate("1 + 1") == 2);
	TESTCASE_ASSERT(sln.calculate("2-1 + 2") == 3);
	TESTCASE_ASSERT(sln.calculate("(1+(4 +5+  2)-3)+(6+8)") == 23);
}