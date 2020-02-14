#include "TestCase.h"

using namespace std;

class SolutionFindPeakElements
{
public:
	int findPeakElement(vector<int>& nums) {
		if (nums.empty())
			return 0;

		bool up = true;
		int cur = nums[0];
		int index = 0;
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] > cur)
			{
				index = i;
				cur = nums[i];
			}
			else
				break;
		}

		return index;
	}
};

RUN_TESTCASE(FindPeakElements)
{
	SolutionFindPeakElements sln;

	vector<int> arr1 = { 1,2,3,1 };
	TESTCASE_ASSERT(sln.findPeakElement(arr1) == 2);

	vector<int> arr2 = { 1,2,1,3,5,6,4 };
	TESTCASE_ASSERT(sln.findPeakElement(arr2) == 1);
}