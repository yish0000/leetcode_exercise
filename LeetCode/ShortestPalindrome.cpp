#include "TestCase.h"

using namespace std;

class SolutionShortestPalindrome
{
public:
	string shortestPalindrome(string s) {
		/*
		int right = 0;
		for (int i = (int)s.size() - 1; i >= 0; i--)
		{
			int l = 0;
			int r = i;
			while (l < r && s[l] == s[r])
			{
				l++;
				r--;
			}

			if (l >= r)
			{
				right = i;
				break;
			}
		}

		if (right == (int)s.size() - 1)
			return s;

		string str;
		for (int i = (int)s.size() - 1; i > right; i--)
			str.push_back(s[i]);
		return str + s;
		*/

		int n = (int)s.size();
		int i = 0;
		for (int j = n - 1; j >= 0; j--) {
			if (s[i] == s[j])
				i++;
		}
		if (i == n)
			return s;
		string remain_rev = s.substr(i, n);
		reverse(remain_rev.begin(), remain_rev.end());
		return remain_rev + shortestPalindrome(s.substr(0, i)) + s.substr(i);
	}
};

RUN_TESTCASE(ShortestPalindrome)
{
	SolutionShortestPalindrome sln;
	TESTCASE_ASSERT(sln.shortestPalindrome("abcbabcaba") == "abacbabcbabcaba");
	TESTCASE_ASSERT(sln.shortestPalindrome("aacecaaa") == "aaacecaaa");
	TESTCASE_ASSERT(sln.shortestPalindrome("abcd") == "dcbabcd");
	TESTCASE_ASSERT(sln.shortestPalindrome("abbabaab") == "baababbabaab");

	string s;
	for (int i = 0; i < 40000; i++)
		s.push_back('a');
	TESTCASE_ASSERT(sln.shortestPalindrome(s) == s);
}
