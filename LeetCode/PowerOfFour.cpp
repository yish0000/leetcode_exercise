#include "TestCase.h"

using namespace std;

class SolutionPowerOfFour
{
public:
	bool isPowerOfFour(int num) {
		if (num < 0)
			return false;
		if (num & (num - 1))
			return false;
		for (int i = 0; i < 32; i++)
		{
			if ((num & (1 << i)) && !(i & 1))
				return true;
		}

		return false;
	}
};

RUN_TESTCASE(PowerOfFour)
{
	SolutionPowerOfFour sln;
	TESTCASE_ASSERT(sln.isPowerOfFour(4));
	TESTCASE_ASSERT(sln.isPowerOfFour(1));
	TESTCASE_ASSERT(sln.isPowerOfFour(16));
	TESTCASE_ASSERT(!sln.isPowerOfFour(8));
	TESTCASE_ASSERT(!sln.isPowerOfFour(15));
}