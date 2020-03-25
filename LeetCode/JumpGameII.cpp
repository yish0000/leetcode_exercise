#include "TestCase.h"

using namespace std;

class SolutionJumpGameII
{
public:
	int jump(vector<int>& nums) {
		if (nums.empty())
			return 0;

		int longestDist = 0;
		int res = 0;
		int cur = 0;
		for (int i = 0; i < nums.size() - 1; i++)
		{
			longestDist = std::max(longestDist, i + nums[i]);
			if (cur <= i)
			{
				res++;
				cur = longestDist;
			}
		}
		return res;
	}

	// TIME EXCEEDED
	int dp(vector<int>& nums)
	{
		if (nums.empty())
			return 0;

		vector<int> dp(nums.size(), 0);
		dp[nums.size() - 1] = 0;
		for (int i = (int)nums.size() - 2; i >= 0; i--)
		{
			if (nums[i] == 0)
				dp[i] = -1;
			else if (nums[i] >= (int)nums.size() - i - 1)
				dp[i] = 1;
			else
			{
				dp[i] = -1;
				for (int j = 1; j <= std::min(nums[i], (int)nums.size() - i - 1); j++)
				{
					if (dp[i + j] < 0)
						continue;
					dp[i] = (dp[i] == -1) ? dp[i + j] + 1 : std::min(dp[i], dp[i + j] + 1);
				}
			}
		}
		return dp.front();
	}
};

RUN_TESTCASE(JumpGameII)
{
	SolutionJumpGameII sln;

	vector<int> arr1 = { 2,3,1,1,4 };
	TESTCASE_ASSERT(sln.jump(arr1) == 2);

	vector<int> arr2 = { 5,9,3,2,1,0,2,3,3,1,0,0 };
	TESTCASE_ASSERT(sln.jump(arr2) == 3);

	vector<int> arr3 = { 9,4,1,1,2,3,1,1,9,1,1,1,1,1,1,1,1 };
	TESTCASE_ASSERT(sln.jump(arr3) == 2);
}