#include "TestCase.h"

using namespace std;

class SolutionUglyNumber
{
public:
	const int primes[3] = { 2,3,5 };
	bool isUgly(int num) {
		if (num <= 0)
			return false;
		if (num == 1)
			return true;
		while (num > 1)
		{
			bool bIsUgly = false;
			for (int i = 0; i < 3; i++)
			{
				if (num % primes[i] == 0)
				{
					num /= primes[i];
					bIsUgly = true;
					break;
				}
			}

			if (!bIsUgly)
				return false;
		}

		return true;
	}
};

RUN_TESTCASE(UglyNumber)
{
	SolutionUglyNumber sln;
	TESTCASE_ASSERT(sln.isUgly(6));
	TESTCASE_ASSERT(sln.isUgly(8));
	TESTCASE_ASSERT(!sln.isUgly(14));
}