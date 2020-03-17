#include "TestCase.h"

using namespace std;

class SolutionIntCalculator
{
public:
	int add(int a, int b)
	{
		while (b != 0)
		{
			int sum = a ^ b;
			b = (a & b) << 1;
			a = sum;
		}

		return a;
	}
};

RUN_TESTCASE(IntCalculator)
{
	SolutionIntCalculator sln;
	TESTCASE_ASSERT(sln.add(777, 987) == 1764);
	TESTCASE_ASSERT(sln.add(777, -7) == 770);
}