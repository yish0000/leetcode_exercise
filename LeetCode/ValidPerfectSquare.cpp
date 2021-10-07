#include "TestCase.h"

using namespace std;

class SolutionValidPerfectSquare
{
public:
	bool isPerfectSquare(int num) {
		if (num == 1) return true;
		if ((num & (num - 1)) == 0)
			return true;
		int l = 2;
		int r = num / 2;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			int64_t squared = (int64_t)mid * mid;
			if (squared == num)
				return true;
			else if (squared < num)
				l = mid + 1;
			else
				r = mid - 1;
		}
		return false;
	}
};

RUN_TESTCASE(ValidPerfectSquare)
{
	SolutionValidPerfectSquare sln;
	TESTCASE_ASSERT(sln.isPerfectSquare(9));
	TESTCASE_ASSERT(sln.isPerfectSquare(81));
	TESTCASE_ASSERT(sln.isPerfectSquare(121));
	TESTCASE_ASSERT(sln.isPerfectSquare(14641));
	TESTCASE_ASSERT(!sln.isPerfectSquare(146410));
}