#include "TestCase.h"

using namespace std;

class SolutionShortestUnsortedContinuousSubarray
{
public:
	int findUnsortedSubarray(vector<int>& nums) {
		vector<int> sorted(nums);
		std::sort(sorted.begin(), sorted.end());

		bool lfound = false, rfound = false;
		int l = 0, r = (int)nums.size() - 1;
		while (l < r)
		{
			if (!lfound)
			{
				if (sorted[l] == nums[l])
					l++;
				else
					lfound = true;
			}
			if (!rfound)
			{
				if (sorted[r] == nums[r])
					r--;
				else
					rfound = true;
			}
			if (lfound && rfound) break;
		}

		if (l == r)
			return 0;
		else
			return r - l + 1;
	}
};

RUN_TESTCASE(ShortestUnsortedContinuousSubarray)
{
	SolutionShortestUnsortedContinuousSubarray sln;

	vector<int> arr1 = { 2,6,4,8,10,9,15 };
	TESTCASE_ASSERT(sln.findUnsortedSubarray(arr1) == 5);

	vector<int> arr2 = { 1,7,3 };
	TESTCASE_ASSERT(sln.findUnsortedSubarray(arr2) == 2);

	vector<int> arr3 = { 1,7,3,4 };
	TESTCASE_ASSERT(sln.findUnsortedSubarray(arr3) == 3);

	vector<int> arr4 = { 1,2,3,5,4 };
	TESTCASE_ASSERT(sln.findUnsortedSubarray(arr4) == 2);
}