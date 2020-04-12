#include "TestCase.h"

using namespace std;

class SolutionSuperUglyNumber
{
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		vector<int> dp(n, 0);
		vector<int> index(primes.size(), 0);
		dp[0] = 1;
		for (int i = 1; i < n; i++)
		{
			dp[i] = std::numeric_limits<int>::max();
			for (int j = 0; j < primes.size(); j++)
				dp[i] = std::min(dp[i], dp[index[j]] * primes[j]);
			for (int j = 0; j < primes.size(); j++)
			{
				if (dp[i] == dp[index[j]] * primes[j])
					index[j]++;
			}
		}
		return dp.back();
	}
};

RUN_TESTCASE(SuperUglyNumber)
{
	SolutionSuperUglyNumber sln;

	vector<int> arr1 = { 2,7,13,19 };
	TESTCASE_ASSERT(sln.nthSuperUglyNumber(12, arr1) == 32);
}