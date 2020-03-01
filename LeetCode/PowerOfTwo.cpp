#include "TestCase.h"

using namespace std;

class SolutionPowerOfTwo
{
public:
	bool isPowerOfTwo(int n) {
		return n != 0 ? (n & (n - 1)) == 0 : false;
	}
};

RUN_TESTCASE(PowerOfTwo)
{
	SolutionPowerOfTwo sln;
	TESTCASE_ASSERT(sln.isPowerOfTwo(1));
	TESTCASE_ASSERT(sln.isPowerOfTwo(16));
	TESTCASE_ASSERT(!sln.isPowerOfTwo(218));
	TESTCASE_ASSERT(!sln.isPowerOfTwo(0));
}