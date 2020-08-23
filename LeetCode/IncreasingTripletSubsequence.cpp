#include "TestCase.h"

using namespace std;

class SolutionIncreasingTripletSubsequence
{
public:
	bool increasingTriplet(vector<int>& nums) {
		if (nums.size() < 3)
			return false;

		int max_len = 1;
		vector<int> dp(nums.size(), 0);
		dp[nums.size() - 1] = 1;
		for (int i = (int)nums.size() - 1; i >= 0; i--)
		{
			dp[i] = 1;
			for (int j = i + 1; j < nums.size(); j++)
			{
				if (nums[i] < nums[j])
					dp[i] = std::max(dp[i], dp[j] + 1);
			}
			max_len = std::max(max_len, dp[i]);
			if (max_len >= 3)
				return true;
		}

		return max_len >= 3;
	}

	bool increasingTripletFast(vector<int>& nums)
	{
		vector<int> lis;
		for (auto num : nums)
		{
			auto it = std::lower_bound(lis.begin(), lis.end(), num);
			if (it == lis.end())
			{
				lis.push_back(num);
				if (lis.size() >= 3)
					break;
			}
			else if (*it > num)
				*it = num;
		}
		return lis.size() >= 3;
	}
};

RUN_TESTCASE(IncreasingTripletSubsequence)
{
	SolutionIncreasingTripletSubsequence sln;

	vector<int> arr1 = { 1,2,3,4,5 };
	TESTCASE_ASSERT(sln.increasingTriplet(arr1));

	vector<int> arr2 = { 5,4,3,2,1 };
	TESTCASE_ASSERT(!sln.increasingTriplet(arr2));
}