#include "TestCase.h"
#include <queue>

using namespace std;

class SolutionPerfectSquares
{
public:
	int numSquares(int n) {
		vector<int> sqr;
		for (int i = 1; i <= n; i++)
		{
			if (i*i > n)
				break;
			sqr.push_back(i*i);
		}

		vector<int> dp(n + 1, 0);
		for (auto s : sqr)
			dp[s] = 1;
		for (int i = 1; i <= n; i++)
		{
			int count = 0;
			for (auto s : sqr)
			{
				if (i < s)
					continue;
				if (i == s)
				{
					count = 1;
					break;
				}
				if (dp[i - s] != 0)
				{
					if (count == 0)
						count = dp[i - s] + 1;
					else
						count = std::min(count, dp[i - s] + 1);
				}
			}
			if (count)
				dp[i] = count;
		}

		return dp.back();
	}
};

RUN_TESTCASE(PerfectSquares)
{
	SolutionPerfectSquares sln;
	TESTCASE_ASSERT(sln.numSquares(12) == 3);
	TESTCASE_ASSERT(sln.numSquares(13) == 2);
}