#include "TestCase.h"

using namespace std;

class SolutionValidPalindrom
{
public:
	bool isPalindrome(string s) {
		if (s.empty())
			return true;

		string::const_iterator l = s.begin(), r = s.end() - 1;
		while (l < r)
		{
			if (!is_alpha_or_numberic(*l))
			{
				++l;
				continue;
			}
			if (!is_alpha_or_numberic(*r))
			{
				--r;
				continue;
			}
			if (tolower(*l) != tolower(*r))
				return false;
			++l;
			--r;
		}

		return true;
	}

	bool is_alpha_or_numberic(char c)
	{
		return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
	}
};

RUN_TESTCASE(ValidPalindrom)
{
	SolutionValidPalindrom sln;
	TESTCASE_ASSERT(sln.isPalindrome("A man, a plan, a canal: Panama"));
	TESTCASE_ASSERT(!sln.isPalindrome("race a car"));
}