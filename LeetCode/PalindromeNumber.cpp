#include <iostream>
#include <vector>
#include "TestCase.h"

class Solution
{
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		if (x < 10) return true;
		std::vector<int> arr;
		while (x > 0)
		{
			int part = x % 10;
			arr.push_back(part);
			x /= 10;
		}
		int s = 0, e = (int)arr.size() - 1;
		while (s < e)
		{
			if (arr[s] != arr[e])
				return false;
			s++;
			e--;
		}
		return true;
	}
};

RUN_TESTCASE(PalindromeNumber)
{
	Solution sln;
	TESTCASE_ASSERT(sln.isPalindrome(8671768));
	TESTCASE_ASSERT(sln.isPalindrome(121));
	TESTCASE_ASSERT(!sln.isPalindrome(-68));
	TESTCASE_ASSERT(sln.isPalindrome(9));
	TESTCASE_ASSERT(sln.isPalindrome(3261623));
	TESTCASE_ASSERT(!sln.isPalindrome(3261663));
}
