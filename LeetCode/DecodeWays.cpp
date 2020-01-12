#include "TestCase.h"

using namespace std;

class SolutionDecodeWays
{
public:
	int numDecodings(string s) {
		if (s.empty()) return 0;
		if (s[0] == '0') return 0;

		vector<int> dp(s.length() + 1, 0);
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 1; i < s.length(); i++)
		{
			if (s[i] == '0')
			{
				if (s[i - 1] != '2' && s[i - 1] != '1')
					return 0;
				else
					dp[i + 1] = dp[i - 1];
			}
			else
			{
				if ((s[i - 1] > '2' || (s[i - 1] == '2' && s[i] > '6')) || s[i - 1] == '0')
					dp[i + 1] = dp[i];
				else
					dp[i + 1] = dp[i - 1] + dp[i];
			}
		}
		return dp[s.length()];
	}
};

RUN_TESTCASE(DecodeWays)
{
	SolutionDecodeWays sln;

	TESTCASE_ASSERT(sln.numDecodings("12") == 2);
	TESTCASE_ASSERT(sln.numDecodings("226") == 3);
	TESTCASE_ASSERT(sln.numDecodings("0") == 0);
	TESTCASE_ASSERT(sln.numDecodings("30") == 0);
	TESTCASE_ASSERT(sln.numDecodings("20") == 1);
	TESTCASE_ASSERT(sln.numDecodings("08") == 0);
	TESTCASE_ASSERT(sln.numDecodings("1003") == 0);
	TESTCASE_ASSERT(sln.numDecodings("10") == 1);
	TESTCASE_ASSERT(sln.numDecodings("2703") == 0);
	TESTCASE_ASSERT(sln.numDecodings("2203") == 1);
}