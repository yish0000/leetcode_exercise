#include "TestCase.h"

using namespace std;

class SolutionNimGame
{
public:
	bool canWinNimDP(int n) {
		if (n <= 0) return false;
		vector<bool> dp(n, false);
		for (int i = 0; i < n; i++)
		{
			if (i < 3)
				dp[i] = true;
			else
				dp[i] = !(dp[i - 1] && dp[i - 2] && dp[i - 3]);
		}
		return dp.back();
	}

	bool canWinNim(int n)
	{
		return (n % 4) != 0;
	}
};

RUN_TESTCASE(NimGame)
{
	SolutionNimGame sln;
	TESTCASE_ASSERT(!sln.canWinNim(4));
	TESTCASE_ASSERT(sln.canWinNim(7));
}