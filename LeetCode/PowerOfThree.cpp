#include "TestCase.h"
#include <math.h>

using namespace std;

class SolutionPowerOfThree
{
public:
	const int max_value = 1162261467;
	bool isPowerOfThree(int n) {
		if (n < 1)
			return false;
		if (n == 1)
			return true;
		return max_value % n == 0;
	}
};

RUN_TESTCASE(PowerOfThree)
{
	SolutionPowerOfThree sln;
	TESTCASE_ASSERT(sln.isPowerOfThree(27));
	TESTCASE_ASSERT(!sln.isPowerOfThree(0));
	TESTCASE_ASSERT(sln.isPowerOfThree(9));
	TESTCASE_ASSERT(!sln.isPowerOfThree(45));
	TESTCASE_ASSERT(!sln.isPowerOfThree(-3));
}