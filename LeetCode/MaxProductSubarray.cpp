#include "TestCase.h"

using namespace std;

class SolutionMaxProductSubarray
{
public:
	int maxProduct(vector<int>& nums) {
		if (nums.empty())
			return 0;

		int maxValue = nums[0];
		int last_max = nums[0];
		int last_min = nums[0];

		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] > 0)
			{
				last_max = std::max(last_max * nums[i], nums[i]);
				last_min = std::min(last_min * nums[i], nums[i]);
			}
			else
			{
				int a = last_min, b = last_max;
				last_max = std::max(a * nums[i], nums[i]);
				last_min = std::min(b * nums[i], nums[i]);
			}

			maxValue = std::max(maxValue, last_max);
		}

		return maxValue;
	}
};

RUN_TESTCASE(MaxProductSubarray)
{
	SolutionMaxProductSubarray sln;

	vector<int> arr1 = { 2,3,-2,4 };
	TESTCASE_ASSERT(sln.maxProduct(arr1) == 6);

	vector<int> arr2 = { -2,0,-1 };
	TESTCASE_ASSERT(sln.maxProduct(arr2) == 0);

	vector<int> arr3 = { 2,3,-2,4,-2 };
	TESTCASE_ASSERT(sln.maxProduct(arr3) == 96);

	vector<int> arr4 = { 0,2 };
	TESTCASE_ASSERT(sln.maxProduct(arr4) == 2);

	vector<int> arr5 = { 2,-5,-2,-4,3 };
	TESTCASE_ASSERT(sln.maxProduct(arr5) == 24);
}