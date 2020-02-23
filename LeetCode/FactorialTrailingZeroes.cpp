#include "TestCase.h"

using namespace std;

class SolutionFactorialTrailingZeroes
{
public:
	int trailingZeroes(int n)
	{
		int zeroes = 0;
		while (n > 0)
		{
			zeroes += n / 5;
			n /= 5;
		}
		return zeroes;
	}

	int trail(int n, int& zeroes)
	{
		if (n == 0)
			return 1;
		if (n == 1)
			return 1;
		int tail = n * trail(n - 1, zeroes);
		while (tail % 10 == 0)
		{
			tail /= 10;
			zeroes++;
		}
		tail %= 10;
		return tail;
	}
};

RUN_TESTCASE(FactorialTrailingZeroes)
{
	SolutionFactorialTrailingZeroes sln;
	TESTCASE_ASSERT(sln.trailingZeroes(3) == 0);
	TESTCASE_ASSERT(sln.trailingZeroes(5) == 1);
	TESTCASE_ASSERT(sln.trailingZeroes(15) == 3);
	TESTCASE_ASSERT(sln.trailingZeroes(20) == 4);
	TESTCASE_ASSERT(sln.trailingZeroes(25) == 6);
	TESTCASE_ASSERT(sln.trailingZeroes(30) == 7);
	TESTCASE_ASSERT(sln.trailingZeroes(50) == 12);
}