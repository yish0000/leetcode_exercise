#include "TestCase.h"

using namespace std;

class SolutionSumOfTwoIntegers
{
public:
	int getSum(int a, int b) {
		while (b != 0)
		{
			int sum = (a ^ b);
			uint32_t carry = ((uint32_t)a & b) << 1;
			a = sum;
			b = carry;
		}
		return a;
	}
};

RUN_TESTCASE(SumOfTwoIntegers)
{
	SolutionSumOfTwoIntegers sln;
	TESTCASE_ASSERT(sln.getSum(1, -1) == 0);
}