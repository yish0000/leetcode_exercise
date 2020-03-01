#include "TestCase.h"

using namespace std;

class SolutionBitwiseAndOfNumbersRange
{
public:
	int rangeBitwiseAnd(int m, int n) {
		int cur = m;
		if (cur == 0) return 0;
		for (int i = 0; i < 32; i++)
		{
			if ((cur & (1 << i)) == 0)
				continue;

			for (uint32_t j = m + 1; j <= (uint32_t)n; j++)
			{
				if ((j & (1 << i)) == 0)
				{
					cur &= ~(1 << i);
					break;
				}
			}
		}
		return cur;
	}

	int rangeBitwiseAnd_Quick(int m, int n) {
		int ret = 0;
		int mask = 1 << 30;
		while (mask >= std::max(1, n - m))
		{
			if (mask & m & n)
				ret |= mask;
			mask >>= 1;
		}
		return ret;
	}
};

RUN_TESTCASE(BitwiseAndOfNumbersRange)
{
	SolutionBitwiseAndOfNumbersRange sln;
	TESTCASE_ASSERT(sln.rangeBitwiseAnd_Quick(5, 7) == 4);
	TESTCASE_ASSERT(sln.rangeBitwiseAnd_Quick(0, 1) == 0);
	TESTCASE_ASSERT(sln.rangeBitwiseAnd_Quick(0, 2147483647) == 0);
	TESTCASE_ASSERT(sln.rangeBitwiseAnd_Quick(2147483646, 2147483647) == 2147483646);
}