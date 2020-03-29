#include "TestCase.h"

using namespace std;

class SolutionFindDupNumber
{
public:
	int findDuplicate(vector<int>& nums) {
		if (nums.empty()) return 0;
		int slow = nums[0];
		int fast = nums[nums[0]];
		while (slow != fast)
		{
			slow = nums[slow];
			fast = nums[nums[fast]];
		}
		fast = 0;
		while (slow != fast)
		{
			slow = nums[slow];
			fast = nums[fast];
		}
		return fast;
	}
};

RUN_TESTCASE(FindDupNumber)
{
	SolutionFindDupNumber sln;

	vector<int> arr1 = { 1,3,4,2,2 };
	TESTCASE_ASSERT(sln.findDuplicate(arr1) == 2);

	vector<int> arr2 = { 3,1,3,4,2 };
	TESTCASE_ASSERT(sln.findDuplicate(arr2) == 3);
}