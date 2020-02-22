#include "TestCase.h"

using namespace std;

class SolutionFirstMissingPositive
{
public:
	int firstMissingPositive(vector<int>& nums) {
		int r = (int)nums.size();
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != i + 1)
			{
				bool bSwap = false;
				if (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1])
				{
					swap(nums[i], nums[nums[i] - 1]);
					bSwap = true;
				}
				else
				{
					if (i != nums.size() - 1 && r > 0 && nums[r - 1] != r && nums[i] != nums[r - 1])
					{
						swap(nums[i], nums[r - 1]);
						r--;
						bSwap = true;
					}
				}
				if (bSwap && nums[i] != i + 1)
					i -= 1;
			}
		}
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != i + 1)
				return i + 1;
		}
		return (int)nums.size() + 1;
	}
};

RUN_TESTCASE(FirstMissingPositive)
{
	SolutionFirstMissingPositive sln;

	vector<int> arr1 = { 1,2,0 };
	TESTCASE_ASSERT(sln.firstMissingPositive(arr1) == 3);

	vector<int> arr2 = { 3,4,-1,1 };
	TESTCASE_ASSERT(sln.firstMissingPositive(arr2) == 2);

	vector<int> arr3 = { 7,8,9,11,12 };
	TESTCASE_ASSERT(sln.firstMissingPositive(arr3) == 1);

	vector<int> arr4 = { 1,1 };
	TESTCASE_ASSERT(sln.firstMissingPositive(arr4) == 2);
}