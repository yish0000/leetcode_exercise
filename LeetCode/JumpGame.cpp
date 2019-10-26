#include "TestCase.h"
#include <set>

using namespace std;

class SolutionJumpGame
{
public:
	bool canJump(vector<int>& nums) {
		if (nums.empty())
			return false;
		int count = (int)nums.size();
		int leftGoodIndex = (int)nums.size() - 1;
		for (int i = count - 2; i >= 0; --i)
		{
			if (i + nums[i] >= leftGoodIndex)
				leftGoodIndex = i;
		}
		return leftGoodIndex == 0;
	}

	bool canJumpDP(vector<int>& nums) {
		if (nums.empty())
			return false;
		int count = (int)nums.size();
		vector<bool> dp(count, false);
		dp[count - 1] = true;
		for (int i = count - 2; i >= 0; --i)
		{
			int furthestJump = std::min(i + nums[i], count - 1);
			for (int s = furthestJump; s > i; --s)
			{
				if (dp[s])
				{
					dp[i] = true;
					break;
				}
			}
		}
		return dp[0];
	}
};

RUN_TESTCASE(JumpGame)
{
	SolutionJumpGame sln;

	vector<int> arr1 = { 2,3,1,1,4 };
	TESTCASE_ASSERT(sln.canJump(arr1));

	vector<int> arr2 = { 3,2,1,0,4 };
	TESTCASE_ASSERT(!sln.canJump(arr2));

	vector<int> arr3 = { 2,0 };
	TESTCASE_ASSERT(sln.canJump(arr3));
}