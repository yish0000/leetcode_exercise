#include "TestCase.h"

using namespace std;

class SolutionTargetSum
{
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		int N = (int)nums.size();
		int sum = 0;
		for (int i = 0; i < N; i++)
			sum += nums[i];
		vector<vector<int>> dp(N, vector<int>(sum * 2 + 1, 0));
		dp[0][nums[0] + sum] = 1;
		dp[0][-nums[0] + sum] += 1;
		for (int i = 1; i < N; i++)
		{
			for (int s = -sum; s <= sum; s++)
			{
				if (dp[i - 1][s + sum] > 0)
				{
					dp[i][s + sum + nums[i]] += dp[i - 1][s + sum];
					dp[i][s + sum - nums[i]] += dp[i - 1][s + sum];
				}
			}
		}
		return (S > sum || S < -sum) ? 0 : dp[N - 1][S + sum];
	}
};

RUN_TESTCASE(TargetSum)
{
	SolutionTargetSum sln;

	vector<int> arr1 = { 1,1,1,1,1 };
	TESTCASE_ASSERT(sln.findTargetSumWays(arr1, 3) == 5);
	TESTCASE_ASSERT(sln.findTargetSumWays(arr1, -3) == 5);

	vector<int> arr2 = { 0,0,0,0,0,0,0,0,1 };
	TESTCASE_ASSERT(sln.findTargetSumWays(arr2, 1) == 256);
}