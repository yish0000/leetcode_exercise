#include "TestCase.h"

using namespace std;

class SolutionCountPrimes
{
public:
#define SET_BITS(idx) primes[idx>>3] |= (1 << (idx & 7))
#define TEST_BITS(idx) (primes[idx>>3] & (1 << (idx & 7)))
	int countPrimes(int n) {
		vector<char> primes((n >> 3) + 1, 0);
		int count = 0;
		for (uint64_t i = 2; i < n; i++)
		{
			if (TEST_BITS(i))
				continue;
			count++;
			for (uint64_t x = i * i; x < n; x += i)
				SET_BITS(x);
		}
		return count;
	}
};

RUN_TESTCASE(CountPrimes)
{
	SolutionCountPrimes sln;
	TESTCASE_ASSERT(sln.countPrimes(10) == 4);
	TESTCASE_ASSERT(sln.countPrimes(499979) == 41537);
}