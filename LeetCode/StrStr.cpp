#include "TestCase.h"

using namespace std;

class SolutionStrStr {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty())
			return 0;
		if (needle.length() > haystack.length())
			return -1;
		else if (needle.length() == haystack.length())
			return (haystack == needle) ? 0 : -1;
		else
		{
			for (size_t i = 0; i < haystack.length(); i++)
			{
				size_t j = 0;
				while (j < needle.length())
				{
					if (haystack[i + j] != needle[j])
						break;
					else
						j++;
				}

				if (j == needle.length())
					return (int)i;
			}

			return -1;
		}
	}
};

RUN_TESTCASE(StrStr)
{
	SolutionStrStr sln;
	TESTCASE_ASSERT(sln.strStr("hello", "ll") == 2);
	TESTCASE_ASSERT(sln.strStr("aaaaa", "bba") == -1);
	TESTCASE_ASSERT(sln.strStr("hello world, hello world!!!", "orl") == 7);
}
