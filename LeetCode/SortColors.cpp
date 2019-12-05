#include "TestCase.h"

using namespace std;

class SolutionSortColors
{
public:
	void sortColors(vector<int>& nums) {
		int l = 0;
		int r = (int)nums.size() - 1;
		int mid = 0;
		while (mid <= r)
		{
			if (nums[mid] == 0)
			{
				std::swap(nums[mid], nums[l]);
				mid++;
				l++;
			}
			else if (nums[mid] == 1)
				mid++;
			else
			{
				std::swap(nums[mid], nums[r]);
				r--;
			}
		}
	}
};

RUN_TESTCASE(SortColors)
{
	SolutionSortColors sln;

	vector<int> arr1 = { 2,0,2,1,1,0 };
	vector<int> ret1 = { 0,0,1,1,2,2 };
	sln.sortColors(arr1);
	TESTCASE_ASSERT(arr1 == ret1);

	vector<int> arr2 = { 2,0,2,1,1,0,1 };
	vector<int> ret2 = { 0,0,1,1,1,2,2 };
	sln.sortColors(arr2);
	TESTCASE_ASSERT(arr2 == ret2);
}
