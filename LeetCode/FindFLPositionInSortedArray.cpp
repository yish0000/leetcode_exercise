#include "TestCase.h"

using namespace std;

class SolutionFindFLPosInSortedArray
{
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> vec({ -1, -1 });
		int s = find_edge(nums, target, true);
		if (s == nums.size() || nums[s] != target)
			return vec;
		vec[0] = s;
		vec[1] = find_edge(nums, target, false) - 1;
		return vec;
	}

	int find_edge(vector<int>& nums, int target, bool left)
	{
		int l = 0;
		int r = (int)nums.size();
		while (l < r)
		{
			int mid = l + (r - l) / 2;
			if (nums[mid] > target || (left && nums[mid] == target))
				r = mid;
			else
				l = mid + 1;
		}
		return l;
	}
};

RUN_TESTCASE(FindFLPosInSortedArray)
{
	SolutionFindFLPosInSortedArray sln;

	vector<int> arr1 = { 5,7,7,8,8,10 };
	vector<int> res1 = { 3,4 };
	vector<int> res2 = { -1,-1 };
	TESTCASE_ASSERT(sln.searchRange(arr1, 8) == res1);
	TESTCASE_ASSERT(sln.searchRange(arr1, 6) == res2);
	vector<int> arr2 = { 0,1,3,5,7,8,8,8,8,8,8,10,12,13,15,66,77,99 };
	vector<int> res3 = { 5, 10 };
	TESTCASE_ASSERT(sln.searchRange(arr2, 8) == res3);
}
