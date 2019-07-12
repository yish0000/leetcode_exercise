#include "TestCase.h"

class SolutionCountNumbersUniqueDigits {
public:
	int countNumbersWithUniqueDigits(int n) {
		if (n < 0) return 0;
		if (n == 0) return 1;
		if (n == 1) return 10;
		int val = 10;
		int val2 = 1;
		for (int i = 1; i < n; i++)
		{
			val *= (10 - i);
			val2 *= (10 - i);
		}

		return val - val2 + countNumbersWithUniqueDigits(n - 1);
	}
};

RUN_TESTCASE(CountNumbersUniqueDigits)
{
	SolutionCountNumbersUniqueDigits sln;
	TESTCASE_ASSERT(sln.countNumbersWithUniqueDigits(0) == 1);
	TESTCASE_ASSERT(sln.countNumbersWithUniqueDigits(1) == 10);
	TESTCASE_ASSERT(sln.countNumbersWithUniqueDigits(2) == 91);
	TESTCASE_ASSERT(sln.countNumbersWithUniqueDigits(3) == 739);
}