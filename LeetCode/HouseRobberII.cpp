#include "TestCase.h"

using namespace std;

class SolutionHouseRobberII
{
public:
	int rob(vector<int>& nums) {
		if (nums.empty()) return 0;
		if (nums.size() == 1) return nums[0];
		if (nums.size() == 2) return std::max(nums[0], nums[1]);

		return std::max(dp(nums, 0, (int)nums.size() - 2), dp(nums, 1, (int)nums.size() - 3) + nums.back());
	}

	int dp(vector<int>& nums, int start, int end)
	{
		if (start > end)
			return 0;
		if (start == end)
			return nums[start];

		vector<int> dp(nums.size(), 0);
		dp[start] = nums[start];
		dp[start + 1] = std::max(nums[start], nums[start + 1]);
		for (int i = start + 2; i <= end; i++)
		{
			dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
		}

		return dp[end];
	}
};

RUN_TESTCASE(HouseRobberII)
{
	SolutionHouseRobberII sln;

	vector<int> arr1 = { 2,3,2 };
	TESTCASE_ASSERT(sln.rob(arr1) == 3);

	vector<int> arr2 = { 1,2,3,1 };
	TESTCASE_ASSERT(sln.rob(arr2) == 4);

	vector<int> arr3 = { 4,1,2,7,5,3,1 };
	TESTCASE_ASSERT(sln.rob(arr3));
}