#include "TestCase.h"

using namespace std;

class SolutionLenOfLongestSubStr
{
public:
	int lengthOfLongestSubstring(string s) {
		int len = 0;
		int max_len = 0;
		bool chars[256] = {0};
		string::const_iterator left = s.begin();
		string::const_iterator right = s.begin();
		while (right != s.end())
		{
			char ch = *right;
			if (!chars[ch])
			{
				len++;
				chars[ch] = true;
				if (len > max_len)
					max_len = len;
				++right;
			}
			else
			{
				chars[*left] = false;
				len--;
				++left;
			}
		}

		return max_len;
	}

	int lengthOfLongestSubstringSlow(string s) {
		int len = 0;
		int max_len = 0;
		int start = 0;
		bool chars[256] = { 0 };
		string::const_iterator it = s.begin();
		while (it != s.end())
		{
			if (!chars[*it])
			{
				len++;
				chars[*it] = true;
				if (len > max_len)
					max_len = len;
				++it;
			}
			else
			{
				memset(chars, 0, sizeof(chars));
				len = 0;
				start++;
				it = s.begin() + start;
			}
		}

		return max_len;
	}
};

RUN_TESTCASE(LengthOfLongestSubstring)
{
	SolutionLenOfLongestSubStr sln;
	TESTCASE_ASSERT(sln.lengthOfLongestSubstring("abcabcbb") == 3);
	TESTCASE_ASSERT(sln.lengthOfLongestSubstring("bbbbb") == 1);
	TESTCASE_ASSERT(sln.lengthOfLongestSubstring("pwwkew") == 3);
	TESTCASE_ASSERT(sln.lengthOfLongestSubstring("au") == 2);
	TESTCASE_ASSERT(sln.lengthOfLongestSubstring("dvdf") == 3);
}