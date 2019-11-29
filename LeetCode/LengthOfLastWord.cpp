#include "TestCase.h"

using namespace std;

class SolutionLengthOfLastWord
{
public:
	int lengthOfLastWord(string s) {
		int len = 0;
		string::reverse_iterator it = s.rbegin();
		for (; it != s.rend(); ++it)
		{
			if (*it == ' ')
			{
				if (len > 0)
					break;
			}
			else
			{
				len++;
			}
		}
		return len;
	}
};

RUN_TESTCASE(LengthOfLastWord)
{
	SolutionLengthOfLastWord sln;
	TESTCASE_ASSERT(sln.lengthOfLastWord("Hello World  ") == 5);
	TESTCASE_ASSERT(sln.lengthOfLastWord("   ") == 0);
}