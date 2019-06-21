#include <iostream>
#include <vector>
#include "TestCase.h"

class Solution
{
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		if (x < 10) return true;
		int input = x;
		unsigned reverse = 0;
		while (input > 0)
		{
			reverse = reverse * 10 + input % 10;
			input /= 10;
		}
		return reverse == x;
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