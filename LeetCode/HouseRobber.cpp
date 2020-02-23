#include "TestCase.h"

using namespace std;

class SolutionHouseRobber
{
public:
	int rob(vector<int>& nums)
	{
		if (nums.empty()) return 0;
		if (nums.size() == 1) return nums[0];

		vector<int> dp(nums.size(), 0);
		dp[0] = nums[0];
		dp[1] = std::max(nums[0], nums[1]);
		for (int i = 2; i < nums.size(); i++)
		{
			dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
		}

		return dp[nums.size() - 1];
	}
};

RUN_TESTCASE(HouseRobber)
{
	SolutionHouseRobber sln;

	vector<int> arr1 = { 1,2,3,1 };
	TESTCASE_ASSERT(sln.rob(arr1) == 4);

	vector<int> arr2 = { 2,7,9,3,1 };
	TESTCASE_ASSERT(sln.rob(arr2) == 12);
}