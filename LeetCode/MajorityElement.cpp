#include "TestCase.h"

using namespace std;

class SolutionMajorityElement
{
public:
	int majorityElement(vector<int>& nums) {
		if (nums.empty())
			return 0;

		int count = 1;
		int candidate = nums[0];

		for (int i = 1; i < (int)nums.size(); i++)
		{
			if (count == 0)
				candidate = nums[i];
			count += (nums[i] == candidate) ? 1 : -1;
		}

		return candidate;
	}
};

RUN_TESTCASE(MajorityElement)
{
	SolutionMajorityElement sln;

	vector<int> arr1 = { -1,1,1,1,2,1 };
	TESTCASE_ASSERT(sln.majorityElement(arr1) == 1);

	vector<int> arr2 = { 7, 7, 5, 7, 5, 1, 5, 7, 5, 5, 7, 7, 7, 7, 7, 7 };
	TESTCASE_ASSERT(sln.majorityElement(arr2) == 7);

	vector<int> arr3 = { 3,2,3 };
	TESTCASE_ASSERT(sln.majorityElement(arr3) == 3);
}