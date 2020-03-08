#include "TestCase.h"

using namespace std;

class SolutionMinimumSizeSubarraySum
{
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int l = 0, r = -1;
		int cur = 0;
		int minLen = std::numeric_limits<int>::max();
		for (int i = 0; i < nums.size(); i++)
		{
			cur += nums[i];
			r = i;

			if (cur >= s)
			{
				int t = cur - s;
				while (l < r)
				{
					if (t >= nums[l])
					{
						t -= nums[l];
						cur -= nums[l];
						l++;
					}
					else
						break;
				}

				minLen = std::min(r - l + 1, minLen);
			}
		}

		return minLen == std::numeric_limits<int>::max() ? 0 : minLen;
	}
};

RUN_TESTCASE(MinimumSizeSubarraySum)
{
	SolutionMinimumSizeSubarraySum sln;

	vector<int> arr1 = { 2,3,1,2,4,3 };
	TESTCASE_ASSERT(sln.minSubArrayLen(7, arr1) == 2);

	vector<int> arr2 = { 5, 1, 3, 5, 10, 7, 4, 9, 2, 8 };
	TESTCASE_ASSERT(sln.minSubArrayLen(15, arr2) == 2);
}