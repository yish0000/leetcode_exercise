#include "TestCase.h"

using namespace std;

class SolutionReverseWordsInString
{
public:
	string reverseWords(string s) {
		string ret;
		int index = (int)s.length() - 1;
		int r = -1, l = -1;
		while (index >= 0)
		{
			if (s[index] == ' ')
			{
				if (r != -1)
				{
					if (l == -1) l = r;
					ret.append(&s[l], r - l + 1);
					ret.push_back(' ');
				}

				r = l = -1;
			}
			else
			{
				if (r == -1)
					r = index;
				else
					l = index;
			}

			index--;
		}

		if (r != -1 )
		{
			if (l == -1) l = r;
			ret.append(&s[l], r - l + 1);
		}
		else
		{
			if (ret.size() > 0 && ret.back() == ' ')
				ret.pop_back();
		}

		return ret;
	}
};

RUN_TESTCASE(ReverseWordsInString)
{
	SolutionReverseWordsInString sln;

	TESTCASE_ASSERT(sln.reverseWords("the sky is blue") == "blue is sky the");
	TESTCASE_ASSERT(sln.reverseWords(" hello world!  ") == "world! hello");
	TESTCASE_ASSERT(sln.reverseWords("a good   example") == "example good a");
}