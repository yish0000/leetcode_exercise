#include "TestCase.h"

using namespace std;

class SolutionSingleNonDuplicate {
public:
	int singleNonDuplicate(vector<int>& nums) {
		if (nums.size() % 2 == 0)
			return -1;
		int h = (int)nums.size() / 2;
		int l = 0;
		while (l < h)
		{
			int mid = l + (h - l) / 2;
			if (nums[mid * 2] == nums[mid * 2 + 1])
				l = mid + 1;
			else
				h = mid;
		}
		return nums[l * 2];
	}

	int singleNonDuplicateOld(vector<int>& nums) {
		int l = 0;
		int r = (int)nums.size() - 1;
		while (l <= r)
		{
			int mid = l + (r - l) / 2;
			if (mid == l && mid == r)
				return nums[mid];
			else if (mid == l)
			{
				if (nums[mid] != nums[mid + 1])
					return nums[mid];
			}
			else if (mid == r)
			{
				if (nums[mid - 1] != nums[mid])
					return nums[mid];
			}
			else
			{
				if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
					return nums[mid];
				else if (nums[mid] != nums[mid - 1])
				{
					if (mid & 1)
						r = mid - 1;
					else
						l = mid + 2;
				}
				else if (nums[mid] != nums[mid + 1])
				{
					if (mid & 1)
						l = mid + 1;
					else
						r = mid - 2;
				}
			}
		}
		return -1;
	}
};

RUN_TESTCASE(SingleNonDuplicate)
{
	SolutionSingleNonDuplicate sln;

	vector<int> arr1 = { 1,1,2,2,3,3,5,6,6 };
	TESTCASE_ASSERT(sln.singleNonDuplicate(arr1) == 5);
	vector<int> arr2 = { 1,1,2,2,3,3,6,6,7 };
	TESTCASE_ASSERT(sln.singleNonDuplicate(arr2) == 7);
	vector<int> arr3 = { 0,1,1,2,2,3,3,6,6,7,7,9,9 };
	TESTCASE_ASSERT(sln.singleNonDuplicate(arr3) == 0);
	vector<int> arr4 = { 0 };
	TESTCASE_ASSERT(sln.singleNonDuplicate(arr4) == 0);
	vector<int> arr5 = { 1,1,2,2 };
	TESTCASE_ASSERT(sln.singleNonDuplicate(arr5) == -1);
}