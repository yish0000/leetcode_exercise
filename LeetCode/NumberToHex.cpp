#include "TestCase.h"
#include <stack>

using namespace std;

class SolutionNumberToHex
{
public:
	string toHex(int num) {
		string ret;
		stack<char> s;
		int cur = 0;
		for (int i = 0; i < 32; i++)
		{
			if (num & (1 << i))
				cur += 1 << (i % 4);
			if ((i + 1) % 4 == 0)
			{
				if (cur < 10)
					s.push(cur + '0');
				else
					s.push(cur - 10 + 'a');
				cur = 0;
			}
		}
		while (s.size() > 0)
		{
			if (s.top() != '0' || ret.size() > 0 || s.size() == 1)
				ret.push_back(s.top());
			s.pop();
		}
		return ret;
	}
};

RUN_TESTCASE(NumberToHex)
{
	SolutionNumberToHex sln;
	TESTCASE_ASSERT(sln.toHex(8866983) == "874ca7");
	TESTCASE_ASSERT(sln.toHex(0) == "0");
	TESTCASE_ASSERT(sln.toHex(26) == "1a");
	TESTCASE_ASSERT(sln.toHex(-1) == "ffffffff");
	TESTCASE_ASSERT(sln.toHex(111111) == "1b207");
}