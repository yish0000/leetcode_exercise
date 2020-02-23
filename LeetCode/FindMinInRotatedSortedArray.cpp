#include "TestCase.h"

using namespace std;

class SolutionFindMinInRotatedSortedArray
{
public:
	int findMin(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int l = 0, r = (int)nums.size() - 1;
		while (l <= r)
		{
			int mid = l + (r - l) / 2;
			if (mid + 1 >= nums.size())
				return nums.back();
			if (nums[mid] > nums[mid + 1])
			{
				return nums[mid + 1];
			}
			else if (nums[mid] > nums.back())
				l = mid + 1;
			else if (nums[mid] < nums.front())
				r = mid - 1;
			else
				break;
		}
		return nums[0];
	}
};

RUN_TESTCASE(FindMinInRotatedSortedArray)
{
	SolutionFindMinInRotatedSortedArray sln;

	vector<int> arr1 = { 3,4,5,1,2 };
	TESTCASE_ASSERT(sln.findMin(arr1) == 1);

	vector<int> arr2 = { 4,5,6,7,0,1,2 };
	TESTCASE_ASSERT(sln.findMin(arr2) == 0);

	vector<int> arr3 = { 1,2 };
	TESTCASE_ASSERT(sln.findMin(arr3) == 1);
}