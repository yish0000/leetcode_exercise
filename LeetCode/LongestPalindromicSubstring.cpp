#include "TestCase.h"

using namespace std;

class SolutionLongestPalindromicSubstring
{
public:
	string longestPalindrome(string s) {
		string result;
		if (s.empty()) return result;
		int left = 0, right = 0;
		for (int i = 1; i < (int)s.size(); i++)
		{
			int l = i - 1;
			int r = i;
			while (l >= 0 && r < (int)s.size() && l < r && s[l] == s[r])
			{
				if (r - l > right - left)
				{
					left = l;
					right = r;
				}

				l--;
				r++;
			}

			l = i - 1;
			r = i + 1;
			while (l >= 0 && r < (int)s.size() && l < r && s[l] == s[r])
			{
				if (r - l > right - left)
				{
					left = l;
					right = r;
				}

				l--;
				r++;
			}
		}
		result.assign(s, left, right - left + 1);
		return result;
	}

	string longestPalindromeSlow(string s) {
		string result;
		int max_len = 0;
		string::const_iterator itL = s.begin();
		string::const_iterator itR = s.begin();
		string::const_iterator destL = itL;
		string::const_iterator destR = itR;
		while (itL != s.end())
		{
			if (isPalindromeString(itL, itR) && (itR - itL + 1) > max_len)
			{
				destL = itL;
				destR = itR;
				max_len = (int)(itR - itL + 1);
			}

			if (++itR == s.end())
			{
				++itL;
				if (s.end() - itL < max_len)
					break;

				itR = itL + max_len;
				if (itR == s.end())
					break;
			}
		}

		result.assign(destL, destR + 1);
		return result;
	}

	bool isPalindromeString(string::const_iterator l, string::const_iterator r)
	{
		if (l == r)
			return true;

		while (l < r)
		{
			if (*l != *r)
				return false;
			l++;
			r--;
		}

		return true;
	}
};

RUN_TESTCASE(LongestPalindromicSubstring)
{
	SolutionLongestPalindromicSubstring sln;
	TESTCASE_ASSERT(sln.longestPalindrome("xabcdedcba7821") == "abcdedcba");
	TESTCASE_ASSERT(sln.longestPalindrome("babad") == "bab");
	TESTCASE_ASSERT(sln.longestPalindrome("cbbd") == "bb");
	TESTCASE_ASSERT(sln.longestPalindrome("dddddddddddddddddddd") == "dddddddddddddddddddd");
}
