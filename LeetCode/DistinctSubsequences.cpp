#include "TestCase.h"

using namespace std;

class SolutionDistinctSubsequences
{
public:
	int numDistinct(string s, string t) {
		if (s.empty() || t.empty())
			return 0;

		vector<vector<int>> dp(s.size(), vector<int>(t.size(), 0));
		dp[0][0] = (s[0] == t[0]) ? 1 : 0;
		for (size_t i = 0; i < s.size(); i++)
		{
			for (size_t j = 0; j < t.size(); j++)
			{
				if (i == 0 && j == 0)
					continue;

				if (j == 0)
				{
					dp[i][j] = (s[i] == t[j]) ? dp[i - 1][j] + 1 : dp[i - 1][j];
				}
				else
				{
					if (j > i)
						dp[i][j] = 0;
					else
					{
						if (s[i] == t[j])
						{
							dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
						}
						else
						{
							dp[i][j] = dp[i - 1][j];
						}
					}
				}
			}
		}

		return dp[s.size() - 1][t.size() - 1];
	}
};

RUN_TESTCASE(DistinctSubsequences)
{
	SolutionDistinctSubsequences sln;

	TESTCASE_ASSERT(sln.numDistinct("rabbbit", "rabbit") == 3);
	TESTCASE_ASSERT(sln.numDistinct("babgbag", "bag") == 5);
}